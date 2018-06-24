{Problem 12: Making Change [Traditional, 2007]

Poor Bessie has taken a job in the convenience store located just
over the border in Slobbovia. Slobbovians use different coinages
than the USA; their coin values change day-by-day!

Help Bessie make optimal change for Slobbovian shoppers. You will
need to create C (1 <= C <= 1000) cents of change using N (1 <= N
<= 10) coins of various values. All test cases will be solvable
using the supplied coins.

If 5 coins of values 50, 25, 10, 5, and 1 were available, Bessie
would make optimum change (minimal coins) of 93 cents by using 1 x
50, 1 x 25, 1 x 10, 1 x 5, and 3 x 1 coins (a total of 7 coins).

How hard could it be? The final two test cases will be challenging.

PROBLEM NAME: change

INPUT FORMAT:

* Line 1: Two space-separate integers: C and N

* Lines 2..N+1: Each line contains a single unique integer that is a
        coin value that can be used to create change

SAMPLE INPUT (file change.in):

93 5
25
50
10
1
5


OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of coins to
        create C cents

SAMPLE OUTPUT (file change.out):

7
 }

var
 fe,fs             : text;
 n,m,sol,max       : longint;
 tab,siz,sav,temp  : array[1..10] of longint;

procedure open;
var
 i              : longint;
begin
 assign(fe,'change.in'); reset(fe);
 assign(fs,'change.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to m do
  readln(fe,tab[i]);
 close(fe);
end;

procedure qsort(ini,fin : longint);
var
 i,j,k,t                : longint;
begin
 i:=ini; j:=fin; k:=tab[random(j-i+1)+i];
 repeat
  while tab[i] < k do inc(i);
  while tab[j] > k do dec(j);
  if i<=j then
   begin
    t:=tab[i]; tab[i]:=tab[j]; tab[j]:=t;
    inc(i); dec(j);
   end;
 until i>j;
 if i < fin then qsort(i,fin);
 if j > ini then qsort(ini,j);
end;

procedure work;
var
 i,j,k,t        : longint;
begin
 randomize;
 qsort(1,m);
 for i:=1 to m do
  begin
   while (tab[i] * sav[i]) < n do inc(sav[i]);
   if (tab[i]*sav[i]) > n then
     dec(sav[i]);
  end;
 max:=maxlongint; k:=0; t:=m;
 repeat
  begin
  inc(k); sol:=0;
  fillchar(siz,sizeof(siz),0);
  fillchar(temp,sizeof(temp),0);
  for i:=m downto 1 do
   begin
    while (tab[i]*temp[i]+siz[i+1] < n) and (temp[i] < sav[i]) do
     inc(temp[i]);
    if (tab[i]*temp[i]+siz[i+1]) > n then
     dec(temp[i]);
    siz[i]:=siz[i+1]+temp[i]*tab[i];
    sol:=sol + temp[i];
   end;
    if siz[1] <> n then
     sol:=maxlongint;
    end;
 if sol<max then max:=sol;
 dec(sav[t]);
 if sav[t]<=0 then
  dec(t);
 until (k=n);
end;

procedure closer;
begin
 writeln(fs,max);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.