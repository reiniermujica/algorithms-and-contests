{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{76¦ Mapa de Densidad                                        Korea 2002
----------------------------------------------------------------------

Se dan:
. los enteros n y r, n > r >= 0,
. la  tabla  F  de n x n con números del conjunto [0,1]; las columnas
  y las filas de la tabla son numeradas desde 1 hasta n, el número en
  la i-ésima columna y en la j-ésima fila es denotado como F[i,j].

Si  [i,j]  y  [i',j']  son  dos posiciones de la tabla F, la distancia
entre  ellas  es el Max(|i-i'|,|j-j'|). La tabla W, de n x n, debe ser
calculada,  donde  W[i,j]  (el  número  en  la i-ésima columna y en la
j-ésima fila de la tabla W) es igual a la suma de todos los números de
F[x, y], tal que la distancia entre [x, y] y [i, j] no es mayor que r.

Tarea

Escriba un programa, el cual:
- lea los enteros n, r y la tabla F desde el fichero texto MAP.IN,
- calcule la tabla W,
- escriba la tabla W hacia el fichero texto MAP.OUT.

Entrada

En    la   primera  línea  texto  MAP.IN  hay  dos  enteros  positivos
separados  por  un  espacio:  n  y  r,  donde  0  <=  r < n <= 250. En
las  siguientes  n  líneas  es  descrita la tabla F. Cada una de estas
líneas    contiene   n  enteros  del  conjunto  [0,1],  separados  por
espacios.  El  i-ésimo  número  escrito  en  la  (j+1)-ésima  línea es
igual a F[i,j].

Salida

El  fichero  MAP.OUT debe contener exactamente n líneas. En la j-ésima
línea    deben    ser    escritos    los  valores  W[1,  j]...  W[n,j]
respectivamente; ellos deben estar separados por un espacio.

Ejemplo de Entrada y Salida:

+-------------+     +-------------+
¦ MAP.IN      ¦     ¦ MAP.OUT     ¦
+-------------¦     +-------------¦
¦ 5 1         ¦     ¦ 3 4 2 2 1   ¦
¦ 1 0 0 0 1   ¦     ¦ 4 5 2 2 1   ¦
¦ 1 1 1 0 0   ¦     ¦ 3 4 3 3 2   ¦
¦ 1 0 0 0 0   ¦     ¦ 2 2 2 2 2   ¦
¦ 0 0 0 1 1   ¦     ¦ 1 1 2 2 2   ¦
¦ 0 1 0 0 0   ¦     +-------------+
+-------------+

}
type
 maxi                   = array[1..250] of word;

var
 fe,fs                  : text;
 n,r                    : integer;
 T                      : array[0..250] of ^maxi;

procedure open;
var
 i,j,x                  : integer;
begin
 assign(fe,'map.in'); reset(fe);
 assign(fs,'map.out'); rewrite(fs);
 readln(fe,n,r);
 new(T[0]);
 fillchar(T[0]^,sizeof(T[0]^),0);
 for i:=1 to n do
  begin
  new(T[i]); fillchar(T[i]^,sizeof(T[i]^),0);
  for j:=1 to n do
   begin
    read(fe,x);
    T[i]^[j]:=T[i-1]^[j] + T[i]^[j-1] - T[i-1]^[j-1] + x;
   end;
  readln(fe);
  end;
 close(fe);
end;

function min(x,y : integer) : integer;
begin
 if x < y then min:=x
 else min:=y;
end;

function max(x,y : integer) : integer;
begin
 if x > y then max:=x
 else max:=y;
end;

procedure work;
var
 i,j,k,x1,y1,x2,y2          : integer;
begin
  for i:=1 to n do
   begin
   for j:=1 to n do
    begin
     x1:=min(i+r,n); y1:=min(j+r,n);
     x2:=max(i-r-1,0); y2:=max(j-r-1,0);
     k:=T[x1]^[y1] - T[x2]^[y1] - T[x1]^[y2] + T[x2]^[y2];
     write(fs,k,' ');
    end;
   writeln(fs);
   end;
   close(fs);
end;

begin
 open;
 work;
end.