 {$I-,Q-,R-,S-}

{ 9ş Nets                                                  Turqu¡a 1999
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Cierta   cantidad   de   escuelas   est n    conectadas   a  una  red
 de   computadoras.  Se    han    establecido   acuerdos  entre  estas
 escuelas: cada  escuela  mantiene  una  lista  de las escuelas a  las
 cuales les distribuye software  nuevo (llamadas escuelas receptoras).
 Nota  que si B est   en  la lista de distribuci¢n de  la  escuela  A,
 entonces A no necesariamente aparece en la lista de le escuela B.

 Escribe  un   programa  que  calcule  el  n£mero m¡nimo  de  escuelas
 que  deben  recibir  una  copia  del  software  nuevo  para  que ‚ste
 llegue  a  todas  las  escuelas  en  la  red siguiendo  los  acuerdos
 (subtarea A). Como  una  tarea  adicional, queremos asegurar que  con
 el  env¡o	de una copia del software nuevo a una  escuela arbitraria,
 este  software  llegar  a todas las escuelas en	la red. Para	lograr
 este   objetivo   podr¡a   ser   necesario   extender  la  listas  de
 receptoras  con  nuevos   miembros.  Calcula  el  n£mero   m¡nimo  de
 extensiones que se deben de hacer  de  tal forma que, sin  importar a
 qu‚ escuela le enviemos el  software nuevo, ‚ste  llegar  a todas las
 escuelas (subtarea B).  Una  extensi¢n  significa introducir un nuevo
 miembro a la lista de receptoras de una escuela.

 DATOS DE ENTRADA

 La  primer  l¡nea  del  archivo  INPUT.TXT contiene al entero N: el
 n£mero de escuelas  en  la  red (2 <= N <= 100). Las  escuelas  est n
 identificadas por los  primeros N enteros positivos. Cada una de las
 siguientes  N  l¡neas describe una lista de receptoras. La l¡nea  i+1
 contiene  los  identificadores  de  las  receptoras  de la escuela i.
 Todas las  listas  terminan   con  un  0.  Una  lista  vac¡a contiene
 £nicamente  un  0 en la l¡nea.

 DATOS DE SALIDA

 Tu programa debe escribir dos l¡neas  en  el  archivo	OUTPUT.TXT.
 La primer l¡nea debe contener un entero  positivo: la soluci¢n de  la
 subtarea A. La segunda l¡nea debe contener la soluci¢n de la subtarea
 B.

 EJEMPLO DE ENTRADA Y SALIDA

 La figura 1 muestra un posible archivo de entrada y el correspondiente
 archivo de salida.

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿	ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ INPUT.TXT ³	³ OUTPUT.TXT ³
 ³ÄÄÄÄÄÄÄÄÄÄÄ³	³ÄÄÄÄÄÄÄÄÄÄÄÄ³
 ³ 5				 ³	³ 1 				 ³
 ³ 2 4 3 0	 ³	³ 2 				 ³
 ³ 4 5 0		 ³	ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 0				 ³
 ³ 0				 ³
 ³ 1 0			 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ

 }

{ Fuertemente Conexas (SCC) }

const
 mx            = 101;

var
 fe,fs         : text;
 n,sa,sb,act   : longint;
 tab           : array[1..mx,1..mx] of boolean;
 comp          : array[1..mx] of longint;
 mk,mark       : array[1..mx,1..2] of boolean;

procedure open;
var
 i,j           : longint;
begin
 assign(fe,'input.txt'); reset(fe);
 assign(fs,'output.txt'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   read(fe,j);
   while j <> 0 do
    begin
     tab[i,j]:=true;
     read(fe,j);
    end;
   readln(fe);
  end;
end;

procedure dfsh(x : longint);
var
 i               : longint;
begin
 mk[x,1]:=true;
 for i:=1 to n do
  if (not mk[i,1]) and (tab[x,i]) then
   dfsh(i)
end;

procedure dfsp(x : longint);
var
 i               : longint;
begin
 mk[x,2]:=true;
 if (mk[x,1]) then comp[x]:=act;
 for i:=1 to n do
  if (not mk[i,2]) and (tab[i,x]) then
   dfsp(i)
end;

procedure work;
var
 i,j,ch,cp     : longint;
begin
 act:=0; ch:=0; cp:=0;
 for i:=1 to n do
  begin
   if (comp[i] = 0) then
    begin
     fillchar(mk,sizeof(mk),false);
     inc(act);
     comp[i]:=act;
     dfsh(i);
     dfsp(i);
     for j:=1 to n do
      if (mk[j,1]) and (not mk[j,2]) then
       mark[act,1] := true
       else
      if (not mk[j,1]) and (mk[j,2]) then
       mark[act,2]:=true;
    end;
  end;
  for i:=1 to act do
   begin
    if not mark[i,1] then inc(cp);
    if not mark[i,2] then inc(ch);
   end;
  if act > 1 then
   if cp > ch then sb:=cp
              else sb:=ch;
  sa:=ch;
end;

procedure closer;
begin
 writeln(fs,sa);
 writeln(fs,sb);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.