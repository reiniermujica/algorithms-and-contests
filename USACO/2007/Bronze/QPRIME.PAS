  {$I-,Q-,R-,S-}

{Problem 11: Qualified Primes [Kolstad/Ho, 2007]

Farmer John has begun branding the cows with sequential prime
numbers. Bessie has noticed this and is curious about the occurrence
of various digits in those brands.

Help Bessie determine the number of primes in the inclusive range
A..B (1 <= A <= B <= 4,000,000; B <= A + 1,000,000; one test case
has B <= A + 2,000,000 ) that contain a supplied digit D.

A prime is a positive integer with exactly two divisors (1 and
itself). The first primes are 2, 3, 5, 7, 11, 13, 17, 19, 23, and,
29.

PROBLEM NAME: qprime

INPUT FORMAT:

* Line 1: Three space-separated integers: A, B, and D

SAMPLE INPUT (file qprime.in):

10 15 3


INPUT DETAILS:

How many primes in the range 10..15 contain the digit 3?

OUTPUT FORMAT:

* Line 1: The count of primes in the range that contain the digit D.

SAMPLE OUTPUT (file qprime.out):

1

OUTPUT DETAILS:

Just 13 in this range contains a '3'.
 }

var
 fe,fs           : text;
 n,m,d,sol       : longint;
 dig             : string;
 mk              : array[1..4000000] of boolean;

procedure open;
begin
 assign(fe,'qprime.in'); reset(fe);
 assign(fs,'qprime.out'); rewrite(fs);
 readln(fe,n,m,d);
 str(d,dig);
 close(fe);
end;

function primo(x : longint) : boolean;
var
 St              : string[10];
begin
 str(x,St);
 if pos(dig,St) > 0 then
  primo:=true
 else primo:=false;
end;

procedure work;
var
 i,j,k              : longint;
begin
 sol:=0;
 for i:=2 to (m div 2) do
  mk[i*2]:=true;
 for i:=3 to m do
  begin
   if not mk[i] then
    begin
     j:=3;
     k:=j*i;
     while (k <= m) do
      begin
       mk[k]:=true;
       j:=j+2;
       k:=j*i;
      end;
    end;
  end;
  for i:=n to m do
   if not mk[i] then
    begin
     if primo(i) then
      inc(sol);
    end;
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.
