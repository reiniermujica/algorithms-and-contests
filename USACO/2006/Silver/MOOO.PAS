 {$I-,Q-,R-,S-}

{Problema 6: Moo [Brian Dean, 2005]

Las N (1 &lt;= N &lt;= 50,000) vacas del Granjero Juan est�n en una fila muy
larga mugiendo. Cada vaca tiene una altura �nica h en el rango
1..2,000,000,000 nan�metros (GJ  realmente es muy quisquilloso con la
precisi�n). Cada vaca muge en alg�n volumen v en el rango 1..10,000.
Este mugido viaja a trav�s de la fila de vacas en ambas direcciones
(excepto obviamente para las vacas en los extremos). Curiosamente, es
oido por las vacas mas cercanas en cada direcci�n cuyas alturas sean
estrictamente mayores que la vaca mugidora (por lo tanto cada mugido
ser� oido por 0, 1 o 2 vacas, dependiendo si o no vacas mas altas
existan a la derecha o izquierda de la vaca mugidora).

El volumen total de mugido o�do por una vaca dada es la suma de todos
los vol�menes de mugido que llegan a la vaca. Desde que algunas vacas
(presumiblemente m�s altas) podr�an estar sometidas a una cantidad muy
grande de volumen de mugido, GJ quiere comprar tapones para la vaca
cuya audici�n sea la m�s amenazada. Por favor, calcule el volumen de
mugido mas alto o�do por cualquier vaca.

NOMBRE DEL PROBLEMA: mooo

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, N.

* L�neas 2..N+1: La l�nea i+1 contiene dos enteros, h y v, para la
     vaca que est� en la ubicaci�n i.

ENTRADA EJEMPLO (archivo mooo.in):

3
4 2
3 5
6 10

DETALLES DE LA ENTRADA:

Tres vacas: la primera tiene altura 4 y muge con volumen 2, etc.

FORMATO DE SALIDA:

* L�nea 1: El volumen de mugido m�s grande o�do por cualquier vaca en
     particular.

SALIDA EJEMPLO (archivo moo.out):

7

DETALLES DE LA SALIDA:

La tercera vaca va oye tanto los mugidos de la primera y segunda vacas
2+5=7. A pesar que la tercera vaca muge con volumen 10, ninguna la
oye.
 }

 { 2 * n }

const
 mx             = 50001;

var
 fe,fs          : text;
 n,sol          : longint;
 tab            : array[1..mx,1..2] of longint;
 cont,next      : array[1..mx] of longint;

procedure open;
var
 i              : longint;
begin
 assign(fe,'mooo.in'); reset(fe);
 assign(fs,'mooo.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  readln(fe,tab[i,1],tab[i,2]);
 close(fe);
end;

procedure work;
var
 i,j            : longint;
begin
 fillchar(next,sizeof(next),0); sol:=0;
 for i:=2 to n do { 1 --------> n }
  begin
   j:=i-1;
   repeat
    begin
     if (tab[i,1] < tab[j,1]) then
      begin
       cont[j] := cont[j] + tab[i,2];
       next[i]:=j;
       if cont[j] > sol then sol:=cont[j];
       j:=0;
      end
      else
       j:=next[j];
    end
   until j=0;
  end;
 fillchar(next,sizeof(next),0);
 for i:=n-1 downto 1 do { 1 <-------- n }
  begin
   j:=i+1;
   repeat
    begin
     if (tab[i,1] < tab[j,1]) then
      begin
       cont[j] := cont[j] + tab[i,2];
       next[i]:=j;
       if cont[j] > sol then sol:=cont[j];
       j:=0;
      end
      else
       j:=next[j];
    end
   until j=0;
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