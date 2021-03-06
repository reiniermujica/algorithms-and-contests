 {$I-,Q-,R-,S-}

{Tres granjeros se levantan a las 5am cada am�ana y se dirigen al establo para
orde�ar trs vacas. El primer granjero comienza a orde�ar su vaca en el tiempo
300 (medido en segundos despu�s de las 5am) y termina en el tiempo 1000. El
segundo granjero comienza en le tiempo 700 y termina en el tiempo 1200. El
tercer granjero ocmienza en el teimpo 1500 y termina en el tiempo 2100. La
mayor cantidad de tiempo continuo durante al menos un granjero estuvo
orde�ando una vaca fu� 900 segundos (de 300 a 1200). La cantidad mayor de
teimpo en el cual no se estuvo haciendo ning�n orde�amiento entre el comienzo
y el fin del orde�amiento fu� 300 segundos (1500 menos 1200).

Su trabajo es escribir un program que examinar� una lista de comienzos de
inicio y final para N(1 &lt;=  N &lt;= 5000) granjeros orde�ando N vacas y
calcule en segundos:

 - El intervalo de tiempo m�s largo en que al menos una vaca fu� orde�ada.
 - El intervalo m�s largo de tiempo (desde que se comienza el orde�o) durante
  el cual ninguna vaca fu� orde�ada.

NOMBRE DEL PROGRAMA: milk2

FORMATO DE ENTRADA

L�nea  1: Un solo entero: N
L�neas 2..N+1: Dos enteros no negativos menores que  1000000, el comienzo y
el fin en segundos despu�s de las 0500

ENTRADA EJEMPLO (archivo milk2.in)

3
300 1000
700 1200
1500 2100


FORMATO DE SALIDA

Una sola l�nea con dos enteros que representan el intervalo de tiempo
continuo m�s grande de orde�o y el m�s largo sin orde�o.

SALIDA EJEMPLO (archivo milk2.out)

900 300
}

const
 mx             = 5001;

var
 fe,fs          : text;
 n,m,mint,maxt  : longint;
 tab            : array[0..mx,1..2] of longint;

procedure open;
var
 i              : longint;
begin
 assign(fe,'milk2.in'); reset(fe);
 assign(fs,'milk2.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  readln(fe,tab[i,1],tab[i,2]);
 close(fe);
end;

procedure qsort(ini,fin,p : longint);
var
 i,j,k,t                  : longint;
begin
 i:=ini; j:=fin; k:=tab[(i+j) div 2,p];
 repeat
  while (tab[i,p] < k) do inc(i);
  while (tab[j,p] > k) do dec(j);
  if i<=j then
   begin
    tab[0]:=tab[i]; tab[i]:=tab[j]; tab[j]:=tab[0];
    inc(i); dec(j);
   end;
 until i>j;
 if i < fin then qsort(i,fin,p);
 if j > ini then qsort(ini,j,p);
end;

function max(n1,n2 : longint) : longint;
begin
 if n1 > n2 then
  max:=n1
 else max:=n2;
end;

procedure work;
var
 i,j,k,r,c      : longint;
begin
 qsort(1,n,2);
 qsort(1,n,1);
 r:=tab[1,1]; c:=tab[1,2];
 mint:=0; maxt:=c-r;
 for i:=2 to n do
  begin
   if (tab[i,1] <= c) and (tab[i,2] > c) then
    begin
     maxt:=max(maxt,tab[i,2] - r);
     c:=tab[i,2];
    end
   else
   if (tab[i,1] > c) then
    begin
     maxt:=max(maxt,tab[i,2] - tab[i,1]);
     mint:=max(mint,tab[i,1] - c);
     r:=tab[i,1]; c:=tab[i,2];
    end;
  end;
end;

procedure closer;
begin
 writeln(fs,maxt,' ',mint);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.