{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{ 28þ [MAXIMA SUMA]                                       Veszpr‚m '96
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Dado un arreglo de dos dimensiones de enteros positivos y negativos,
 encontrar el rect ngulo con la mayor suma. La suma de un  rect ngulo
 es  la  suma  de  todos  los  elementos  en  ese rect ngulo. En este
 problema   el   sub-arreglo   con   la   mayor   suma, es   nombrado
 "sub-rect ngulo  m ximo". Un  sub-rect ngulo  es  alg£n  sub-arreglo
 contiguo  de  tama¤o  1x1 ¢  mayor, localizado  dentro  del  arreglo
 completo.

 Como ejemplo, el sub-rect ngulo m ximo del arreglo :

    0 -2 -7  0
    9  2 -6  2     9 2
   -4  1 -4  1    -4 1  ( esquina inferior izquierda y tiene
   -1  8  0 -2    -1 8    suma igual a 15 )

 Entrada:

 Consiste en un arreglo de  NxN enteros. La entrada comienza  con  un
 entero positivo  N  en la  l¡nea, indicando el  tama¤o  del  arreglo
 bidimensional cuadrado. Esta es  seguida por  N^2 enteros  separados
 por  una  espacio  en  blanco. Estos  N^2  enteros forman el arreglo
 bidimensional de  N filas y  N columnas. N puede ser tan  largo como
 100. Los n£meros en el arreglo estar n en el rango de -127 a 127.

 Salida:

 La salida es la suma del sub-rect ngulo m ximo.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄ¿
 ³Entrada:          ³       ³ Salida:³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄ´
 ³4                 ³       ³ 15     ³
 ³0 -2 -7 0         ³       ÀÄÄÄÄÄÄÄÄÙ
 ³9 2 -6 2          ³
 ³-4 1 -4 1         ³
 ³-1 8 0 -2         ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 }
const
 max            = 101;

var
 fe,fs          : text;
 n,sol          : longint;
 tab            : array[0..max,0..max] of shortint;
 suma           : array[0..max] of longint;

procedure open;
var
 i,j            : longint;
begin
 assign(fe,'hun028.in'); reset(fe);
 assign(fs,'hun028.out'); rewrite(fs);
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
var
 i,j,k,act      : longint;
begin
 sol:=-maxlongint;
 for i:=1 to n do
  begin
   fillchar(suma,sizeof(suma),0);
   for j:=i to n do
    begin
      act:=0;
      for k:=1 to n do
        begin
          suma[k]:=suma[k] + tab[j,k];
          act:=act + suma[k];
          if act > sol then
           sol:=act;
          if act < 0 then
           act:=0;
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