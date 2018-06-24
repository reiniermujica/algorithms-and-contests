 {$I-,Q-,R-,S-}

{Problema 14: Fiesta Vacuna Bronce [Richard Ho, 2006]

Una vaca de cada una de N granjas (1 <= N <= 1000) convenientemente
numeradas 1..N van a ir a una gran fiesta vacuna que tendrá lugar en la
granja #X (1 <= X <= N). Un total de  M (1 <= M <= 100,000) carreteras
bidireccionales conectan pares de granjas; la carretera i requiere Ti (1
<= Ti <= 100) unidades de tiempo para recorrerse. Algunas granjas están
conectadas por dos caminos; todas las granjas están conectadas por al
menos una carretera.

Después que las vacas se reunen en la granja #X, ellas se dan cuenta que 
cada vaca se olvidó algo en su granja. Ellas deciden suspender la fiesta 
y enviar todas las vacas de regreso a sus granjas para traer lo que se 
les olvidó. Todas las vacas usan rutas optimas para ir a sus granjas y 
devolverse a la fiesta. ¿Cuál es el mínimo número de unidades de tiempo 
que la fiesta debe ser suspendida?

NOMBRE DEL PROBLEMA: bparty

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por espacios, respectivamente: N, M 
      y X.

* Líneas 2..M+1: La línea i+1 describe la carretera i con tres enteros
      separados por espacios, respectivamente: Ai, Bi, y Ti. La carretera
      descrita conecta Ai y Bi y requiere Ti unidades de tiempo para
      recorrerse.

Entrada Ejemplo (archivo bparty.in):

4 8 2
1 2 7
1 3 8
1 4 4
2 1 3
2 3 1
3 1 2
3 4 6
4 2 2

DETALLES DE LA ENTRADA:

Cuatro vacas; ocho caminos; la fiesta en la granja 2.

FORMATO DE SALIDA:

* Línea 1: Un entero: la mínima cantidad de tiempo en que la fiesta debe 
ser
      suspendida.

ARCHIVO EJEMPLO (archivo bparty.out):

6

DETALLES DE LA SALIDA:

Existen carreteras directas que conectan a la granja 2 con las otras 
granjas( a la granja 1: 7 y 3; a la granja 3: 1; a la granja 4: 2). El 
camino más largo tiene longitud 3, por lo tanto el viaje de ida y vuelta 
es de 6.

**********************************************************************


Translation by Mario Cruz

 }

const
 mx                     = 1001;

var
 fe,fs                  : text;
 n,m,p,sol              : longint;
 tab                    : array[1..mx,1..mx] of longint;
 d                      : array[0..mx] of longint;
 s                      : array[1..mx] of boolean;

procedure open;
var
 i,j,a,b                : longint;
begin
 assign(fe,'bparty.in'); reset(fe);
 assign(fs,'bparty.out'); rewrite(fs);
 readln(fe,n,m,p);
 fillchar(tab,sizeof(tab),127);
 for i:=1 to m do
  begin
   readln(fe,a,b,j);
   if tab[a,b] > j then
    begin
     tab[a,b]:=j;
     tab[b,a]:=j;
    end;
  end;
 close(fe);
end;

procedure work;
var
 i,j,x                  : longint;
begin
 fillchar(d,sizeof(d),127);
 d[p]:=0; x:=p;
 for i:=1 to n-1 do
  begin
   s[x]:=true;
   for j:=1 to n do
    if (tab[x,j] + d[x] < d[j]) then
     d[j]:=(tab[x,j] + d[x]);
   x:=0;
   for j:=1 to n do
    if (not s[j]) and (d[j] < d[x]) then
     x:=j;
  end;
 sol:=0;
 for i:=1 to n do
  if d[i] > sol then
   sol:=d[i];
end;

procedure closer;
begin
 writeln(fs,sol*2);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.