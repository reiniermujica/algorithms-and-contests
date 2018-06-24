{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{17ş Olimpiada.                                            Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En un lejano planeta llamado ByteEath se realizar  en el a¤o 2008  una
extra¤a competencia que participar n todos los pa¡ses. La  competencia
consta de  M rondas,  donde en  cada ronda  se compite  en un  deporte
diferente aportando al pa¡s ganador una X cantidad de puntos, donde  x
puede tomar valores positivos o  negativos y puede ser diferente  para
cada  ronda.  Existe  una  organizaci¢n  que  es  quien  organiza este
prestigioso evento, en ella trabajan diversos analistas y ellos  est n
interesados  en  saber al  final  de cada  ronda  quien va  siendo  el
ganador. Los pa¡ses est n enumerados desde 1 hasta N. Si varios pa¡ses
est n empatados en una ronda se elige al pa¡s con menor ¡ndex.

Tarea

Escribe  un programa  que  dado  los pa¡ses  ganadores en  cada  ronda
le  informe   a los   analistas  quien  es  el   primer lugar   de  la
Olimpiada hasta esa ronda.

Entrada (Olimp.in)

En  la  primera l¡nea  del  fichero de  entrada  aparecen dos  enteros
separados por un simple espacio en blanco N y M respectivamente, 0 < N
<= 8000, 0 < M <= 50000. En las pr¢ximas M l¡neas aparecen dos enteros
separados por un simple espacio en blanco K y X, identificando al pa¡s
numero K y el valor X que se le asigna al pa¡s K.

-10000 <= X <= 10000, 1 <= K <= N
Nota : El 50% de los datos 0 < N <= 1000, 0 < M <= 2000.

Salida (Olimp.out)

En el fichero de  salida tienen que aparecer  M l¡neas, donde en  cada
l¡nea aparece un numero  que indica el ¡ndex  del pa¡s ganador en  esa
ronda.

Ejemplo de Entrada

Olimp.in
5 4
2 5
3 4
3 2
4 9

Olimp.out
2
2
3
4
 }

var
 fe,fs                  : text;
 n,m,aux,idx            : longint;
 a                      : array[1..8000] of longint;

procedure open;
begin
 assign(fe,'Olimp.in'); reset(fe);
 assign(fs,'Olimp.out'); rewrite(fs);
 readln(fe,n,m);
end;

procedure work;
var
 i,j,k,x                : longint;
begin
 aux:=0; idx:=0;
 for i:=1 to m do
  begin
   readln(fe,k,x);
   a[k]:=a[k] + x;
   if a[k] > aux then
    begin
     aux:=a[k];
     idx:=k;
     writeln(fs,k);
    end
    else
   if (a[k] = aux) and (idx > k) then
    begin
     idx:=k;
     writeln(fs,k);
    end
    else
     writeln(fs,idx);
  end;
 close(fs);
 close(fe);
end;

begin
 open;
 work;
end.