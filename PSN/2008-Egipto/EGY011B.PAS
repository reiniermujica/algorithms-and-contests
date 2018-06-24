 {$I-,Q-,R-,S-}

{
 VC6
 Reinier C‚sar Mujica Hern ndez
 11 Grado
 IPVCE "Ernesto Guevara"
}

const
 mx                   = 301;
 mov                  : array[1..4,1..2] of shortint
  =((1,0),(0,1),(-1,0),(0,-1));

var
 fe,fs                : text;
 n,m,sol,p,cont       : longint;
 posi                 : array[1..4] of longint;
 tab,ns               : array[1..mx,1..mx] of longint;
 co                   : array[1..mx*mx,1..2] of longint;
 cam                  : array[1..mx,1..mx,1..2] of longint;
 sav                  : array[boolean,1..mx*mx,1..2] of longint;
 mk                   : array[1..mx,1..mx] of boolean;

procedure open;
var
 i,a,b                : longint;
begin
 assign(fe,'sensor.in'); reset(fe);
 assign(fs,'sensor.out'); rewrite(fs);
 readln(fe,n,m);
 readln(fe,posi[1],posi[2],posi[3],posi[4]);
 readln(fe,p);
 fillchar(tab,sizeof(tab),127);
 for i:=1 to p do
  begin
   readln(fe,a,b);
   tab[a,b]:=-1;
  end;
 close(fe);
end;

procedure work;
var
 cp,ch,h1,h2,i,j      : longint;
 ok                   : boolean;
 z                    : array[1..2] of longint;
 s                    : boolean;
begin
 s:=true; cp:=1; ch:=0;
 sav[s,1,1]:=posi[1]; sav[s,1,2]:=posi[2];
 tab[posi[1],posi[2]]:=0;
 fillchar(ns,sizeof(ns),127);
 ns[posi[1],posi[2]]:=0;
 while cp > 0 do
  begin
   fillchar(mk,sizeof(mk),false);
   for i:=1 to cp do
    begin
     h1:=sav[s,i,1]; h2:=sav[s,i,2];
     for j:=1 to 4 do
      begin
       z[1]:=h1 + mov[j,1]; z[2]:=h2 + mov[j,2]; ok:=false;
       if (z[1] > 0) and (z[1] <= n) and (z[2] > 0) and (z[2] <= m)
        and (tab[z[1],z[2]] <> -1) then
        begin
         if (j=1) or (j=3) then
          begin
           if (ns[z[1],z[2]] > ns[h1,h2] + 1) then
            begin
             ns[z[1],z[2]]:=ns[h1,h2] + 1;
             cam[z[1],z[2],1]:=h1;
             cam[z[1],z[2],2]:=h2;
             tab[z[1],z[2]]:=tab[h1,h2] + 1;
             ok:=true;
            end
            else
           if (ns[z[1],z[2]] = ns[h1,h2] + 1) then
            begin
             if (tab[z[1],z[2]] > tab[h1,h2] + 1) then
              begin
               tab[z[1],z[2]]:=tab[h1,h2] + 1;
               cam[z[1],z[2],1]:=h1;
               cam[z[1],z[2],2]:=h2;
               ok:=true;
              end;
            end;
          end
          else
         if (ns[z[1],z[2]] > ns[h1,h2]) then
          begin
           ns[z[1],z[2]]:=ns[h1,h2];
           tab[z[1],z[2]]:=tab[h1,h2] + 1;
           cam[z[1],z[2],1]:=h1;
           cam[z[1],z[2],2]:=h2;
           ok:=true;
          end
          else
         if (ns[z[1],z[2]] = ns[h1,h2]) then
          begin
           if (tab[z[1],z[2]] > tab[h1,h2] + 1) then
            begin
             tab[z[1],z[2]]:=tab[h1,h2] + 1;
             cam[z[1],z[2],1]:=h1;
             cam[z[1],z[2],2]:=h2;
             ok:=true;
            end;
          end;
         if (not mk[z[1],z[2]]) and (ok) then
          begin
           mk[z[1],z[2]]:=true;
           inc(ch);
           sav[not s,ch,1]:=z[1];
           sav[not s,ch,2]:=z[2];
          end;
        end;
      end;
    end;
   s:=not s;
   cp:=ch;
   ch:=0;
  end;
 sol:=tab[posi[3],posi[4]];
 cont:=ns[posi[3],posi[4]];
end;

procedure closer;
var
 i,j,k,l,t            : longint;
begin
 writeln(fs,sol);
 writeln(fs,cont);
 k:=1;
 co[k,1]:=posi[3]; co[k,2]:=posi[4];
 l:=cam[posi[3],posi[4],1];
 t:=cam[posi[3],posi[4],2];
 while (l <> posi[1]) or (t <> posi[2]) do
  begin
   inc(k);
   co[k,1]:=l; co[k,2]:=t;
   j:=l;
   l:=cam[l,t,1]; t:=cam[j,t,2];
  end;
 for i:=k downto 1 do
  begin
   writeln(fs,co[i,1],' ',co[i,2]);
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.