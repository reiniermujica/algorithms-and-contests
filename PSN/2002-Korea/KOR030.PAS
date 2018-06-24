 {$I-,Q-,R-,S-}

{30ş El nuevo juguete de Melany                              Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Melany  es una ni¤a inteligente y traviesa. Sus padres le han comprado
un  nuevo  juguete  que consiste en un puzzle de N piezas. Se sabe que
una  pieza encaja con al menos otra pieza del mismo puzzle, y que unir
estas dos piezas le lleva a Melany algun M tiempo.

Tarea:

Confeccione  un  programa  para  dada  la cantidad de piezas del nuevo
juguete, las piezasa que pueden unirse y el tiempo M que demora Melany
en  unirlas,  determine el menor tiempo en que ella armara su puzzle y
la configuracion del mismo.

Entrada:

La  entrada  es  mediante  el  fichero  texto MELY.IN con la siguiente
estructura:

.  Primera  linea: dos numeros enteros N y K, el primero representa la
  cantidad  de  piezas que tiene el puzzle y el segundo la cantidad de
  parejas de piezas que pueden unirse (4 <= N <= 100).
.  2..K+1 linea: tres enteros A, B y M donde A y B representan numeros
  de  dos  piezas que pueden unirse y M el tiempo que demora Melany en
  unirlas (0 <= M <= 255).

Salida:

La salida se realizara hacia el fichero texto MELY.OUT:

.  Primera  linea: un entero que significa el tiempo que demora Melany
  en armar su puzzle.
. A partir de la segunda linea la configuracion del puzzle, la primera
  pieza  y  a  continuacion todas las que Melany une a esta, separados
  por un espacio en blanco.

ÚÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄ¿
³MELY.IN³  ³MELY.OUT³
ÃÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄ´
³6 10   ³  ³16      ³
³1 2 7  ³  ³1 2 3 4 ³
³1 6 6  ³  ³3 6 5   ³
³4 1 2  ³  ÀÄÄÄÄÄÄÄÄÙ
³2 4 8  ³
³3 1 2  ³
³5 4 7  ³
³3 4 3  ³
³5 3 4  ³
³6 3 1  ³
³6 5 5  ³
ÀÄÄÄÄÄÄÄÙ
 }

const
 mx                 = 101;
 maxlong            = 2139062143;

var
 fe,fs              : text;
 n,m,sol            : longint;
 tab                : array[1..mx,1..mx] of longint;
 mk                 : array[1..mx] of boolean;
 sav                : array[1..mx] of longint;
 link               : array[1..mx,1..mx] of boolean;

procedure open;
var
 i,a,b,c            : longint;
begin
 assign(fe,'mely.in'); reset(fe);
 assign(fs,'mely.out'); rewrite(fs);
 readln(fe,n,m);
 fillchar(tab,sizeof(tab),127);
 for i:=1 to m do
  begin
   readln(fe,a,b,c);
   tab[a,b]:=c;
   tab[b,a]:=c;
  end;
 close(fe);
end;

procedure work;
var
 i,j,k,max,act,piv  : longint;
begin
 sav[1]:=1; mk[1]:=true; sol:=0;
 for i:=2 to n do
  begin
   max:=maxlong;
   for j:=1 to i-1 do
    begin
     for k:=1 to n do
      if (not mk[k]) and (tab[sav[j],k] < max) then
       begin
        max:=tab[sav[j],k];
        piv:=k;
        act:=sav[j];
       end;
    end;
   sav[i]:=piv;
   mk[piv]:=true;
   link[act,piv]:=true;
   sol:=sol + tab[act,piv];
  end;
end;

procedure closer;
var
 i,j               : longint;
 ok                : boolean;
begin
 writeln(fs,sol);
 for i:=1 to n do
  begin
   ok:=false;
   for j:=1 to n do
    if link[i,j] then
     begin
      if not ok then
       begin
        ok:=true;
        write(fs,i,' ',j,' ');
        link[i,j]:=false;
       end
      else
       begin
        write(fs,j,' ');
        link[i,j]:=false;
       end;
     end;
   if ok then
    writeln(fs);
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.