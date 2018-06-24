{
ID: reywork2
PROG: transform
LANG: PASCAL
}

const
 mx               = 11;

var
 fe,fs            : text;
 n,sol            : longint;
 tab,inv,tmp,cad  : array[1..mx,1..mx] of char;

procedure open;
var
 i,j              : longint;
begin
 assign(fe,'transform.in'); reset(fe);
 assign(fs,'transform.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    read(fe,tab[i,j]);
   readln(fe);
  end;
 for i:=1 to n do
  begin
   for j:=1 to n do
    read(fe,inv[i,j]);
   readln(fe);
  end;
 close(fe);
end;

function comp : boolean;
var
 i,j          : longint;
begin
 for i:=1 to n do
  for j:=1 to n do
   if inv[i,j] <> tmp[i,j] then
    begin
     comp:=false;
     exit;
    end;
 comp:=true;
end;

procedure rota90;
var
 i,j,x,y,k,l  : longint;
begin
 k:=1; l:=n;
 for i:=1 to n do
  begin
   dec(k); dec(l);
   x:=k; y:=l;
   for j:=1 to n do
    begin
     tmp[i+x,j+y]:=cad[i,j];
     inc(x); dec(y);
    end;
  end;
end;

procedure refle;
var
 i,j          : longint;
begin
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     tmp[i,n-j+1]:=tab[i,j];
    end;
  end;
end;

procedure closer(x : longint);
begin
 writeln(fs,x);
 close(fs);
 halt;
end;

procedure work;
var
 i              : longint;
begin
 if comp then
  closer(6);
 cad:=tab;
 for i:=1 to 3 do
  begin
   rota90;
   if comp then
    closer(i);
   cad:=tmp;
  end;
 refle;
 if comp then
  closer(4);
 cad:=tmp;
 for i:=1 to 3 do
  begin
   rota90;
   if comp then
    closer(5);
   cad:=tmp;
  end;
end;

begin
 open;
 work;
 closer(7);
end.