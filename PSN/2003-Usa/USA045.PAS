{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{þ Kola.

En  un  cuarto  hay    M    botellas rellenas con una bebida sumamente
popular y de  buen gusto,  llamada Kola. Cada una de las botellas est 
marcada  por uno de los n£meros 1, 2, 3, ... M, y no hay ning£n par de
botellas marcadas con el mismo n£mero.

Una    cola  (muy  popular  en  nuestro  pa¡s)  consiste en N personas
sedientas  que forman en la puerta  de entrada al cuarto. Cada persona
tiene asignado un de n£mero 1,  2,  3, ...  N,  y de nuevo, ning£n par
de  ellas  tiene el mismo n£mero.  Todos ellos esperan para beber Kola
de una de las botellas en el cuarto. Uno por  uno, organizados por sus
n£meros  (la  persona  que  se le asign¢  el n£mero 1 es el primero en
entrar,  el  pr¢ximo  es  la  persona  que  se  le asign¢ el n£mero 2,
etc.),  entran en el cuarto, beben un decilitro  de Kola de una de las
botellas  en el cuarto y entonces se marchan. No m s de una persona se
permite  estar  en  el cuarto en cualquier momento. Hay dos  tipos  de
personas:    malgastadoras y  econ¢micas.  Las  personas malgastadoras
siempre  beben  de  una  de las botellas  m s  llenas.  Los econ¢micos
siempre    beben de una de las botellas  menos  llenas  (por supuesto,
las botellas vac¡as son ignoradas). Es conocido cu nta  Kola permanece
en  cada botella despu‚s de que la £ltima persona  dej¢  el cuarto.

Tarea

Usted    necesita escribir un programa que determine qu‚ persona bebi¢
de cada botella.

Entrada

La  primera l¡nea del fichero de entrada COLA.IN contiene tres enteros
N,  M  y K,  1  <=  N  <= 1000, 1 <= M <= 100, 1 <= K <= 20, el n£mero
de   las personas  en  la  cola, el n£mero de botellas en el cuarto  y
cu ntos  decilitros      de   Kola   estaban  inicialmente   en   cada
botella,  respectivamente. Se asignan a las personas los n£meros del 1
al    N  y las  botellas  se  marcan por n£meros del 1 al  M  como  se
describi¢  anteriormente.  La   segunda  l¡nea  del fichero de entrada
contiene   una  sucesi¢n  de caracteres  'R'  y  'S' de longitud N. El
car cter de  la  posici¢n  i describe a la persona i-esima: 'R' denota
a  la  persona  malgastadora   y 'S' denota a la persona econ¢mica. La
tercera (y £ltima l¡nea) del fichero de entrada contiene M enteros que
denotan    los    vol£menes (en decilitros) que  quedaron de  Kola  en
las    botellas  correspondientes:  el k-‚simo n£mero corresponde a la
botella    k-‚sima.  Los    n£meros  adyacentes  son  separados por un
espacio. Cada uno de esos M enteros son del conjunto (0, 1, 2... K).

Salida

La    primera    y  £nica  l¡nea del fichero de  salida  COLA.OUT debe
contener   N enteros;  el i-esimo n£mero es el n£mero de botella de la
persona    i-  esima  que bebi¢ Kola. Dos n£meros adyacentes deben ser
separados  por un espacio.

Ejemplos de Entrada y Salida:

     Ejemplo  #  1         Ejemplo # 2             Ejemplo # 3
ÚÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³COLA.IN³³ COLA.OUT ³ ³COLA.IN³³ COLA.OUT ³ ³ COLA.IN   ³³ COLA.OUT  ³
ÃÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 3 3 ³³ 2 2 2 3  ³ ³ 4 3 3 ³³ 2 2 3 2  ³ ³ 5 5 2     ³³ 3 3 5 1 5 ³
³ SSSS  ³ÀÄÄÄÄÄÄÄÄÄÄÙ ³ SSRS  ³ÀÄÄÄÄÄÄÄÄÄÄÙ ³ SSRRS     ³ÀÄÄÄÄÄÄÄÄÄÄÄÙ
³ 3 0 2 ³             ³ 3 0 2 ³             ³ 1 2 0 2 0 ³
ÀÄÄÄÄÄÄÄÙ             ÀÄÄÄÄÄÄÄÙ             ÀÄÄÄÄÄÄÄÄÄÄÄÙ

Nota:  Habr  siempre una soluci¢n, no necesariamente £nica, para todos
los juegos de datos de prueba.
}
var
 fe,fs           : text;
 n,m,k           : longint;
 res,bot,ide,r   : array[1..1001] of longint;
 per             : array[1..1001] of char;

procedure open;
var
 t               : longint;
begin
 assign(fe,'cola.in'); reset(fe);
 assign(fs,'cola.out'); rewrite(fs);
 readln(fe,n,m,k);
 for t:=1 to n do read(fe,per[t]);
 readln(fe);
 for t:=1 to m do
  begin
   read(fe,bot[t]);
   res[t]:=k;
  end;
end;

function findmax : longint;
var
 i,aux,best      : longint;
begin
 aux:=0;
 for i:=1 to m do
  if (res[i] > aux) then
   begin
    aux:=res[i];
    best:=i;
   end;
 findmax:=best;
end;

function findmin : longint;
var
 i,aux,best      : longint;
begin
 aux:=maxlongint;
 for i:=1 to m do
  if (res[i] < aux) and (res[i] > 0) then
   begin
    aux:=res[i];
    best:=i;
   end;
 findmin:=best;
end;

procedure swap(var n1,n2 : longint);
var
 t                       : longint;
begin
 t:=n1;
 n1:=n2;
 n2:=t;
end;

procedure qsort(ini,fin : longint);
var
 i,j,k                  : longint;
begin
 i:=ini; j:=fin; k:=bot[(i+j) div 2];
 repeat
  while bot[i] < k do inc(i);
  while bot[j] > k do dec(j);
  if i<=j then
   begin
    swap(bot[i],bot[j]);
    swap(ide[i],ide[j]);
    inc(i); dec(j);
   end;
 until i>j;
 if i < fin then qsort(i,fin);
 if j > ini then qsort(ini,j);
end;

procedure work;
var
 i,k             : longint;
begin
 for i:=1 to m do ide[i]:=i;
 qsort(1,m);
 for i:=1 to n do
  begin
   if per[i] = 'S' then
    begin
     k:=findmin;
     dec(res[k]);
    end
   else
    begin
     k:=findmax;
     dec(res[k]);
    end;
   r[i]:=ide[k];
  end;
end;

procedure closer;
var
 t              : longint;
begin
 for t:=1 to n do write(fs,r[t],' ');
 close(fs);
end;

begin
 open;
 work;
 closer;
end.