{
PROG: shelf2
LANG: PASCAL
}

 {$I-,Q-,R-,S-}

{Problema 12: Estante 2 [Neal Wu, 2007]

El Granjero Juan compro recientemente otro estante para la librería
vacuna, pero el estante se está llenando rápidamente, y ahora el único
espacio disponible es el de arriba.

GJ tiene N vacas (1 <= N <= 20) cada una de alguna altura de H_i (1 <=
H_i <= 1,000,000 – estas son vacas muy altas). El estante tiene altura de
B (1 <= B <= S, donde S es la suma de las alturas de todas las vacas).

Para alcanzar la parte alta del estante, uno o más de las vacas se suben
una encima de otra en una pila, de tal manera que su altura total es la
suma de sus alturas individuales. Esta altura total debe ser no menor que
la altura del estante con el propósito que las vacas alcancen la parte
superior del estante.

Como una pila más grande que la necesaria puede ser peligrosa, su tarea
es encontrar el conjunto de vacas que produce una pila de la menor altura
posible tal que la pila pueda alcanzar la parte superior del estante. Su
programa debería producir la altura de 'exceso' mínima entre la pila
óptima de vacas y el estante.

NOMBRE DEL PROBLEMA: shelf2

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio N y B

* Líneas 2..N+1: la línea i+1 contiene un solo entero: H_i

ENTRADA EJEMPLO (archivo shelf2.in):

5 16
3
1
3
5
6

FORMATO DE SALIDA:

* Línea 1: un solo entero representando la diferencia (no negativa)
     entre al altura total del conjunto optimo de vacas y la altura del
     estante.

SALIDA EJEMPLO (archivo shelf2.out):

1

DETALLES DE LA SALIDA:

Aquí usamos las vacas 1, 3, 4, y 5, para una altura total de  3 + 3+ 5 +
6 = 17. No es posible obtener una altura total de 16, por lo tanto, la
respuesta es 1.
}

const
 mx                  = 1100000;

var
 fe,fs               : text;
 n,m,sol             : longint;
 best                : array[0..mx] of longint;

procedure open;
begin
 assign(fe,'shelf2.in'); reset(fe);
 assign(fs,'shelf2.out'); rewrite(fs);
 readln(fe,n,m);
end;

procedure work;
var
 i,j,k,t               : longint;
begin
 k:=0; sol:=maxlongint; k:=0;
 for i:=1 to n do
  begin
   inc(k);
   readln(fe,best[k]);
   t:=k;
   for j:=1 to t-1 do
    begin
     inc(k);
     best[k]:=best[j] + best[t];
     if (best[k] >= m) and (best[k] - m < sol) then
      sol:=best[k] - m;
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