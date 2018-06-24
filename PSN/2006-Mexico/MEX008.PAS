{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{8ş Extraer Subsecuencia.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
                             
Se tiene una secuencia de N números enteros positivos. Se quiere
extraer una subsecuencia  del tal forma que en la subsecuencia
extraída cada número sea divisible por cada uno de los anteriores a él
en la subsecuencia.

Ejemplo:

Para la lista original:  8  3  2  4  6   6  8  10  15  9  25  12  13
                                         -            -    -                               ---

Los elementos marcados forman la subsecuencia y cumplen
la propiedad de divisibilidad, o sea, el 6 es divisible por 3 y el
próximo 6 es divisible por 6 y por 3, el 12 es divisible por los
dos 6 y por 3.

Usted debe encontrar  la subsecuencia que cumpla los requisitos de
divisibilidad expresados anteriormente y que la cantidad de elementos
de la misma sea máxima.

Tarea

Hacer un programa que permita:
- Leer desde fichero de entrada SUB.IN  la secuencia dada.

- Encontrar la mayor subsecuencia, según la definición anteriormente
  explicada.

- Escribir hacia el fichero de salida SUB.OUT la cantidad de elementos
  de la mayor subsecuencia encontrada y los elementos que la conforman.

Entrada

El fichero de entrada SUB.IN contiene:
Línea 1: N (1 <= N <= 2000), cantidad de elementos de la
   secuencia.
Línea 2..N+1: En la línea i+1 se escribirá un valor Mi(0 <=Mi <=10000)
  el cual representa al i-ésimo elemento de la secuencia.

Salida

El fichero de salida SUB.OUT contiene:
Línea 1: S, el cual representa la  cantidad de elementos de la
  subsecuencia encontrada.
Línea 2..S+1: En cada una de estas se escribirán un elemento de la
  subsecuencia encontrada en el mismo orden en que estos aparecen en
  la secuencia original.


Ejemplo de Entrada y Salida

SUB.IN                 SUB.OUT

13                     4
8                      3
3                      6
2                      6
4                      12
6
6
8
10
15
9
25
12
13
 }

var
 fe,fs          : text;
 n,sol,act      : integer;
 a,b,cam,res    : array[0..2001] of integer;

procedure open;
var
 t              : integer;
begin
 assign(fe,'sub.in'); reset(fe);
 assign(fs,'sub.out'); rewrite(fs);
 readln(fe,n);
 for t:=1 to n do readln(fe,a[t]);
 close(fe);
end;

procedure work;
var
 i,j            : integer;
begin
 sol:=0; act:=0;
 for i:=1 to n do
   begin
    for j:=1 to i-1 do
     if (b[j] > b[i]) and (a[i] mod a[j] = 0) then
       begin
        b[i]:=b[j];
        cam[i]:=j;
       end;
    inc(b[i]);
    if b[i] > sol then
     begin
      sol:=b[i];
      act:=i;
     end;
   end;
end;

procedure closer;
var
 t              : integer;
begin
 t:=1; res[1]:=act;
 while t < sol do
  begin
   act:=cam[act];
   inc(t);
   res[t]:=act;
  end;
 writeln(fs,sol);
 for t:=sol downto 1 do writeln(fs,a[res[t]]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.