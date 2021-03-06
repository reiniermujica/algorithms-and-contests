{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{62� T�nel.                                                    USA 2003
����������������������������������������������������������������������

Mirko est� posicionado  en la entrada y Slavko est� posicionado en la
salida de un t�nel. Ellos anotan el registro de matr�cula (las chapas)
de los autom�viles que pasan por ellos y proporcionan esa informaci�n
a la patrulla de policia que est� a unas millas de ellos en la
carretera.
Usando la informaci�n que Mirko y Slavko les dieron, la polic�a puede
determinar, sin cometer error, que algunos choferes se adelantaron
mientras manejaban a trav�s del t�nel y esto est� estrictamente
prohibido Escriba un programa que determine el n�mero de choferes para
los cuales la polic�a puede alegar que ellos se adelantaron. Nosotros
asumimos que el tr�fico a trav�s del t�nel no tiene ninguna parada.

Entrada

El archivo de la entrada TUNNEL.IN consiste en 2N+1 l�neas. En primera
l�nea hay un entero N, 1 <= N <= 1000, n�mero de autom�viles. En las
pr�ximas N l�neas hay registros de matr�cula de esos autom�viles, en
el orden en que ellos entraron en el t�nel. En las pr�ximas N l�neas
est�n los registros de matr�culas de esos autom�viles, en el orden en
que ellos salieron del t�nel. El registro de matr�cula de un autom�vil
consiste en por lo menos seis y a lo sumo ocho car�cteres y s�lo ser�n
permitidos los caracteres del alfabeto ingl�s (A-Z) y los d�gitos del
sistema decimal (0-9).

Salida

En la primera y �nica l�nea del fichero de salida TUNNEL.OUT aparecer�
el n�mero de choferes que polic�a puede castigar ciertamente por
adelantarse en el t�nel.

Ejemplos de Entrada y Salida:

  Ejemplo #1           Ejemplo # 2             Ejemplo #3

 �����������Ŀ        �����������Ŀ           ������������Ŀ
 � TUNNEL.IN �        � TUNNEL.IN �           � TUNNEL.IN  �
 �����������Ĵ        �����������Ĵ           ������������Ĵ
 � 4         �        � 5         �           � 5          �
 � ZG431SN   �        � ZG508OK   �           � ZG206A     �
 � ZG5080K   �        � PU305A    �           � PU234Q     �
 � ST123D    �        � RI604B    �           � OS945CK    �
 � ZG206A    �        � ZG206A    �           � ZG431SN    �
 � ZG206A    �        � ZG232ZF   �           � ZG5962J    �
 � ZG431SN   �        � PU305A    �           � ZG5962J    �
 � ZG5080K   �        � ZG232ZF   �           � OS945CK    �
 � ST123D    �        � ZG206A    �           � ZG206A     �
 �������������        � ZG508OK   �           � PU234Q     �
                      � RI604B    �           � ZG431SN    �
                      �������������           ��������������
 ������������Ŀ       ������������Ŀ          ������������Ŀ
 � TUNNEL.OUT �       � TUNNEL.OUT �          � TUNNEL.OUT �
 ������������Ĵ       ������������Ĵ          ������������Ĵ
 � 1          �       � 3          �          � 2          �
 ��������������       ��������������          ��������������
 }
const
 max            = 1000;

var
 fe,fs          : text;
 n,sol          : longint;
 mir,sla,sav    : array[1..max] of string[8];
 mk             : array[1..max] of boolean;
 idx            : array[1..max] of longint;

procedure open;
var
 t              : longint;
begin
 assign(fe,'tunnel.in'); reset(fe);
 assign(fs,'tunnel.out'); rewrite(fs);
 readln(fe,n);
 for t:=1 to n do
  begin
   readln(fe,mir[t]);
   sav[t]:=mir[t];
   idx[t]:=t;
  end;
 for t:=1 to n do
  readln(fe,sla[t]);
 close(fe);
end;

procedure qsort(ini,fin : longint);
var
 i,j,l                  : longint;
 k,t                    : string;
begin
 i:=ini; j:=fin; k:=sav[random(j-i+1)+i];
 repeat
   while sav[i] < k do inc(i);
   while sav[j] > k do dec(j);
   if i<=j then
    begin
     t:=sav[i]; sav[i]:=sav[j]; sav[j]:=t;
     l:=idx[i]; idx[i]:=idx[j]; idx[j]:=l;
     inc(i); dec(j);
    end;
 until i>j;
 if i < fin then qsort(i,fin);
 if j > ini then qsort(ini,j);
end;

function search(x : string) : longint;
var
 ini,fin,mit      : longint;
begin
 ini:=1; fin:=n; mit:=(ini + fin) div 2;
 while (sav[mit] <> x) do
  begin
   if sav[mit] < x then
    begin
     ini:=mit + 1;
     mit:=(ini + fin) div 2;
    end
   else
    begin
     fin:=mit;
     mit:=(ini + fin) div 2;
    end;
  end;
 search:=idx[mit];
end;

procedure work;
var
 i,j                    : longint;
begin
 randomize;
 qsort(1,n);
 fillchar(mk,n,true);
 j:=0; sol:=0;
 for i:=1 to n do
  if mk[i] then
   begin
    inc(j);
    while sla[j] <> mir[i] do
     begin
      inc(sol);
      mk[search(sla[j])]:=false;
      inc(j);
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