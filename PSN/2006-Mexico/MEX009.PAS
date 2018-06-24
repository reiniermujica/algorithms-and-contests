{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{9ş Descifrar el mensaje.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se  tiene un diccionario con  N  palabras (formadas por los caracteres
de la A a la Z ). Se sabe que se escribi¢ un mensaje secreto usando
alguna de estas palabras (concaten ndolas sin espacio) y que algunas
palabras fueron puestas al derecho y otras al rev‚s.

Ejemplo:

Palabras de Diccionario: aba  iba  ojo  lelo  alto lento
Mensaje Secreto: ojoolelotlaabaabi

Palabras utilizados: ojo  lelo   alto   iba

Se quiere descifrar el mensaje secreto, es decir, encontrar las
palabras originales del diccionario con las que fue construido el
mensaje. Se garantiza que el mensaje secreto fue formado completamente
con las palabras del diccionario  y de la forma descrita. Las palabras
pueden usarse tantas veces como se desee.

Tarea

Hacer un programa que permita:
- Leer desde fichero de entrada MENSAJE.IN las palabras que tiene el
  diccionario, y el mensaje codificado.
- Determinar las palabras con las que se construy¢ el mensaje.
- Escribir hacia el fichero de salida MENSAJE.OUT las palabras que
  componen el mensaje codificado.


Entrada

El fichero de entrada MENSAJE.IN contiene:
L¡nea 1: N (1 <= N <= 200), cantidad de palabras del diccionario.
L¡nea 2..N+1: en cada una de estas l¡neas se escribir  una palabra P
  (la longitud de P ser   <= 100).
L¡nea N+2: C (1 <= C <= 20 000) cantidad de caracteres en el mensaje
L¡nea N+3: el mensaje codificado.

Salida

El fichero de salida MENSAJE.OUT contiene:
L¡nea 1: P, representa la  cantidad de palabras del mensaje.
L¡nea 2..P+1: en cada una de estas l¡neas se escribir n una palabra,
la cual representa a una palabra del mensaje. Las palabras deben
aparecer en el mismo orden en que aparecen de izquierda a derecha en
el mensaje codificado. Pueden existir varias formas de escoger las
palabras en el mensaje aunque lo que importa es una de ellas.

Ejemplo de Entrada y Salida

MENSAJE.IN                   MENSAJE.OUT

6                            5
aba                          ojo
iba                          lelo
ojo                          alto
lelo                         aba
alto                         iba
lento
17
ojoolelotlaabaabi
}
const
 maxic          = 201;
 max            = 20001;

var
 fe,fs          : text;
 n,m            : longint;
 a              : array[1..maxic,1..2] of string[101];
 tex            : array[1..max] of char;
 long           : array[1..maxic] of byte;

procedure open;
var
 i,j,k          : longint;
 St             : string[100];
begin
 assign(fe,'mensage.in'); reset(fe);
 assign(fs,'mensage.out'); rewrite(fs);
 readln(fe,n);
 fillchar(a,sizeof(a),#0);
 for i:=1 to n do
  begin
   readln(fe,St);
   k:=length(St);
   long[i]:=k;
   for j:=1 to long[i] do
    begin
     a[i,1]:=a[i,1] + St[j];
     a[i,2]:=a[i,2] + St[k];
     dec(k);
    end;
  end;
 readln(fe,m);
 for i:=1 to m do read(fe,tex[i]);
 close(fe);
end;

function comp(x,y,z : longint) : boolean;
var
 i,k                : longint;
begin
  k:=x;
  comp:=true;
  for i:=1 to length(a[y,z]) do
   begin
    if tex[k] <> a[y,z,i] then
     begin
      comp:=false;
      exit;
     end;
    inc(k);
   end;
end;

procedure work;
var
 i,j,k,aux      : longint;
 mk             : array[1..max] of boolean;
 res            : array[1..maxic] of byte;
 best           : array[0..max] of byte;
 c              : array[0..max] of byte;
begin
 fillchar(mk,sizeof(mk),false);
 fillchar(best,sizeof(best),0);
 fillchar(c,sizeof(c),255);
 mk[1]:=true; c[0]:=0; best[0]:=0;
 for i:=1 to m do
   if mk[i] then
    begin
      for j:=1 to n do
       for k:=1 to 2 do
          begin
            if (long[j] <= (m - i + 1)) and (comp(i,j,k))
             and (c[i+long[j]-1] > c[i-1] + 1) then
               begin
                mk[i+long[j]]:=true;
                best[i+long[j]-1]:=j;
                c[i+long[j]-1]:=c[i-1] + 1;
                break;
               end;
          end;
    end;
 i:=0; k:=m;
 aux:=best[m];
 while aux <> 0 do
  begin
   inc(i);
   res[i]:=aux;
   k:=k - long[aux];
   aux:=best[k];
  end;
 writeln(fs,i);
 for j:=i downto 1 do
  begin
   writeln(fs,a[res[j],1]);
  end;
 close(fs);
end;

begin
 open;
 work;
end.