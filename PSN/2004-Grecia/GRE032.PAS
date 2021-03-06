{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{32� Exchange.                                              Grecia 2004
����������������������������������������������������������������������

David, de alg�n modo, adquiri� las tasas de cambio del d�lar americano
a marcos alemanes para varios d�as en el futuro.

Tarea

Escriba un programa que har� pensar a David en cu�ndo comprar o vender
marcos o d�lares para que, empezando con 100 marcos �l termine con la
mayor cantidad posible de marcos al final del �ltimo d�a.

Fichero de entrada (EXCHANGE.IN)

La primera l�nea del archivo de la entrada contiene un n�mero natural
N, 1 <= N <= 100, el n�mero de d�as futuros por los que David conoce
las tasas de cambio. Cada uno de las N l�neas siguientes contiene dos
n�meros naturales B y S separados con un espacio, 100 <= B <= S <=
1000. La (i+1) - �sima l�nea describe el tipo de cambio del i - �simo
d�a. Esos dos n�meros determinan la tasa de cambio de la manera
siguiente: Pueden comprarse B d�lares para 100 marcos, y pueden
comprarse 100 marcos para S d�lares.

Fichero de salida (EXCHANGE.OUT)

La primera y �nica l�nea del archivo de salida debe contener un n�mero
que representa la mayor cantidad de marcos deseados escrito con dos
lugares decimales.

Comentario: Debido a los errores con la aritmetica de los reales, se
considerar�n como correctos los resultados dentro del rango de error
de 0.05 marcos.

Ejemplo #1 de Entrada y Salida      Ejemplo #2 de Entrada y Salida

�������������Ŀ ��������������Ŀ    �������������Ŀ ��������������Ŀ
� EXCHANGE.IN � � EXCHANGE.OUT �    � EXCHANGE.IN � � EXCHANGE.OUT �
�������������Ĵ ��������������Ĵ    �������������Ĵ ��������������Ĵ
� 3           � � 102.07       �    � 5           � � 103.12       �
� 393 398     � ����������������    � 300 300     � ����������������
� 394 401     �                     � 310 320     �
� 386 386     �                     � 320 330     �
���������������                     � 330 330     �
                                    � 300 320     �
                                    ���������������


Ejemplo #3 de Entrada y Salida

�������������Ŀ ��������������Ŀ
� EXCHANGE.IN � � EXCHANGE.OUT �
�������������Ĵ ��������������Ĵ
� 8           � � 126.14       �
� 218 219     � ����������������
� 228 231     �
� 227 235     �  Ejemplo #3
� 205 213     �
� 230 232     �  D�a 2... Cambiando 100.0000 DEM a 228.0000 USD
� 239 239     �  D�a 4... Cambiando 228.0000 USD a 107.0422 DEM
� 251 258     �  D�a 7... Cambiando 107.0422 DEM a 268.6760 USD
� 205 213     �  D�a 8... Cambiando 268.6760 USD a 126.1389 DEM
���������������
 }
var
 fe,fs          : text;
 n,i            : byte;
 chan           : array[1..100,1..2] of real;

procedure open;
begin
 assign(fe,'EXCHANGE.IN'); reset(fe);
 assign(fs,'EXCHANGE.out'); rewrite(fs);
 readln(fe,n);
end;

function max(x,y : real) : real;
begin
 if x > y then max:=x
 else max:=y;
end;

procedure work;
var
 b,s            : real;
begin
 readln(fe,b,s);
 chan[1,1]:=b; chan[1,2]:=100;
 for i:=2 to n do
  begin
   readln(fe,b,s);
   chan[i,1]:=max(chan[i-1,1],chan[i-1,2]*b/100);
   chan[i,2]:=max(chan[i-1,2],chan[i-1,1]*100/s);
  end;
end;

procedure closer;
begin
 writeln(fs,chan[n,2]:0:2);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.