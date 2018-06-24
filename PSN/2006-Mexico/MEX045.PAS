{$I-,Q-,R-,S-}
{45¦ Suma Máxima.                                           México 2006
----------------------------------------------------------------------

Dado un arreglo de dos  dimensiones de enteros negativos y  positivos,
encuentre  el subrectangulo  con la  suma más  grande. La  suma de  un
rectangulo es  la suma  de todos  los elementos  en ese rectangulo. En
este problema el  sub-rectangulo con la  mas grande suma  se refiere a
como el subrectangulo maximo. Un subrectangulo es cualquier subarreglo
localizado  dentro   del  arreglo   completo.  Como   un  ejemplo,  el
subrectangulo maximo del arreglo:

    0 -2 -7  0
    9  2 -6  2
   -4  1 -4  1
   -1  8  0 -2

esta en la esquina inferior izquierda:

    9 2
   -4 1
   -1 8

y tiene como suma 15.

Entrada

El fichero de entrada SUBMTX.IN consiste de un arreglo de enteros.  La
entrada comienza   con un   entero positivo   simple N   en una  línea
indicando  el tamaño  del cuadrado de dos dimensiones. Esto es seguido
por N  filas de  N  enteros  cada  uno   separados  entre   si por  un
espacio  en  blanco. N  puede se  tan largo como 100. Los  numeros  en
el arreglo estaran en  el rango [-127, 127].

Salida

La primera y única línea del  fichero de  salida SUBMTX.OUT  contiene un
entero el cual representa la suma del subrectángulo máximo.

Ejemplo de entrada y salida

+------------+  +------------+
¦ SUBMTX.IN  ¦  ¦ SUBMTX.OUT ¦
+------------¦  +------------¦
¦ 4          ¦  ¦ 15         ¦
¦ 0 -2 -7 0  ¦  +------------+
¦ 9 2 -6 2   ¦
¦ -4 1 -4  1 ¦
¦ -1 8 0 -2  ¦
+------------+
 }

const
 max                = 101;

var
 fe,fs              : text;
 n,sol,aux,i,j,k    : longint;
 tab                : array[0..max,0..max] of longint;
 suma               : array[0..max] of longint;

procedure open;
begin
 assign(fe,'submtx.in'); reset(fe);
 assign(fs,'submtx.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    read(fe,tab[i,j]);
   readln(fe);
  end;
 close(fe);
end;

procedure work;
begin
 sol:=-maxlongint;
 for i:=1 to n do
  begin
    fillchar(suma,sizeof(suma),0);
    for j:=i to n do
     begin
      aux:=0;
      for k:=1 to n do
       begin
        suma[k]:=suma[k] + tab[j,k];
        aux:=aux + suma[k];
        if aux > sol then
         sol:=aux;
        if aux < 0 then
         aux:=0;
       end;
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