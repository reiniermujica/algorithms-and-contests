  {$I-,Q-,R-,S-}

{Broken Necklace
You have a necklace of N red, white, or blue beads (3<=N<=350) some of which
are red, others blue, and others white, arranged at random. Here are two
examples for n=29:

                1 2                               1 2
            r b b r                           b r r b
          r         b                       b         b
         r           r                     b           r
        r             r                   w             r
       b               r                 w               w
      b                 b               r                 r
      b                 b               b                 b
      b                 b               r                 b
       r               r                 b               r
        b             r                   r             r
         b           r                     r           r
           r       r                         r       b
             r b r                             r r w
            Figure A                         Figure B
                        r red bead
                        b blue bead
                        w white bead

The beads considered first and second in the text that follows have been
marked in the picture.

The configuration in Figure A may be represented as a string of b's and r's,
where b represents a blue bead and r represents a red one, as follows:
brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight,
and then collect beads of the same color from one end until you reach a bead
of a different color, and do the same for the other end (which might not be
of the same color as the beads collected before this).

Determine the point where the necklace should be broken so that the most
number of beads can be collected.

Example
For example, for the necklace in Figure A, 8 beads can be collected, with the
breaking point either between bead 9 and bead 10 or else between bead 24 and
bead 25.

In some necklaces, white beads had been included as shown in Figure B above.
When collecting beads, a white bead that is encountered may be treated as
either red or blue and then painted with the desired color. The string that
represents this configuration will include the three symbols r, b and w.

Write a program to determine the largest number of beads that can be
collected from a supplied necklace.

PROGRAM NAME: beads


INPUT FORMAT

Line 1:  N, the number of beads
Line 2:  a string of N characters, each of which is r, b, or w


SAMPLE INPUT (file beads.in)

29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb


OUTPUT FORMAT

A single line containing the maximum of number of beads that can be collected
from the supplied necklace.


SAMPLE OUTPUT (file beads.out)

11

OUTPUT EXPLANATION

Consider two copies of the beads (kind of like being able to runaround the
ends). The string of 11 is marked.
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
                        ***** ******

}

const
 max            = 1056;

var
 fe,fs          : text;
 n,cont,sol     : longint;
 tab            : array[0..max] of char;

procedure open;
var
 i              : longint;
begin
 assign(fe,'beads.in'); reset(fe);
 assign(fs,'beads.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   read(fe,tab[i]);
   tab[i+n]:=tab[i];
   tab[i+n*2]:=tab[i];
  end;
 close(fe);
end;

function cut(x,y : longint; ch : char) : longint;
var
 i               : longint;
begin
 i:=x + y;
 while ((tab[i] = 'w') or (tab[i] = ch)) and (cont < n) do
  begin
   i:=i + y;
   cont:=cont + 1;
  end;
 cut:=i;
end;

procedure work;
var
 i,x             : longint;
begin
 sol:=0;
 for i:=n to n*2+1 do
  begin
   cont:=1; x:=i;
   if tab[i] = 'w' then
    begin
     x:=cut(i,-1,'w');
     cont:=cont + 1;
    end;
   cut(x,-1,tab[x]);
   cont:=cont + 1; x:=i+1;
   if tab[x] = 'w' then
    begin
     x:=cut(x,1,'w');
     cont:=cont + 1;
    end;
   cut(x,1,tab[x]);
   if (cont > sol) then
    sol:=cont;
  end;
 if sol > n then sol:=n;
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