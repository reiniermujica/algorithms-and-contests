 {$I-,Q-,R-,S-}

{Problem 8: Balanced Lineup [Coaches, 2004]

For the daily milking, Farmer John's N cows (1 <= N <= 50,000)
always line up in the same order. One day Farmer John decides to
organize a game of Ultimate Frisbee with some of the cows. To keep
things simple, he will take a contiguous range of cows from the
milking lineup to play the game. However, for all the cows to have
fun they should not differ too much in height.

Farmer John has made a list of Q (1 <= Q <= 200,000) potential
groups of cows and their heights (1 <= height <= 1,000,000). For
each group, he wants your help to determine the difference in height
between the shortest and the tallest cow in the group.

PROBLEM NAME: lineup

INPUT FORMAT:

* Line 1: Two space-separated integers, N and Q.

* Lines 2..N+1: Line i+1 contains a single integer that is the height
        of cow i

* Lines N+2..N+Q+1: Two integers A and B (1 <= A <= B <= N),
        representing the range of cows from A to B inclusive.

SAMPLE INPUT (file lineup.in):

6 3
1
7
3
4
2
5
1 5
4 6
2 2


OUTPUT FORMAT:

* Lines 1..Q: Each line contains a single integer that is a response
        to a reply and indicates the difference in height between the
        tallest and shortest cow in the range.

SAMPLE OUTPUT (file lineup.out):

6
3
0
}
const
 mx                   = 50001;

var
 fe,fs                : text;
 n,m                  : longint;
 tab,nr,nl            : array[1..mx] of longint;

procedure open;
var
 i                    : longint;
begin
 assign(fe,'lineup.in'); reset(fe);
 assign(fs,'lineup.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to n do
  readln(fe,tab[i]);
end;

procedure build;
var
 i,k                  : longint;
begin
 nl[n]:=0; nr[n]:=0;
 for i:=n-1 downto 1 do   { max }
  begin
   k:=i+1;
   while tab[k] < tab[i] do
    begin
     k:=nr[k];
     if k = 0 then
      break;
    end;
   if k = 0 then
    nr[i] := 0
   else
    nr[i]:=k;
  end;
 for i:=n-1 downto 1 do   { min }
  begin
   k:=i+1;
   while tab[k] > tab[i] do
    begin
     k:=nl[k];
     if k = 0 then
      break;
    end;
   if k = 0 then
    nl[i] := 0
   else
    nl[i]:=k;
  end;
end;

procedure work;
var
 i,j,k,a,b,max,min        : longint;
begin
 build;
 for i:=1 to m do
  begin
   readln(fe,a,b);
   if a<b then
    begin
     k:=nr[a]; j:=a;
     while (k<>0) and (k <= b) do
      begin
       j:=k;
       k:=nr[k];
      end;
     max:=j;
     k:=nl[a]; j:=a;
     while (k<>0) and (k <= b) do
      begin
       j:=k;
       k:=nl[k];
      end;
     min:=j;
     writeln(fs,tab[max]-tab[min]);
    end
   else
    writeln(fs,0);
  end;
 close(fe); close(fs);
end;

begin
 open;
 work;
end.