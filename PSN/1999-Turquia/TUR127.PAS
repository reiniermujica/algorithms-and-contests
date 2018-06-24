{$I-,Q-,R-,S-}
{ 127ş N£meros de tel‚fono                                 Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En el mundo actual usted se encuentra frecuentemente muchos n£meros
telef¢nicos cada vez m s largos. Usted necesita recordar semejante
tipo de n£meros. Un m‚todo de c¢mo hacerlo de una manera f cil es
asignar letras a los d¡gitos como es mostrado en el cuadro siguiente:

  1 ij   2 abc   3 def
  4 gh   5 kl    6 mn
  7 prs  8 tuv   9 wxy
         0 oqz

De esta manera cada palabra o grupo de palabras pueden ser
asignados a un £nico n£mero, para que usted puede recordar palabras en
lugar de los n£meros telef¢nicos. Es evidente que tiene su propio
encanto si es posible encontrar alguna relaci¢n simple entre la
palabra y la propia persona. As¡ usted puede aprender que  el n£mero
941837296 de un amigo suyo jugador de ajedrez puede leerse como
WHITEPAWN, y el n£mero 285304 de su maestro favorito se lee BULDOG.

Escriba un programa para encontrar la sucesi¢n m s corta de palabras
(es decir una que tiene el posible n£mero m s peque¤o de palabras) que
corresponde a un n£mero dado y una lista dada de palabras. La
correspondencia es descrita en el cuadro de arriba.

Entrada:

La primera l¡nea de archivo de entrada PHONE.IN contiene el n£mero
telef¢nico, la transcripci¢n de la que usted tiene que encontrar. El
n£mero consiste, a lo sumo, en 100 d¡gitos. La segunda l¡nea contiene
el n£mero total de las palabras en el diccionario (el m ximo es
50000). Cada uno de las l¡neas restantes contiene una palabra que
consiste, como m ximo, de 50 letras min£sculas del alfabeto ingl‚s. El
tama¤o total del archivo de entrada no excede los 300 KB.

Salida:

La £nica l¡nea de archivo de salida PHONE.OUT contiene la sucesi¢n m s
corta de palabras que han sido encontradas por su programa. Las
palabras est n separadas solo por espacios. Si no hay ninguna soluci¢n
a los datos de la entrada, la l¡nea contiene el texto 'No soluci¢n'.
Si hay m s soluciones que tienen el n£mero m¡nimo de palabras, usted
puede escoger cualquiera de ellas.

Ejemplo #1:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³PHONE.IN   ³³PHONE.OUT   ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³7325189087 ³³reality our ³
³5          ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³it         ³ Hay s¢lo una soluci¢n al archivo de la entrada PHONE.IN
³your       ³ escrita en el archivo de salida PHONE.OUT.(la pr¢xima
³reality    ³ posibilidad 'Real it your',  que corresponde al mismo
³real       ³ n£mero, es m s larga).
³our        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ

Ejemplo #2:

ÚÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³PHONE.IN  ³³PHONE.OUT  ³
ÃÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄ´
³4294967296³³No soluci¢n³
³5         ³ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³it        ³ Porque ninguna palabra dada contiene letras g y h que es
³your      ³ necesario para obtener el d¡gito 4.
³reality   ³
³real      ³
³our       ³
ÀÄÄÄÄÄÄÄÄÄÄÙ
}
{  Reinier Cesar  Free Pascal   Mochila}
const
 tec                    : string='22233344115566070778889990';
 max                    = 50002;
 cad                    = 102;

var
 fe,fs            : text;
 n,m,sol          : longint;
 num,ch           : string[cad];
 mk               : array[1..cad] of boolean;
 best,c           : array[0..cad] of longint;
 cont             : array[1..max] of byte;
 w,sav,cam        : array[1..max] of string[50];

procedure open;
var
 i,j,k            : longint;
begin
 assign(fe,'phone.in'); reset(fe);
 assign(fs,'phone.out'); rewrite(fs);
 readln(fe,num);
 m:=length(num);
 readln(fe,n);
 for i:=1 to n do
  begin
    readln(fe,ch);
    sav[i]:=ch;
    cont[i]:=length(ch);
    for j:=1 to cont[i] do
      begin
       k:=ord(ch[j]) - 96;
       w[i]:=w[i] + tec[k];
      end;
  end;
 close(fe);
end;

function comp(q,p : longint) : boolean;
var
 i                : longint;
begin
 for i:=1 to cont[p] do
  if (num[q+i-1] <> w[p,i]) then
   begin
    comp:=false;
    exit;
   end;
 comp:=true;
end;

procedure work;
var
 i,j              : longint;
begin
 fillchar(mk,sizeof(mk),false);
 fillchar(c,sizeof(c),127);
 mk[1]:=true; c[0]:=0;
 for i:=1 to m do
  if mk[i] then
   begin
   for j:=1 to n do
    begin
      if (cont[j] <= m - i + 1) and (comp(i,j))
       and (c[i+cont[j]-1] > c[i-1]) then
        begin
         mk[i+cont[j]]:=true;
         best[i+cont[j]-1]:=j;
         c[i+cont[j]-1]:=c[i-1] + 1;
        end;
    end;
  end;
end;

procedure closer;
var
 t                : longint;
begin
 sol:=0;
 t:=m;
 if best[t] = 0 then
  begin
   writeln(fs,'No solution.');
  end
 else
  begin
  while t > 0 do
   begin
    inc(sol);
    cam[sol]:=sav[best[t]];
    t:=t - cont[best[t]];
   end;
  for t:=sol downto 1 do write(fs,cam[t],' ');
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.
