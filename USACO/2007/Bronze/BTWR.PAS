{Problem 13: The Bale Tower [Rob Kolstad, 2007]

Always bored with cud-chewing, the cows have invented a new game.
One cow retrieves a set of N (3 <= N <= 20) hay bales from the shed
each of which is one unit high. Each bale also has some unique width
and unique breadth.

A second cow tries to choose a set of bales to make the tallest
stack of bales in which each bale can be placed only on a bale whose
own width and breadth are smaller than the width and breadth of the
bale below. Bales can not be rotated to interchange the width and
breadth.

Help the cows determine the highest achievable tower that can be
legally built form a set of bales.

PROBLEM NAME: btwr

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Each line describes a bale with two space-separated
        integers,respectively the width and breadth

SAMPLE INPUT (file btwr.in):

6
6 9
10 12
9 11
8 10
7 8
5 3


INPUT DETAILS:

Six bales of various widths and breadths

OUTPUT FORMAT:

* Line 1: The height of the tallest possible tower that can legally be
        built from the bales.

SAMPLE OUTPUT (file btwr.out):

5

OUTPUT DETAILS:

These bales can be stacked for a total height of 5:
10 12
9 11
8 10
6 9
5 3
[another stacking exists, too]
}

var
 fe,fs          : text;
 n,sol          : longint;
 tab            : array[0..21,1..2] of longint;
 res            : array[0..21] of longint;

procedure open;
var
 t              : longint;
begin
 assign(fe,'btwr.in'); reset(fe);
 assign(fs,'btwr.out'); rewrite(fs);
 readln(fe,n);
 for t:=1 to n do
  readln(fe,tab[t,1],tab[t,2]);
 close(fe);
end;

procedure qsort(ini,fin : longint);
var
 i,j,k,t                : longint;
begin
 i:=ini; j:=fin; k:=tab[(i+j) div 2,2];
 repeat
  while tab[i,2] < k do inc(i);
  while tab[j,2] > k do dec(j);
  if i<=j then
   begin
    t:=tab[i,2]; tab[i,2]:=tab[j,2]; tab[j,2]:=t;
    t:=tab[i,1]; tab[i,1]:=tab[j,1]; tab[j,1]:=t;
    inc(i); dec(j);
   end;
 until i>j;
 if i < fin then qsort(i,fin);
 if j > ini then qsort(ini,j);
end;

procedure work;
var
 i,j            : longint;
begin
 sol:=0;
 for i:=n downto 1 do
  begin
   for j:=i+1 to n do
    if (tab[i,1] < tab[j,1]) and (res[j] > res[i]) then
     res[i]:=res[j];
    inc(res[i]);
    if res[i] > sol then
     sol:=res[i];
  end;
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 qsort(1,n);
 work;
 closer;
end.
