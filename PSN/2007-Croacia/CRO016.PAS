{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{16¦ Modulo.                                               Croacia 2007
----------------------------------------------------------------------

Dado dos enteros A y B, A modulo B es el resto cuando dividimos A  por
B. Por ejemplo, los nuemros 7,  14, 27 y 38 toman 1, 2, 0  y 2, modulo
3. Escriba un programa que acepte  10 números  como entrada y de  como
salida el número de distinto  números  de la entrada,  si  los números
son  considerados modulo 42.

Entrada

El fichero de entrada MODULO.IN debe contener de 10 enetros no
negativos, cada uno mas pequeño que 1000, uno por línea.

Salida

El fihcero de salida MODULO.OUT debe contener el número de distintos
valores que son considerados modulo 42 en una simple línea.

Ejemplos de Enttada y Salida:

MODULO.IN           MODULO.OUT
1                   10
2
3
4
5
6
7
8
9
10

MODULO.IN           MODULO.OUT
42                  1
84
252
420
840
126
42
84
420
126

MODULO.IN           MODULO.OUT
39                  6
40
41
42
43
44
82
83
84
85

Calificacion: En el primer ejemplo,  los números modulo 42 son  1,  2,
3, 4, 5, 6, 7, 8, 9  y  10. En  el  segundo  ejemplo todos los números
modulo 42 son 0. En el  tercer ejemplo, los números  modulo 42 son 39,
40, 41, 0, 1, 2, 40, 41, 0 y 1. Hay 6.
}

var
 fe,fs               : text;
 A                   : array[1..10] of longint;
 B                   : array[0..1000] of boolean;
 sol                 : longint;

procedure open;
var
 t                   : longint;
begin
 assign(fe,'modulo.in'); reset(fe);
 assign(fs,'modulo.out'); rewrite(fs);
 for t:=1 to 10 do
  readln(fe,A[t]);
 close(fe);
end;

procedure work;
var
 i,k,max             : longint;
begin
 sol:=0; max:=0;
 for i:=1 to 10 do
  begin
   k:=a[i] mod 42;
   b[k]:=true;
   if k > max then max:=k;
  end;
 for i:=0 to max do
  if b[i] then inc(sol);
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
end.