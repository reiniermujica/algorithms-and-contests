{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{61� Barcos                                               Turqu�a 1999
����������������������������������������������������������������������

El  pa�s  Palmia  est�  dividido  por  un  rio  en las riveras norte y
sur.  Hay  N  pueblos en ambas riveras. Cada pueblo en la rivera norte
tiene  un  �nico  pueblo amigo en la rivera sur. Dos pueblos no tienen
el mismo amigo.

A  cada  par  de  pueblos amigos le gustar�a tener una l�nea de barcos
que  los  conecte  a  ellos.  Ellos  solictar�n  permiso  al gobierno,
porque  muchas  veces  hay  neblina  en  el  rio y el gobierno decidi�
prohibir  intersecciones  de  l�neas  de  barcos  (si  dos  l�neas  se
intersectan hay una alta probabilidad de choques de barcos).

Tarea

Escribir  un programa que ayude a los oficiales del gobierno decidir a
cuales  l�neas  de barcos ellos deben conceder permiso para obtener un
n�mero m�ximo de l�neas de barcos sin intersecci�n.

Entrada

El  fichero  de  entrada contiene en la primera l�nea dos enteros X, Y
separados  por un espacio, X (10 � X � 6000) representa la longitud de
la  rivera  del  Rio  de Palmia , Y (10 � Y � 100) representa el ancho
del  rio.  La segunda l�nea contiene al entero N, el n�mero de pueblos
situados  en  ambas riveras norte y sur (1 � N � 5000). En cada una de
las pr�ximas N l�neas hay dos enteros no negativos C y D separados por
un  espacio  (C,  D � X), representando la distancia de pueblos amigos
del  borde  oeste  (al  este) de Palmia medido a lo largo de la rivera
del  rio (C para el pueblo de la rivera norte y D para el pueblo de la
rivera  Sur).  No  hay  dos  pueblos  en la misma posici�n en la misma
rivera. Ver figura 1 para el ejemplo de entrada.

Salida

El  ficheo  de  salida tiene que contener el n�mero m�ximo de posibles
l�neas de barcos que satisfagan la condici�n de arriba.

��������������������Ŀ�������������������Ŀ
� Ejemplo de Entrada �� Ejemplo de Salida �
��������������������Ĵ�������������������Ĵ
� 30 4               �� 4                 �
� 7                  ����������������������
� 22 4               �
� 2 6                �                     Norte
� 10 3               �        2     4        9  10     15 17  22
� 15 12              �     ���������������������������������������
� 9 8                �
� 17 17              �  Oeste                                    Este
� 4 2                �
����������������������     ���������������������������������������
                              2  3  4  6  8     12        17
                                           Sur
                                         Figura 1
 }

var
 fe,fs                  : text;
 n,sol                  : word;
 a                      : array[1..5000,1..2] of word;
 b                      : array[1..5000] of word;

procedure open;
var
 t                      : word;
begin
 assign(fe,'tur061.in'); reset(fe);
 assign(fs,'tur061.out'); rewrite(fs);
 readln(fe);
 readln(fe,n);
 for t:=1 to n do readln(fe,a[t,1],a[t,2]);
 close(fe);
end;

procedure swap(var x,y : word);
var
 t                 : word;
begin
 t:=x; x:=y; y:=t;
end;

procedure qsort(ini,fin : word);
var
 i,j,k                  : word;
begin
 i:=ini; j:=fin; k:=a[(i+j) div 2,1];
 repeat
  while a[i,1] < k do inc(i);
  while a[j,1] > k do dec(j);
  if i<=j then
   begin
    swap(a[i,1],a[j,1]);
    swap(a[i,2],a[j,2]);
    inc(i); dec(j);
   end;
 until i>j;
 if i<fin then qsort(i,fin);
 if j>ini then qsort(ini,j);
end;

procedure work;
var
 i,j                  : word;
begin
 for i:=1 to n do
  begin
   for j:=1 to i-1 do
    if (a[i,2] > a[j,2]) and (b[j] > b[i]) then
     b[i]:=b[j];
   inc(b[i]);
   if b[i] > sol then sol:=b[i];
  end;
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 qsort(1,n);
 work;
 closer;
end.