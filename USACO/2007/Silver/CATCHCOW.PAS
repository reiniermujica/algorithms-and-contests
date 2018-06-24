 {$I-,Q-,R-,S-}

{104¦ Catch That Cow.                                      Croacia 2007
----------------------------------------------------------------------

Farmer John has been  informed of the location  of a fugitive cow  and
wants to  catch her  immediately. He  starts at  a point  N (0 <= N <=
100,000) on  a number  line and  the cow  is at  a point  K (0 <= K <=
100,000)  on  the same  number  line. Farmer  John  has two  modes  of
transportation: walking and teleporting.

    * Walking: FJ can move from any point X to the points X-1 or
      X+1 in a single minute

    * Teleporting: FJ can move from any point X to the point 2*X
      in a single minute.

If the cow,  unaware of its  pursuit, does not  move at all,  how long
does it take for Farmer John to retrieve it?

PROBLEM NAME: catchcow

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

SAMPLE INPUT (file catchcow.in):

5 17

INPUT DETAILS:

Farmer John starts at point 5 and the fugitive cow is at point 17.

OUTPUT FORMAT:

* Line 1: The  least amount of time,  in minutes, it takes  for Farmer
John to catch the fugitive cow.

SAMPLE OUTPUT (file catchcow.out):

4

OUTPUT DETAILS:

The fastest way for Farmer John  to reach the fugitive cow is  to move
along the following path: 5-10-9-18-17, which takes 4 minutes.
 }
const
 max        = 100001;

var
 fe,fs      : text;
 n,m,ch,cp  : longint;
 sav        : array[boolean,1..max] of longint;
 tab        : array[0..max] of longint;

procedure open;
begin
 assign(fe,'catchcow.in'); reset(fe);
 assign(fs,'catchcow.out'); rewrite(fs);
 readln(fe,n,m);
 close(fe);
end;

procedure closer(x : longint);
begin
 writeln(fs,x);
 close(fs);
 halt;
end;

function updatex(x,cant : longint) : boolean;
begin
 if tab[x] > cant then
  begin
   tab[x]:=cant;
   updatex:=true;
  end
 else
  updatex:=false;
end;

procedure work;
var
 i,j,k,h1   : longint;
 s          : boolean;
begin
 s:=true; cp:=1; ch:=0;
 fillchar(tab,sizeof(tab),127);
 sav[s,1]:=n; tab[n]:=0;
 while cp > 0 do
  begin
   for i:=1 to cp do
    begin
     h1:=sav[s,i];
     if (h1-1 >= 0) and (updatex(h1-1,tab[h1]+1)) then
      begin
       inc(ch);
       sav[not s,ch]:=h1-1;
       if h1-1 = m then closer(tab[h1]+1);
      end;
     if (h1+1 <= max) and (updatex(h1+1,tab[h1]+1)) then
      begin
       inc(ch);
       sav[not s,ch]:=h1+1;
       if h1+1 = m then closer(tab[h1]+1);
      end;
     if (h1*2 <= max) and (updatex(h1*2,tab[h1]+1)) then
      begin
       inc(ch);
       sav[not s,ch]:=h1*2;
       if h1*2 = m then closer(tab[h1]+1);
      end;
    end;
   cp:=ch;
   ch:=0;
   s:=not s;
  end;
end;

begin
 open;
 if n=m then closer(0);
 work;
end.
