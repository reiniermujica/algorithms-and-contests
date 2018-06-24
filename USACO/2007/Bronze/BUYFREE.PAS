  {$I-,Q-,R-,S-}

{Problema 13: Compre Uno Obtenga Uno Gratis [Jeffrey Wang, 2007]

El Granjero Juan ha descubierto que el Internet está comprando fardos de
heno en línea cuando él ha descubierto una oferta especial. ¡Por cada
fardo de heno de tamaño A (1 <= A <= 1,000,000) que el compre, él puede
obtener un fardo de heno de tamaño B (1 <= B < A) gratis!

La oferta, sin embargo, tiene sus restricciones: el fardo más grande debe
ser de alta calidad y el más chico debe ser de baja calidad. GJ, siempre
un tipo frugal y económico, no se preocupa: cualquier calidad de heno le
sirve en tanto él ahorre algún dinero.

Dada una lista de los tamaños de N (1 <=  N <= 10,000) fardos de alta
calidad y M(1 <= M <= 10,000) fardos de baja calidad, encuentre el número
máximo de fardos que el Granjero Juan puede comprar. El puede comprar
fardos de alta calidad sin obtener los fardos gratis de baja calidad,
pero él no puede comparar fardos de baja calidad (esto es, él debe
obtenerlos gratis en la oferta).

NOMBRE DEL PROBLEMA: buyfree

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio: N y M

* Líneas 2..N+1: La línea i+1 contiene un solo entero el cual es el
      tamaño del i-ésimo fardo de alta calidad.

* Líneas 2..N+M+1: La línea i+N+1 contiene un solo entero el cual es el
      tamaño del i-ésimo fardo de baja calidad.

Entrada Ejemplo (archivo buyfree.in):

3 4
6
1
3
1
5
3
4

DETALLES DE LA ENTRADA:

Hay 3 fardos de calidad alta, con tamaños 6, 1, y 3, y 4 fardos de baja
calidad, con tamaños 1, 5, 3, y 4.

FORMATO DE SALIDA:

* Línea 1: El número total máximo de fardos que el Granjero Juan puede
      obtener.

ARCHIVO EJEMPLO (archivo buyfree.out):

5

DETALLES DE LA SALIDA:

Obviamente, el Granjero Juan puede comprar todos los fardos de alta
calidad. Cuando él compra el fardo de alta calidad de tamaño 6, él puede
obtener cualquier fardo de baja calidad gratis (por decir, el fardo de
tamaño 3). Cuando él compra el fardo de alta calidad de tamaño 3, él
puede obtener el fardo de tamaño 1 de baja calidad. Cuando él compra el
fardo de alta calidad de tamaño 1, sin embargo, él no puede obtener
gratis ningún fardo de baja calidad (desde que el tamaño debe ser
estrictamente menor). El total, no importando cuan inteligente es GJ,
viene a ser 5 fardos.
 }

type
 max            = array[1..10000] of longint;

var
 fe,fs          : text;
 n,m,sol        : longint;
 tab            : array[1..2] of ^max;
 be             : array[1..64000] of byte;

procedure open;
var
 i              : longint;
begin
 assign(fe,'buyfree.in'); reset(fe);
 assign(fs,'buyfree.out'); rewrite(fs);
 settextbuf(fe,be);
 readln(fe,n,m);
 new(tab[1]); fillchar(tab[1]^,sizeof(tab[1]^),0);
 new(tab[2]); fillchar(tab[2]^,sizeof(tab[2]^),0);
 for i:=1 to n do
  readln(fe,tab[1]^[i]);
 for i:=1 to m do
  readln(fe,tab[2]^[i]);
 close(fe);
end;

procedure qsort(ini,fin : longint; p : byte);
var
 i,j,k,t                : longint;
begin
 i:=ini; j:=fin; k:=tab[p]^[random(j-i+1)+i];
 repeat
  while tab[p]^[i] < k do inc(i);
  while tab[p]^[j] > k do dec(j);
  if i<=j then
   begin
    t:=tab[p]^[i]; tab[p]^[i]:=tab[p]^[j]; tab[p]^[j]:=t;
    inc(i); dec(j);
   end;
 until i>j;
 if i < fin then qsort(i,fin,p);
 if j > ini then qsort(ini,j,p);
end;

procedure work;
var
 i,j              : longint;
begin
 randomize;
 qsort(1,n,1);
 qsort(1,m,2);
 sol:=n;
 j:=1;
 for i:=1 to m do
  begin
   while (j <= n) and (tab[2]^[i] >= tab[1]^[j]) do
    inc(j);
   if j<=n then
    begin
     inc(sol);
     inc(j);
    end;
  end;
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 release(heaporg);
 open;
 work;
 closer;
end.