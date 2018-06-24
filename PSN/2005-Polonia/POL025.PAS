{$I-,Q-,R-,S-}

{25ş Similitud Vacuna                                      Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El Granjero Juan  tiene N (2  <= N <=  50) vacas diferentes  numeradas
1..N y quiere conocer cuales dos se parecen m s entre s¡. El ha  hecho
fotograf¡as digitales 5x7 de cada una de sus vacas y quiere que  usted
escriba un programa que las compare.

Las fotos 5x7 muestran los patrones de manchas blancas y negras de una
baca. A  continuaci¢n est n  los fotos  de dos  vacas diferentes  ('X'
representa una parte negra, '.' Representa una parte blanca):

     Vaca 1         Vaca 2
     ..X....       ...X...
     .XXX...       ..XX...
     .XX....       .XX....
     .....X.       .XX..X.
     .X...X.       .X...X.

Para   comparar   estas   dos   vacas,   cada   mancha   en  cuadrados
correspondiente es verificada. Cada mancha que sea la misma obtiene un
'punto de similitud'. Las dos vacas presentadas obtienen 30 'puntos de
similitud'debido a  que solo  cinco de  los cuadrados correspondientes
son diferentes (ver '#' a continuaci¢n):

         ++##+++
         +#+++++
         +++++++
         +##++++
         +++++++

Dado un conjunto de vacas, encuentre  las dos que son m s similares  e
impriman sus  dos n£meros  de identificaci¢n  en orden  ascendente. Se
garantiza  que solo  un par  de vacas  tiene el  puntaje m s  alto  de
similitud.

NOMBRE DEL PROBLEMA: likecow

FORMATO  DE  ENTRADA:

- L¡nea 1: N,  el n£mero  de  vacas
- L¡neas 2..N*5+1: Las fotograf¡as digitales de las vacas, con la vaca
  i apareciendo  desde  la  l¡nea   i*5+1  a  la l¡nea  i*5+5. Vea  el
  ejemplo a continuaci¢n.

ENTRADA EJEMPLO (archivo likecow.in):

3
..X....
.XXX...
.XX....
.....X.
.X...X.
...X...
..XX...
.XX....
.XX..X.
.X...X.
XX.....
X......
XX...XX
XXXX.XX
XXX..XX


DETALLES DE LA ENTRADA:
Las dos vacas de la entrada, adem s de una vaca extra.

FORMATO DE SALIDA:

- L¡nea 1: Las dos vacas  teniendo el m ximo puntaje de similitud,  en
  orden ascendente.

SALIDA EJEMPLO (archivo likecow.out):
1 2

DETALLES DE LA SALIDA:

La  tercera vaca tiene  un puntaje  de similitud  de 16  y 19   con la
vaca  1  y  con  la  vaca  2  respectivamente,  ambos  menores que  el
puntaje de similitud de 30 entre las vacas 1 y 2.

 }

const
 max            = 50;

var
 fe,fs          : text;
 n              : byte;
 cows           : array[1..max,1..5,1..7] of char;
 point          : array[1..max] of longint;
 sol            : array[1..2] of byte;

procedure open;
begin
 assign(fe,'likecow.in'); reset(fe);
 assign(fs,'likecow.out'); rewrite(fs);
 readln(fe,n);
end;

procedure work;
var
 i,j,k,t,best   : longint;
begin
 best:=0;
 for i:=1 to n do
   begin
    for j:=1 to 5 do
     begin
       for k:=1 to 7 do
        read(fe,cows[i,j,k]);
       readln(fe);
     end;
    fillchar(point,sizeof(point),0);
    for t:=1 to i-1 do
      begin
        for j:=1 to 5 do
         for k:=1 to 7 do
           begin
             if (cows[t,j,k] = cows[i,j,k]) then
              inc(point[t]);
           end;
      end;
    for j:=1 to i-1 do
     begin
      if (point[j] > best) then
       begin
        best:=point[j];
        sol[1]:=j;
        sol[2]:=i;
       end;
     end;
   end;
 close(fe);
end;

procedure closer;
begin
 writeln(fs,sol[1],' ',sol[2]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.
