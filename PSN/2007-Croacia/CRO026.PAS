 {$I-,Q-,R-,S-}

{� Configuraciones de teclado.                           Croacia 2007
----------------------------------------------------------------------

La Compa��a IslaMovil ha instalado un nuevo servicio en sus  tel�fonos
m�viles con el objetivo de  hacerlos m�s baratos. La novedad  consiste
en que al  trasmitir mensajes de  texto cada operaci�n  de clic  sobre
un caracter en  el teclado tiene   un valor  de 1  centavo. El   nuevo
sistema  tiene  varias  configuraciones  de  teclado   las  cuales  en
dependencia  del  mensaje   se  pueden  ir  alternando.  El  cambio de
configuraci�n de teclado cuesta solamente 1 centavo. El teclado  va  a
tener siempre 9 teclas y la tecla #, que es la tecla de control. A las
teclas num�ricas en dependencia de la configuraci�n se les asigna  una
determinada secuencia de caracteres.

Tomemos inicialmente un  teclado, en cada  tecla pueden existir  uno o
varios caracteres del  alfabeto ingl�s y  todas las letras  aparecer�n
una sola  vez sin  repetici�n en  una configuraci�n,  colocadas en  un
orden, por ejemplo si  en la tecla  4  est�n las letras ghi,  entonces
para colocar la  letra i  en un  mensaje hay  que oprimir  la tecla  4
tres veces.

Siempre es posible escribir un mensaje usando las configuraciones  del
teclado disponible. El problema entonces radica en minimizar el  gasto
al enviar un mensaje.

Tarea

Hacer un programa que permita:

-	Leer  desde fichero  de entrada  TCONFIG2.IN el  mensaje que se desea
  enviar y las configuraciones del teclado del dispositivo.

-	Determinar el menor costo posible con que puede enviarse el mensaje,
  as� como la secuencia de clic que fueron necesarios.

-	Escribir hacia  el fichero  de salida  TCONFIG2.OUT el  menor costo
  encontrado y  la secuencia  de clic  que se  necesitan para   enviar
  el mensaje con ese costo.

Entrada

El fichero de entrada TCONFIG2.IN contiene:
L�nea 1: N (1 <= N <= 5000) el n�mero de caracteres del mensaje.
L�nea 2: el mensaje, escrito sin espacios y con caracteres en
min�sculas.
L�nea 3: C (1 <= C <= 10), cantidad de configuraciones de teclados.
L�nea 4..C*9 + C-1: Se escribir�n para cada configuraci�n el n�mero de
la tecla y los caracteres asociados a dicha tecla en el orden que
ellos aparecen. Una configuraci�n se separa de la otra por una l�nea
en blanco.

Salida

El fichero de salida TCONFIG2.OUT contiene:
L�nea 1: el entero CM el cual representan el costo del mensaje.
L�nea 2..en adelante: en cada una  de ellas el car�cter del mensaje  y
la tecla a la que le corresponde el car�cter la cantidad de veces que
esa tecla se  oprimi�, en el caso  de ser el car�cter de control colocamos
el s�mbolo de # y la configuraci�n  para la cual se cambio.

Ejemplo de Entrada y Salida

+--------------+ +--------------+
� TCONFIG2.IN  � � TCONFIG2.OUT �
+--------------� +--------------�
� 11           � � 20           �
� computadora  � � #2           �
� 2            � � c 22         �
� 1 w          � � o 99         �
� 2 abc        � � #1           �
� 3 def        � � m 6          �
� 4 ghi        � � p 7          �
� 5 jkl        � � u 88         �
� 6 mno        � � t 8          �
� 7 pqrs       � � a 2          �
� 8 tuv        � � d 3          �
� 9 xyz        � � #2           �
� a 2          � � o 99         �
�              � � r 66         �
� 1 yz         � � a 44         �
� 2 gcm        � +--------------+
� 3 knl        �
� 4 ea         �
� 5 jbiv       �
� 6 xrt        �
� 7 dfw        �
� 8 ps         �
� 9 uoq        �
+--------------+
 }

const
 mx             = 5001;

var
 fe,fs          : text;
 n,m            : longint;
 ch             : char;
 cad            : array[1..mx] of char;
 best           : array[1..2] of longint;
 tab            : array[1..11,'a'..'z',1..2] of longint;
 t1             : array[boolean,1..mx] of longint;
 cam            : array[1..mx,1..11] of longint;
 res            : array[1..mx] of longint;

procedure open;
var
 i,j,k,l        : longint;
begin
 assign(fe,'tconfig2.in'); reset(fe);
 assign(fs,'tconfig2.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  read(fe,cad[i]);
 readln(fe);
 readln(fe,m);
 for i:=1 to m do
  begin
   for j:=1 to 9 do
    begin
     read(fe,k); read(fe,ch); l:=0;
     while not eoln(fe) do
      begin
       inc(l);
       read(fe,ch);
       tab[i,ch,1]:=l;
       tab[i,ch,2]:=k;
      end;
     readln(fe);
    end;
   readln(fe);
  end;
 close(fe);
end;

procedure work;
var
 i,j,k,k2       : longint;
 s              : boolean;
begin
 s:=false;
 best[1]:=maxlongint;
 for i:=1 to m do
  begin
   t1[s,i]:=tab[i,cad[1],1] + 1;
   cam[1,i]:=i;
   if t1[s,i] < best[1] then
    begin
     best[1]:=t1[s,i];
     best[2]:=i;
    end;
  end;
 s:=true;
 for i:=2 to n do
  begin
   for j:=1 to m do
    begin
     k:=t1[not s,j] + tab[j,cad[i],1];
     k2:=best[1] + tab[j,cad[i],1] + 1;
     if k < k2 then
      begin
       t1[s,j]:=k;
       cam[i,j]:=j;
      end
     else
      begin
       t1[s,j]:=k2;
       cam[i,j]:=best[2];
      end;
    end;
   best[1]:=maxlongint;
   for j:=1 to m do
    begin
     if t1[s,j] < best[1] then
      begin
       best[1]:=t1[s,j];
       best[2]:=j;
      end;
    end;
   s:=not s;
  end;
end;

procedure writer(x,c : longint);
var
 i                   : longint;
begin
 for i:=1 to x do
  write(fs,c);
 writeln(fs);
end;

procedure closer;
var
 i,j,k          : longint;
begin
 writeln(fs,best[1]);
 k:=best[2]; j:=n; res[n]:=k;
 while (j <> 1) do
  begin
   k:=cam[j,k];
   dec(j);
   res[j]:=k;
  end;
 writeln(fs,'#',res[1]);
 write(fs,cad[1],' ');
 writer(tab[res[1],cad[1],1],tab[res[1],cad[1],2]);
 for i:=2 to n do
  begin
   if (res[i] = res[i-1]) then
    begin
     write(fs,cad[i],' ');
     writer(tab[res[i],cad[i],1],tab[res[i],cad[i],2]);
    end
   else
    begin
     writeln(fs,'#',res[i]);
     write(fs,cad[i],' ');
     writer(tab[res[i],cad[i],1],tab[res[i],cad[i],2]);
    end;
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.