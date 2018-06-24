  {$I-,Q-,R-,S-}

{¦ Tubería para el organopónico.                           Korea 2002
----------------------------------------------------------------------

Los  compañeros  de agricultura urbana quieren mover agua del estanque
municipal al organopónico situado a una distancia D (7<= D <=100000).
Ellos  tienen  un  conjunto  de  P  (1<=p<=350) tubos, cada uno con un
entero positivo Li, la longitud y, un entero positivo Ci, la capacidad
(ambos números se pueden representar en 24 Bits).

Los  tubos  pueden  ser conectados en serie en un recorrido. Los tubos
conectados  tienen  la  capacidad de la menor de todas las capacidades
individuales    de    los  tubos.  Un  recorrido  tiene  que  alcanzar
precisamente  D unidades (es decir, la suma de Li para los tubos en un
recorrido tiene que ser igual a D)

Entrada

El fichero de entrada PLUMB.IN contiene:
- línea 1: una línea con dos entero: D y P
- línea 2.. N+1 : cada línea contiene dos enteros describiendo un
  tubo: Li y Ci.

Salida

El fichero de salida PLUMB.OUT contiene una línea con un entero simple
que es el flujo máximo posible legal.


Ejemplo de Entrada y Salida:

+----------+  +-----------+
¦ PLUMB.IN ¦  ¦ PLUMB.OUT ¦
+----------¦  +-----------¦
¦ 7 6      ¦  ¦ 5         ¦
¦ 4 5      ¦  +-----------+
¦ 3 6      ¦
¦ 2 7      ¦
¦ 1 4      ¦
¦ 6 7      ¦
¦ 1 5      ¦
+----------+
 }

const
 mx                     = 100001;

var
 fe,fs                  : text;
 n,m,sol                : longint;
 tab                    : array[1..mx,1..2] of longint;
 best                   : array[1..mx] of longint;

procedure open;
var
 i                      : longint;
begin
 assign(fe,'plumb.in'); reset(fe);
 assign(fs,'plumb.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to m do
  readln(fe,tab[i,1],tab[i,2]);
 close(fe);
end;

function min(n1,n2 : longint) : longint;
begin
 if n1 < n2 then min:=n1
            else min:=n2;
end;

procedure work;
var
 i,j               : longint;
begin
 for i:=1 to m do
  begin
   for j:=n downto 1 do
    begin
     if (best[j] <> 0) and (j + tab[i,1] <= n) and (best[j+tab[i,1]] < min(best[j],tab[i,2])) then
      best[j+tab[i,1]]:=min(best[j],tab[i,2]);
    end;
   if best[tab[i,1]] < tab[i,2] then best[tab[i,1]]:=tab[i,2];
  end;
 sol:=best[n];
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