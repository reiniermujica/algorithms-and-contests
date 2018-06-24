{
PROG: cheart
LANG: PASCAl
}

 {$I-,Q-,R-,S-}


const
 mx                     = 100001;

var
 fe,fs                  : text;
 n,m,p,act,s            : longint;
 mk,sol                 : array[1..mx] of boolean;

procedure open;
begin
 assign(fe,'cheat.in'); reset(fe);
 assign(fs,'cheat.out'); rewrite(fs);
 readln(fe,n,m,p);
 close(fe);
end;

procedure work;
var
 i,j,k,cont               : longint;
begin
 act:=2; cont:=m-1; k:=p+2; s:=0;
 fillchar(mk,sizeof(mk),true);
 mk[1]:=false;
 while cont > 0 do
  begin
   dec(cont);
   j:=0;
   if act = n then
    begin
     sol[k]:=true;
     act:=1;
     mk[k]:=false;
    end
   else
    begin
     mk[k] := false;
     inc(act);
    end;
   if cont > 0 then
   while j <= p do
    begin
     if k + 1 > m then
      k:=1
     else
      k:=k + 1;
     while not mk[k] do
      begin
       if k + 1 > m then
        k:=1
       else
        k:=k + 1;
      end;
     inc(j);
    end;
  end;
end;

procedure closer;
var
 i                      : longint;
begin
 for i:=1 to m do
  if sol[i] then
  writeln(fs,i);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.