 {$I-,Q-,R-,S-}

{� Sin Heno.                                             Polonia 2005
----------------------------------------------------------------------

Las vacas se  han quedado sin  heno, un suceso  horrible que debe  ser
remediado inmediatamente. Bessie quiere  recorrer algunas de las  N (2
<=  N <=  2,000) otras  granjas (numeradas  1..N) para  investigar su
situaci�n de heno. Ella  recorrer� algunos de todos  los M (1 <=  M <=
10,000) caminos  de doble  v�a cuya  longitud no  excede 1,000,000,000
que  conectan las  granjas. Algunas  granjas pueden  estar conectadas
m�ltiplemente con caminos de diferentes longitudes.

Bessie est� tratando de decidir  el tama�o de la cantimplora  que ella
necesitar�. Ella sabe que necesita una onza de agua por cada unidad de
distancia de un camino. Dado que  ella puede obtener m�s agua en  cada
granja, ella �nicamente est� preocupada por la longitud del camino m�s
largo. Por supuesto, ella planea  su ruta entre granjas de  tal manera
que ella minimice la cantidad de agua que ella debe cargar.

Ayude a que Bessie sepa la cantidad m�s grande de agua que ella tendr�
que cargar: �cu�l es la longitud del camino m�s largo que ella  tendr�
que  recorrer entre  cualesquiera dos  granjas, presumiendo  que  ella
elija rutas que minimicen ese n�mero?

NOMBRE DEL PROBLEMA: outofhay

FORMATO DE ENTRADA:

- L�nea 1: Dos enteros separados por espacio, N y M.

- L�neas  2..1+M: La  l�nea i+1  contiene tres  enteros separados  por
  espacios, A_i,  B_i, y  L_i, describiendo  un camino  de A_i  a  B_i
  de longitud L_i.

ENTRADA EJEMPLO (archivo outofhay.in):

3 3
1 2 23
2 3 1000
1 3 43


FORMATO DE SALIDA:

- L�nea 1: Un solo entero que es la longitud del camino m�s largo que
  necesita ser recorrido.

SALIDA EJEMPLO (archivo outofhay.out):

43

DETALLES DE LA SALIDA:

Con el prop�sito de llegar a  la granja 2, Bessie viaja por  un camino
de longitud 23. Para llegar a la granja 3, Bessie viaja por un  camino
de longitud 43. Con una capacidad de 43, ella puede viajar a lo  largo
de estos  caminos dado  que ella  recarga su  cantimplora a  capacidad
m�xima antes de comenzar un nuevo camino.

 }

const
 arist          = 10001;
 nodes          = 2001;

var
 fe,fs          : text;
 n,m,sol,act    : longint;
 tab            : array[1..arist,1..3] of longint;
 comp           : array[1..nodes] of longint;

procedure open;
var
 i              : longint;
begin
 assign(fe,'outofhay.in'); reset(fe);
 assign(fs,'outofhay.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to m do
  readln(fe,tab[i,1],tab[i,2],tab[i,3]);
 close(fe);
end;

procedure swap(var n1,n2 : longint);
var
 t                       : longint;
begin
 t:=n1; n1:=n2; n2:=t;
end;

procedure qsort(ini,fin : longint);
var
 i,j,k                  : longint;
begin
 i:=ini; j:=fin; k:=tab[random(fin-ini)+i+1,3];
 repeat
  while (tab[i,3] < k) do inc(i);
  while (tab[j,3] > k) do dec(j);
  if i<=j then
   begin
    swap(tab[i,1],tab[j,1]);
    swap(tab[i,2],tab[j,2]);
    swap(tab[i,3],tab[j,3]);
    inc(i); dec(j);
   end;
 until i>j;
 if i<fin then qsort(i,fin);
 if j>ini then qsort(ini,j);
end;

procedure work;
var
 i,j,h1,h2,h3        : longint;
begin
 sol:=0; act:=0;
 randomize;
 qsort(1,m);
 for i:=1 to m do
  begin
   h1:=tab[i,1]; h2:=tab[i,2]; h3:=tab[i,3];
   if (comp[h1] = 0) and (comp[h2] = 0) then
    begin
     inc(act);
     comp[h1]:=act;
     comp[h2]:=act;
     if (h3 > sol) then
      sol:=h3;
    end
    else
   if (comp[h1] * comp[h2] = 0) then
    begin
     if (comp[h1] = 0) then
      comp[h1]:=comp[h2]
     else
      comp[h2]:=comp[h1];
     if (h3 > sol) then
      sol:=h3;
    end
    else
   if (comp[h1] <> comp[h2]) then
    begin
     h1:=comp[h1]; h2:=comp[h2];
     for j:=1 to n do
      if (comp[j] = h1) then
       comp[j]:=h2;
     if (h3 > sol) then
      sol:=h3;
    end;
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