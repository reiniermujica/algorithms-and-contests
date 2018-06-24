  {$I-,Q-,R-,S-}

{Problem 6: Bad Hair Day [Brian Dean, 2006]

Some of Farmer John's N cows (1 <= N <= 80,000) are having a bad
hair day! Since each cow is self-conscious about her messy hairstyle,
FJ wants to count the number of other cows that can see the top of
other cows' heads.

Each cow i has a specified height h[i] (1 <= h[i] <= 1,000,000,000)
and is standing in a line of cows all facing east (to the right in
our diagrams). Therefore, cow i can see the tops of the heads of
cows in front of her (namely cows i+1, i+2, and so on), for as long
as these cows are strictly shorter than cow i.

Consider this example:

        =
=       =
=   -   =           Cows facing right -->
=   =   =
= - = = =
= = = = = =
1 2 3 4 5 6

Cow#1 can see the hairstyle of cows #2, 3, 4
Cow#2 can see no cow's hairstyle
Cow#3 can see the hairstyle of cow #4
Cow#4 can see no cow's hairstyle
Cow#5 can see the hairstyle of cow 6
Cow#6 can see no cows at all!

Let c[i] denote the number of cows whose hairstyle is visible from
cow i; please compute the sum of c[1] through c[N]. For this example,
the desired is answer 3 + 0 + 1 + 0 + 1 + 0 = 5.

TIME LIMIT: 0.5 seconds

PROBLEM NAME: badhair

INPUT FORMAT:

* Line 1: The number of cows, N.

* Lines 2..N+1: Line i+1 contains a single integer that is the height
        of cow i.

SAMPLE INPUT (file badhair.in):

6
10
3
7
4
12
2


INPUT DETAILS:

Six cows stand in a line; heights are 10, 3, 7, 4, 12, 2.

OUTPUT FORMAT:

* Line 1: A single integer that is the sum of c[1] through c[N].

SAMPLE OUTPUT (file badhair.out):

5
 }

const
 mx            = 80001;

var
 fe,fs         : text;
 sol           : int64;
 n             : longint;
 tab,last      : array[1..mx] of longint;
 cont          : array[1..mx] of int64;

procedure open;
var
 i             : longint;
begin
 assign(fe,'badhair.in'); reset(fe);
 assign(fs,'badhair.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  readln(fe,tab[i]);
 close(fe);
end;

procedure work;
var
 i,j           : longint;
begin
 sol:=0; tab[n+1]:=maxlongint; last[n]:=n+1;
 for i:=n-1 downto 1 do
  begin
    j:=i+1;
    cont[i]:=0;
    last[i]:=j;
    while (tab[j] < tab[i]) do
     begin
      cont[i]:=cont[i] + cont[j] + 1;
      last[i]:=last[j];
      j:=last[j];
     end;
  end;
 for i:=1 to n do sol:=sol + cont[i];
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