 {$I-,Q-,R-,S-}

{Dadores Glotones de Regalos
Un grupo de NP (2 <= P <= 10) amigos, cada uno con nombre diferente, han
decidido intercambiar regalos de dinero. Cada uno de estos amigos podr�a o
no dar alg�n dinero a cualquiera de los otros amigos. As� mismo, cada amigo
podr�a o no recibir dinero de cualquiera de todos los otros amigos. Su
objetivo es deducir cu�nto m�s dinero cada persona da que lo que ella recibe.

Las reglas para dar regalos son potencialmente diferentes de lo que usted
podr�a esperar. Cada persona separa cierta cantidad de dinero para dar y
divide este dinero uniformemente entre aquellos a quienes �l o ella est�
dando un regalo. No se dispone de dinero fraccionario, por lo tanto dividir
3 entre dos amigos ser�a dar 1 a cada uno de los amigos con 1 sobrante, ese
1 sobrante permanecer�a en la �cuenta� del dador.

En cualquier grupo de amigos, algunos dan m�s que otros (o al menos pueden
tener m�s cercanos) y algunos tienen m�s dinero que los otros.

Dado un grupo de amigos, ninguno de los cuales tiene un nombre de m�s de 14
caracteres, el dinero que cada persona en el grupo gasta en regalos, y una
(sub)lista de amigos a quienes cada persona da regalos, determine cu�nto m�s
(o menos) cada persona en el grupo da de lo que recibe.

NOTA IMPORTANTE

La m�quina calificadora es una m�quina Linux que usa las convecciones est�ndar
el fin de l�nea es un solo car�cter frecuentemente conocido como `\n`.
Esto es diferente de Windows, donde las l�neas terminan con dos caracteres,
`\n` y `\r`. �No permita que su programa se enrede por esto!

NOMBRE DEL PROGRAMA: gift1

FORMATO DE ENTRADA: L�nea 1:  Un solo entero, NP
L�neas 2..NP+1: Cada l�nea contiene el nombre de un miembro del Grupo
L�neas NP+2..fin:  NP grupos organizados as�: La primera l�nea en el grupo da
el nombre de la persona que dar� los regalos La segunda l�nea en el grupo
contiene dos n�meros: La cantidad inicial de dinero (en el rango 0..2000)
que ser� dividida en regalos por el dador y luego el n�mero de personas a
quienes el dador da regalos, NGi (0 < NGi <= NP-1). Si NGi no es cero, cada
una de las siguientes NGi L�neas contiene el nombre de un receptor de un
Regalo.



ENTRADA EJEMPLO (archivo gift1.in)

5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0

FORMATO DE SALIDA

La salida consiste de NP l�neas, cada una con el nombre de una persona seguida
por un espacio en blanco seguido por la ganancia o p�rdida neta
(valor_final_de_dinero-valor_inicial_de_dinero) para esa persona. Los nombres
deber�an ser impresos en el mismo orden que aparecen en la entrada.

Todos los regalos son enteros. Cada persona da la misma cantidad de dinero a
cada amigo al cual �l da regalos y da tanto dinero como �l pueda que cumpla
estas restricciones. Cualquier dinero que no se d� queda en manos del dador.

SALIDA EJEMPLO (archivo gift1.out)

dave 302
laura 66
owen -359
vick 141
amr -150

}

const
 max            = 11;

var
 fe,fs          : text;
 n              : longint;
 act            : string;
 t              : array[1..max] of string;
 t1             : array[1..max,1..4] of longint;

function find(x : string) : longint;
var
 i               : longint;
begin
 for i:=1 to n do
  if t[i] = x then
   begin
    find:=i;
    exit;
   end;
end;

procedure open;
var
 i,j,k,p,h      : longint;
begin
 assign(fe,'gift1.in'); reset(fe);
 assign(fs,'gift1.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  readln(fe,t[i]);
 for i:=1 to n do
  begin
   readln(fe,act);
   k:=find(act);
   readln(fe,t1[k,1],t1[k,2]);
   t1[k,4]:=t1[k,1];
   if t1[k,2] > 0 then
    begin
     p:=t1[k,1] div t1[k,2];
     t1[k,1]:=t1[k,1] mod t1[k,2];
    end;
   for j:=1 to t1[k,2] do
    begin
     readln(fe,act);
     h:=find(act);
     t1[h,3]:=t1[h,3] + p;
    end;
  end;
 close(fe);
end;

procedure closer;
var
 i,j            : longint;
begin
 for i:=1 to n do
  begin
   j:=find(t[i]);
   writeln(fs,t[i],' ',t1[j,3]-t1[j,4]+t1[j,1]);
  end;
 close(fs)
end;

begin
 open;
 closer;
end.