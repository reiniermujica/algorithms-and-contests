{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{85ş Vendr  la muerte y tendr  tus ojos.                   Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La muerte viene tr s de m¡; y yo, ser vivo al fin, no quiero morir.

La muerte es bromista en extremo y lleva millones de a¤os matando
gente todos los d¡as, por lo tanto para entretenerse utiliza una forma
de matar muy particular. La muerte dispone de un castillo con N
habitaciones (numeradas de 1 a N, dos habitaciones diferentes tienen
n£meros diferentes). La muerte me lleva al castillo y me permite
esconderme en una habitaci¢n. Posteriormente escoge un P n£meros y
revisa todas las habitaciones que est‚n numeradas con un n£mero
divisible entre alguno de los P n£meros escogidos. Si la muerte revisa
la habitaci¢n en que estoy entonces paso a mejor vida.

Tarea

Dado el valor de N, y P n£meros: decir cu ntas habitaciones existen en
las que me puedo esconder y sobrevivir.

Entrada

El fichero de entrada se llamar  DEATH.IN; en la primera l¡nea tendr 
los valores de N (1 <= N <= 4000000) y P (1 <= P <= 8); en la segunda
l¡nea aparecer n los P n£meros seleccionados por la muerte (estos
n£meros son enteros positivos menores que N).

Salida

El fichero de salida se llamar  DEATH.OUT, y consistir  de una £nica
l¡nea con un £nico entero representando la cantidad de habitaciones en
las que puedo sobrevivir.

 ÚÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ DEATH.IN ³   ³ DEATH.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´         Puedo esconderme en las
 ³ 10 2     ³   ³ 3         ³         habitaciones 1, 5, y 7.
 ³ 2 3      ³   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
 ÀÄÄÄÄÄÄÄÄÄÄÙ
}

var
 fe,fs              : text;
 n,m,sol            : longint;
 i                  : byte;
 tab                : array[1..8] of longint;

procedure open;
begin
 assign(fe,'death.in'); reset(fe);
 assign(fs,'death.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to m do read(fe,tab[i]);
 close(fe);
end;

function mcd(n1,n2 : longint) : longint;
begin
 if n2 = 0 then
  mcd:=n1
 else
  mcd:=mcd(n2,n1 mod n2);
end;

function mcm(n1,n2 : longint) : longint;
begin
 if n1=n2 then
  mcm:=n1
 else
  mcm:=(n1*n2) div mcd(n1,n2);
end;

procedure comb(posi : byte; act : longint; ok : boolean);
var
 cm,cd              : longint;
 i                  : byte;
begin
 cm:=mcm(act,tab[posi]);
 cd:=n div cm;
 if ok then
  sol:=sol - cd
 else
  sol:=sol + cd;
 if posi < m then
  for i:=posi+1 to m do
   comb(i,cm,not ok);
end;

procedure work;
begin
 sol:=n;
 for i:=1 to m do
  comb(i,1,true);
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