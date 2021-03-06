{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{13 Filtro.                                               Croacia 2007
----------------------------------------------------------------------
La mediana de 9 n�meros es el quinto n�mero donde los n�meros son
ordenados en cualquier orden ascendente o descendente. Por ejemplo, la
mediana de los 9 n�meros 1, 3, 4, 1, 2, 6, 8, 4, 10 es 4 porque 1 <= 1
<= 2 <= 3 <= 4 <= 4 <= 6 <= 8 <= 10.

Una imagen I es un arreglo de dos dimensiones R x C de pixels, 3 <= R,
C <= 100 000 000. Cada pixel  tiene un valor entero V, 0 <= V <= 255.

Filtrar una mediana  es una operaci�n de procesar la imagen
removi�ndola. Un filtro puede ser implementado  por un movimiento de
una ventana de 3 x 3 sobre la imagen encontrar la mediana  de los 9
n�meros cubierto por la ventana 3 x 3 en los valores del p�xel
Por ejemplo, dada una imagen de 6 x 5

    �������������������Ŀ
    � 49� 36� 73� 62� 21�
    �������������������Ĵ
    � 27� 88� 14� 11� 12�
    �������������������Ĵ
    � 99� 18� 36� 91� 21�
I=  �������������������Ĵ
    � 45� 96� 72� 12� 10�
    �������������������Ĵ
    � 12� 48� 49� 75� 56�
    �������������������Ĵ
    � 12� 15� 48� 86� 78�
    ���������������������

la imagen filtrada es de 4 x 3

       �����������Ŀ
       � 36� 36� 21�
       �����������Ĵ
       � 45� 36� 14�
J =    �����������Ĵ
       � 48� 49� 49�
       �����������Ĵ
       � 48� 49� 56�
       �������������


Usted puede f�cilmente  puede chequear que una ventana de 3 x 3 movida
a lo largo de la fila de arriba desde la izquierda hasta   la derecha,
el contenido de las  tres ventanas son mostrada debajo (los bordes de
las ventanas de 3 x 3 son mostrada con l�neas gruesas)

 �����������ͻ������Ŀ  ���������������ͻ��Ŀ  �������������������ͻ
 � 49� 36� 73� 62� 21�  � 49� 36� 73� 62� 21�  � 49� 36� 73� 62� 21�
 �������������������Ĵ  �������������������Ĵ  �������������������Ķ
 � 27� 88� 14� 11� 12�  � 27� 88� 14� 11� 12�  � 27� 88� 14� 11� 12�
 �������������������Ĵ  �������������������Ĵ  �������������������Ķ
 � 99� 18� 36� 91� 21�  � 99� 18� 36� 91�21 �  � 99� 18� 36� 91� 21�
 �����������ͼ������Ĵ  ���������������ͼ��Ĵ  �������������������ͼ
 � 45� 96� 72� 12� 10�  � 45� 96� 72� 12� 10�  � 45� 96� 72� 12� 10�
 �������������������Ĵ  �������������������Ĵ  �������������������Ĵ
 � 12� 48� 49� 75� 56�  � 12� 48� 49� 75� 56�  � 12� 48� 49� 75� 56�
 �������������������Ĵ  �������������������Ĵ  �������������������Ĵ
 � 12� 15� 48� 86� 78�  � 12� 15� 48� 86� 78�  � 12� 15� 48� 86� 78�
 ���������������������  ���������������������  ���������������������

Las correspondientes medianas para estas posiciones  de la ventana de
3 x 3 son 36, 36 y 21 respectivamente; por lo tanto ellas constituyen
la fila de arriba de la  imagen filtrada J. Los otros valores de los
pixel de las otras filas de la imagen filtrada J pueden encontrase de
forma similar.

Escriba un programa que de como salida un n�mero entero el cual es el
n�mero de pixels en la imagen filtrada J cuyos valores son mayores o
igual  a un cierto valor dado  T.

Para el valor dado  T = 40, el programa debe dar como salida el n�mero
7 para el ejemplo citado anteriormente porque existen 7 pixels in la
imagen filtrada J cuyos valores son mayores o igual  al valor entero
T dado.

Entrada

La entrada ser� a trav�s del fichero FILTER.IN consistiendo de R + 2
l�neas. La primera l�nea contiene  dos enteros R (el  n�mero de filas)
y C (el n�mero de columnas) separado por un espacio en blanco. Las
siguientes R l�neas contienen  la imagen: cada l�nea contiene C
valores de pixel, con un simple espacio en blanco entre dos adyacentes
valores de pixel. La �ltima l�nea contiene un simple entero T, el
valor dado.

Salida

La salida ser� hacia el fichero FILTER.OUT conteniendo un  simple
entero, el cual es el n�mero de pixels filtrado en la  imagen  J  cuyo
valor es mayor o igual a T.

Ejemplo Entrada 1.
                3 3
                3 4 6
                3 1 9
                1 9 10
                4
Ejemplo Salida 1.
                1

Ejemplo Entrada 2.
                6 5
                49 36 73 62 21
                27 88 14 11 12
                99 18 36 91 21
                45 96 72 12 10
                12 48 49 75 56
                12 15 48 86 78
                40
Ejemplo Salida 2.
                7
}
var
 fe,fs                : text;
 x,y,t,n,i,j          : word;
 a                    : array[1..100,1..100] of byte;
 b                    : array[1..9] of byte;

procedure open;
var
 t0,t1      : integer;
begin
 assign(fe,'filter.in'); reset(fe);
 assign(fs,'filter.out'); rewrite(fs);
 read(fe,x,y);
 for t0:=1 to x do
  begin
   readln(fe);
   for t1:=1 to y do
    read(fe,a[t0,t1]);
  end;
 readln(fe);
 readln(fe,t);
 close(fe);
end;

function suma:word;
var
 h,g,l            : word;
begin
 L:=0;
 for h:=i to i+2 do
  for g:=j to j+2 do
   begin
    inc(l);
    b[l]:=a[h,g];
   end;
 for h:=1 to 9 do
  for g:=h to 9 do
   begin
    if b[h] > b[g] then
     begin
      l:=b[h];
      b[h]:=b[g];
      b[g]:=l;
     end;
   end;
 suma:=b[5];
end;


procedure work;
var
 q,w            : word;
begin
 w:=0;
 for i:=1 to x-2 do
  for j:=1 to y-2 do
   begin
    q:=suma;
    if q >= t then
     inc(w);
   end;
 writeln(fs,w);
 close(fs);
end;

begin
 open;
 work;
end.