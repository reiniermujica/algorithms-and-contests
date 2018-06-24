{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{68ş Agentes.                                            Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Por  el  £ltimo  contratiempo  de  sus  agentes, la Agencia Central de
Inteligencia  de Byteland resolvi¢ mejorar su actividad. As¡ que lejos
del  gran  disgusto en que ha estado una preparaci¢n de reuni¢n segura
de  agentes.  Su  programa  tiene que ayudar a resolver esto. Para una
descripci¢n  dada  de  la  red de carreteras en Byteland y la posici¢n
inicial  de  dos  agentes,  el  programa  debe responder si su reuni¢n
segura  es  posible.  Para  considerar  una reuni¢n segura los agentes
tienen que estar sujetos a las siguientes precausiones:

- los agentes se mueven durante el d¡a y la reuni¢n tiene lugar en la
  noche,

- un agente tiene que cambiar su lugar de permanencia cada d¡a,

- los  agentes  pueden  viajar  solamente  a  trav‚s de las carreteras
  conectando  ciudades (desafortunadamente otra inconveniente es que
  en Byteland hay carreteras de un solo sentido),

- un  agente  no  puede  moverse  muy  r pido (este puede  parecer muy
  sospechozo)  durante un d¡a, ‚l no puede viajar m s que a una ciudad
  vecina,

- la  distancia  entre  dos  ciudades  conectadas  es tan corta que un
  agente  sale  de  una  ciudad  en  la ma¤ana y alcanza la otra en la
  noche,

- una  reuni¢n  es  indicada  para  hacerla si dos agentes est n en la
  misma ciudad en la misma noche.

Tarea

Escriba un programa que:

.  Lea  el n£mero de ciudades y la descripci¢n de la red de carreteras
  de  Byteland y la posici¢n de inicio de los agentes desde un fichero
  de texto AGE.IN.

.  Chequee  si hay una reuni¢n, si es as¡, entonces cu ntos d¡as toman
  para reunirse estos.

. Escriba el resultado para el fichero texto AGE.OUT.

Entrada

En la primera l¡nea del fichero AGE.IN hay dos enteros N y M separados
por  un  simple  espacio, donde 1 <= N <= 250, 0 <= M <= N(N-1). En la
segunda  l¡nea  hay  dos  enteros  a1  y  a2  separdos por un espacio,
1  <=  a1,  a2  <=  N y a1 <> a2 denotando respectivamente la posici¢n
inicial  de  los agentes #1 y #2. En las M siguientes l¡neas hay pares
de  n£meros  naturales a y b separdos por un espacio, 1 <= a, b <= N y
a <> b denotando que  una  carretera desde la ciudad a hasta la ciudad
b.

Salida

Debe  ser  exactamente una l¡nea en el fichero de texto AGE.OUT y debe
contener:

. Exactamente un entero positivo el cual es el m¡nimo timepo (en d¡as)
  necesario para reunirse los dos agentes -si tal reuni¢n es pasible.

. La palabra 'NO' -si tal reuni¢n no es posible.

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ AGE.IN     ³  ³ AGE.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 6 7        ³  ³ 3       ³
³ 1 5        ³  ÀÄÄÄÄÄÄÄÄÄÙ
³ 1 2        ³
³ 4 5        ³
³ 2 3        ³
³ 3 4        ³
³ 4 1        ³
³ 5 4        ³
³ 5 6        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}

const
 max                 = 250;

var
 fe,fs               : text;
 n,a1,a2             : byte;
 m,day               : longint;
 sav                 : array[boolean,1..2,1..max] of byte;
 tab                 : array[1..max,1..max] of byte;
 cont                : array[1..max] of byte;
 mk                  : array[1..2,1..max] of boolean;

procedure open;
var
 i                   : longint;
 k,c                 : byte;
 buff                : array[1..64000] of byte;
begin
 assign(fe,'age.in'); reset(fe);
 assign(fs,'age.out'); rewrite(fs);
 settextbuf(fe,buff);
 readln(fe,n,m);
 readln(fe,a1,a2);
 for i:=1 to m do
  begin
   read(fe,k,c);
   inc(cont[k]);
   tab[k,cont[k]]:=c;
   readln(fe);
  end;
 close(fe);
end;

procedure closer(x : longint);
begin
 if x=0 then
  writeln(fs,'NO')
 else
  writeln(fs,x);
 close(fs);
 halt;
end;

procedure bfs;
var
 i,j,h1,h2           : byte;
 cp1,ch1,cp2,ch2     : byte;
 s,q                 : boolean;
 mka                 : array[1..max,1..max] of boolean;
begin
 s:=true; cp1:=1; cp2:=1; day:=0;
 sav[s,1,1]:=a1; sav[s,2,1]:=a2;
 fillchar(mka,sizeof(mka),false);
 while (cp1 > 0) and (cp2 > 0) do
  begin
   ch1:=0; ch2:=0;
   inc(day);
   fillchar(mk,sizeof(mk),false);
   for i:=1 to cp1 do  {agent 1}
    begin
     h1:=sav[s,1,i];
     for j:=1 to cont[h1] do
      begin
       h2:=tab[sav[s,1,i],j];
       if not mk[1,h2] then
        begin
         inc(ch1);
         sav[not s,1,ch1]:=h2;
         mk[1,h2]:=true;
        end;
      end;
    end;               {end agent 1}
   for i:=1 to cp2 do  {agent 2}
    begin
     h1:=sav[s,2,i];
     for j:=1 to cont[h1] do
      begin
       h2:=tab[sav[s,2,i],j];
       if not mk[2,h2] then
        begin
         inc(ch2);
         sav[not s,2,ch2]:=h2;
         mk[2,h2]:=true;
        end;
      end;
    end;                {end agent 2}
   cp1:=ch1;
   cp2:=ch2;
   s:=not s;
   for i:=1 to cp1 do  {si se encuentran}
    begin
    q:=false;
    for j:=1 to cp2 do
     begin
      if (mka[sav[s,1,i],sav[s,2,j]]=false) then
       q:=true;
      if sav[s,1,i] = sav[s,2,j] then
       closer(day);
      mka[sav[s,1,i],sav[s,2,j]]:=true;
      mka[sav[s,2,j],sav[s,1,i]]:=true;
     end;
    if not q then
     begin
      sav[s,1,i]:=sav[s,1,cp1];
      dec(cp1);
     end;              {end encuentran}
    end;
  end; {end bfs}
end;

begin
  open;
  bfs;
  closer(0);
end.
