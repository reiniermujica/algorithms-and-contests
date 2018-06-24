{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{94¦ Apilamiento de Platos.                                Polonia 2005
----------------------------------------------------------------------

Las vacas quieren estar en la TV. Ellas han decidido que su mejor
oportunidad es mostrar su habilidad en apilar platos tan alto como
ellas posiblemente lo puedan hacer. Su propósito es maximizar el valor
de entretenimiento apilando ciertos platos que son lanzados del
estudio izquierdo al estudio central.

Por supuesto, los platos pueden ser únicamente apilados cuando un
plato estrictamente menor es puesto encima de un plato más grande. Por
lo tanto, algunos platos podrían ser descartados.

Dada la secuencia de enteros de N (1 <= N <= 5,000) platos lanzados
desde el lado del estudio, calcule la altura (en platos) de la
estructura de platos apilados más alta posible que puede ser
construida. Los tamaños son enteros en el rango 1..1,000,000.

Si los platos fueran lanzados en este orden:

7 10 7 8 9 7 8 6 4

Entonces la pila mas alta posible seria 10, 9, 8, 6, 4,
cuya altura es 5.

FORMATO DE ENTRADA:

- Línea 1: Un solo entero, N

- Líneas 2..N+1: La línea i+1 describe el i-'esimo plato lanzado desde
  el lado del estudio.

ENTRADA EJEMPLO (archivo plates.in):

9
7
10
7
8
9
7
8
6
4

FORMATO DE SALIDA:

- Línea 1: Una sola línea con la altura máxima de platos que se puede
obtener.

SALIDA EJEMPLO (archivo plates.out):

5
}

var
 fe,fs                  : text;
 n,sol                  : longint;
 a,b                    : array[1..5000] of longint;

procedure open;
var
 t                      : longint;
begin
 assign(fe,'plates.in'); reset(fe);
 assign(fs,'plates.out'); rewrite(fs);
 readln(fe,n);
 for t:=1 to n do readln(fe,a[t]);
 close(fe);
end;

procedure work;
var
 i,j                   : longint;
begin
 sol:=0; fillchar(b,sizeof(b),0);
 for i:=1 to n do
  begin
  for j:=1 to i-1 do
   if (a[i] < a[j]) and (b[j] > b[i]) then
     b[i]:=b[j];
  inc(b[i]);
  if b[i]>sol then sol:=b[i];
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