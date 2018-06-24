{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{54¦ El Cuadrado Máximo.                                 Finlandia 2001
----------------------------------------------------------------------

Una tabla de cuadrados con dimensiones  NxN (3 <= N <= 60)  es ocupada
con  números  enteros, cada  uno  de  los  cuales se  encuentra en  el
intervalo  [-9, 9]. Cada  parte  de  la  tabla  formada  con  K  filas
consecutivas  y  K  columnas consecutivas, 1 <= K <= N, la denominamos
cuadrado. La  suma  de  todos  los  números  dentro  del  cuadrado  la
denominamos suma del cuadrado.

Tarea

Crear un programa, el cual calcule  la  mayor  suma  de  un   cuadrado
dentro de la tabla de cuadrados dada como entrada.

Entrada

La entrada de  debe  leer del archivo de texto  SQR.INP. En la primera
fila de este archivo se sitúa el tamaño N de la tabla. Cada una de las
siguientes  N filas contienen los N números enteros de las filas de la
tabla separados por un espacio.

Salida

La salida del programa se escribirá en un archivo de texto SQR.OUT, en
la única fila de este, el resultado final, o sea la suma máxima de  un
cuadrado.

+------------------+ +-----------------+
¦Ejemplo de Entrada¦ ¦Ejemplo de Salida¦
+------------------¦ +-----------------¦
¦ 4                ¦ ¦ 20              ¦
¦ 2 -8 4 -6        ¦ +-----------------+
¦ 7 1 -5 3         ¦
¦ -9 7 6 5         ¦
¦ 8 3 2 -4         ¦
+------------------+
}
const
 max             = 61;

var
 fe,fs           : text;
 n,i,j,sol       : longint;
 a               : array[0..max,0..max] of longint;

procedure open;
begin
 assign(fe,'sqr.in'); reset(fe);
 assign(fs,'sqr.out'); rewrite(fs);
 readln(fe,n);
end;

function min(a,b : longint) : longint;
begin
 if a < b then min:=a
 else min:=b;
end;

procedure calc;
var
 k,aux           : longint;
begin
 for k:=min(i,j) downto 1 do
  begin
   aux:=a[i,j] - a[i-k,j] - a[i,j-k] + a[i-k,j-k];
   if aux > sol then
    sol:=aux;
  end;
end;

procedure work;
begin
 sol:=-maxlongint;
 for i:=1 to n do
   for j:=1 to n do
    begin
     read(fe,a[i,j]);
     a[i,j]:=a[i,j] + a[i-1,j] + a[i,j-1] - a[i-1,j-1];
     calc;
    end;
 close(fe);
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