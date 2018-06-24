  {$I-,Q-,R-,S-}

{1ş Pal¡ndrome                                           Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  pal¡ndrome  es  una  cadena  sim‚trica,  tal  que  se  pueda  leer
id‚nticamente de derecha a izquierda como de izquierda a derecha.
Usted  debe  escribir  un  programa  que dada una cadena, determine la
m¡nima  cantidad  de  caracteres  que  se debe agregar para obtener un
pal¡ndrome.

Como ejemplo, insertando dor caracteres en la cadena "Ab3bd" puede ser
transformada en una cadena pal¡ndrome ("dAb3bAd") o ("Adb3bdA").
Cualquier insersi¢n menor de dos caracteres no produce una pal¡ndrome.

Entrada:

El fichero de entrada se nombra PALIN.IN. La primera l¡nea contiene un
entero:  la  longitud  de  la cadena N, 3 <= N <= 5000. La cadena esta
formada  por  letras may£sculas desde 'A' hasta 'Z', letras min£sculas
desde  'a' hasta 'z'y d¡gitos desde '0' a '9'. Las letras may£sculas y
min£sculas se consideran distintas.

Salida:

El fichero de salida se nombra PALIN.OUT. La primera l¡nea contiene un
entero el cual es considerado el n£mero m¡nimo.

 ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
 ³PALIN.IN³ ³PALIN.OUT³
 ÃÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
 ³ 5      ³ ³ 2       ³
 ³ Ab3bd  ³ ÀÄÄÄÄÄÄÄÄÄÙ
 ÀÄÄÄÄÄÄÄÄÙ
 }

const
 mx               = 50001;

var
 fe,fs            : text;
 n,sol            : longint;
 cad              : array[1..mx,1..2] of char;
 tab              : array[boolean,0..mx] of longint;

procedure open;
var
 i,k              : longint;
begin
 assign(fe,'palin.in'); reset(fe);
 assign(fs,'palin.out'); rewrite(fs);
 readln(fe,n);
 k:=n+1;
 for i:=1 to n do
  begin
   read(fe,cad[i,1]);
   dec(k);
   cad[k,2]:=cad[i,1];
  end;
 close(fe);
end;

procedure work;
var
 i,j              : longint;
 s                : boolean;
begin
 s:=false;
 for i:=1 to n do
  begin
   s:=not s;
   for j:=1 to n do
    begin
     if (cad[i,1] = cad[j,2]) then
      tab[s,j]:=tab[not s,j-1] + 1
     else
      begin
       if (tab[not s,j] > tab[s,j-1]) then
        tab[s,j]:=tab[not s,j]
         else
        tab[s,j]:=tab[s,j-1];
      end;
    end;
  end;
 sol:=tab[s,n];
end;

procedure closer;
begin
 writeln(fs,n-sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.