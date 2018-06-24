  {$I-,Q-,R-,S-}

{Problema 6: Lexicon Vacuno [Vladimir Novakovski, 2002]


Pocos saben que las vacas tienen su propio diccionario con W (1 <= W
<= 600) palabras, cada una conteniendo no más de 25 de los caracteres
'a'..'z'. Debido a que su sistema de comunicación, basado en mugidos,
no es muy preciso, algunas veces ellas oyen palabras que no tienen
ningún sentido. Por ejemplo, Bessie una vez recibió un mensaje que
decía "browndcodw". Y resulta ser que el mensaje deseado era
"browncow". Las dos letras "d"s eran ruido de otra partes del corral.

Las vacas quieren que usted las ayude a descifrar un mensaje recibido
(también contiendo únicamente caracteres en el rango 'a'..'z') de
longitud de L (1 <= L <= 300) caracteres que está un poco enredado. En
particular, ellas saben que el mensaje tiene algunas letras extra, y
ellas quieren que usted determine el menor número de letras que deben
ser removidas para hacer que el mensaje sea una secuencia de palabras
del diccionario.

NOMBRE DEL PROBLEMA: lexicon

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio, respectivamente: W y L

* Líneas 2: L caracteres (seguidos por un carácter de nueva línea, por
      supuesto): el mensaje recibido

* Líneas 3..W+2: El diccionario de las vacas, una palabra por línea.

ENTRADA EJEMPLO (archivo lexicon.in):

6 10
browndcodw
cow
milk
white
black
brown
farmer

FORMATO DE SALIDA:

* Línea 1: Una solo entero que es el mínimo número de caracteres que
      necesitan ser removidos para hacer el mensaje una secuencia de
      palabras del diccionario.

SALIDA EJEMPLO (archivo lexicon.OUT):
 }

const
 max            = 301;
 maxword        = 601;

var
 fe,fs          : text;
 n,m,sol        : longint;
 cad            : array[1..max] of char;
 list           : array[1..maxword] of string[26];
 best           : array[1..max] of longint;
 cont           : array[1..maxword] of longint;
 be             : array[1..131072] of byte;

procedure open;
var
 i              : longint;
begin
 assign(fe,'lexicon.in'); reset(fe);
 assign(fs,'lexicon.out'); rewrite(fs);
 settextbuf(fe,be);
 readln(fe,m,n);
 for i:=1 to n do
  begin
   read(fe,cad[i]);
   best[i]:=i;
  end;
 readln(fe);
 for i:=1 to m do
  begin
   readln(fe,list[i]);
   cont[i]:=length(list[i]);
  end;
 close(fe);
end;

procedure comprueba(x,y : longint);
var
 i,j,k                  : longint;
begin
 j:=x; k:=0;
 for i:=1 to cont[y] do
  begin
   while (list[y,i] <> cad[j]) do
    begin
     inc(j);
     inc(k);
    end;
   inc(j);
  end;
   if (best[x-1] + k < best[j-1]) then
    best[j-1]:=best[x-1] + k;
end;

procedure work;
var
 i,j             : longint;
begin
 for i:=1 to n do
   begin
    for j:=1 to m do
      begin
       if (i + cont[j]-1 <= n) and (cad[i] = list[j][1]) then
        comprueba(i,j);
      end;
    if (best[i] + 1 < best[i+1]) then
      best[i+1]:=best[i] + 1;
   end;
end;

procedure closer;
begin
 writeln(fs,best[n]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.
