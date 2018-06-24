{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{
Un edificio tiene un largo corredor con L l mparas etiquetadas desde
1, 2, 3, ..., L. cada l mpara tiene un interruptor individual para
apagarla (off) o encenderla (on). Los encargados del edificio son G
guardias de seguridad (no dos  guardias tienen el mismo nombre), cuyo
trabajo por la noches es patrullar el corredor y verificar las
l mparas encendidas y apagadas. A cada guardia se le asigna un
subconjunto de l mparas. Durante una ronda, un guardia caminar  a lo
largo del corredor, y verifica las l mparas asignadas a  ‚l (es decir,
si una l mpara est  en on, el interruptor est  en off; si la l mpara
est  en off el interruptor est  en on). Despu‚s otro guardia verifica
cada l mpara asignada a ‚l exactamente una vez, el guardia no volver 
a patrullar hasta su pr¢xima ronda. Un guardia puede tener m s de
ronda en una noche. El orden de patrullar para los guardias es dictado
por una lista de nombres.

Todas las l mparas est n en off antes que los guardias comiencen hacer
su ronda, y solo un guardia patrulla en cualquier momento.

La asignaci¢n  de las l mparas para los guardia es especificado por
dos  enteros positivos, a0 y d. El subconjunto de l mparas de los
guardias se verificar como:
         a0, a0 + d, a0 + 2d, ..., a0 + kd
donde k es el entero m s largo tal que a0 + kd = L.

Dado la asignaci¢n de l mparas parar cada guardia y la lista de
nombres, encuentre  cu ntas l mparas hay encendida despu‚s que todos
los guardias han terminado todas sus rondas.

Ejemplo

Supongamos que hay 10 l mparas, dos  guardias de seguridad (Edi y
Lou), y tres rondas de patrulla. Las l mparas asignadas a Edi's es
(a0, d) = (1, 4) y las l mparas asignadas a Lou's es (a0, d) = (2, 3).
El orden de patrullar es Edi, Lou, Edi.

Despu‚s de la primera ronda por Edi, las l mparas 1, 5, y 9 son
encendidas. Durante la segunda ronda, Lou verifica las l mparas 2, 5,
y 8. Por consiguiente en la segunda ronda, las l mparas 1, 2, 8, y 9
est n en on pero la l mpara 5 cambia su estado a off. En la tercera
ronda, Edi patrulla de nuevo, y verifica las l mparas 1, 5, y 9.
Consecuentemente, despu‚s de todas las rondas especificadas por la
lista de nombres, las l mparas que quedan en on son 2, 5, y 8.

El n£mero de l mparas que quedan en on despu‚s que todos los guardias
terminan sus rondas es 3.

Entrada

La primera l¡nea del fichero de entrada LAMP.IN consiste de tres
enteros positivos, separados por un caracter espacio. El primer n£mero
L <= 10000 es el n£mero de l mparas. El segundo n£mero G <= 100 es el
n£mero de guardias de seguridad, y el tercer n£mero R <= 1000 es el
n£mero total de rondas. Las pr¢ximas G l¡neas contienen los nombre y
l mpara asignadas a los guardias. Cada una de estas G l¡neas consisten
en el nombre (exactamente 3 letras en el alfabeto ingles), a0 y d, (a0
= N) separado con un espacio. Las siguientes R l¡neas especifican la
lista de nombres a patrullar. Cada l¡nea continene el nombre de un
guardia (se garantiza que todos tienen l mparas asignadas). El orden
de los guardias aparecer  en la lista de nombres dictada en el orden
de patrullar.

Salida

El fichero de salida LAMP.OUT contiene un entero el cual es el n£mero
de l mparas que quedan encendidas despu‚s de todas las rondas de los
guardias

Entrada/Salida Ejemplo

Para el ejemplo de arriba la entrada y salida son los siguientes

Ejemplo Entrada
                10 2 3
                Edi 1 4
                Lou 2 3
                Edi
                Lou
                Edi
Ejemplo Salida
                3     }

var
 fe,fs                    : text;
 l,g,r,sol                : longint;
 nam                      : array[1..1000] of string[3];
 ak                       : array[1..1000,1..2] of longint;
 lamp                     : array[1..40000] of boolean;

procedure open;
var
 t                        : longint;
begin
 assign(fe,'lamp.in'); reset(fe);
 assign(fs,'lamp.out'); rewrite(fs);
 readln(fe,l,g,r);
 for t:=1 to g do readln(fe,nam[t],ak[t,1],ak[t,2]);
end;

function search(x : string):longint;
var
 t                : longint;
begin
 for t:=1 to g do
  if nam[t]=x then
   begin
    search:=t;
    exit;
   end;
end;

procedure work;
var
 i,j,k,a0,d,h             : longint;
 St                       : string;
begin
 sol:=0;
 for i:=1 to r do
  begin
   readln(fe,St);
   j:=search(St);
   a0:=ak[j,1]; d:=ak[j,2]; h:=0;
   repeat
    begin
     k:=a0+(h*d);
     lamp[k]:=not lamp[k];
     inc(h);
    end;
   until k>=l;
  end;
 for i:=1 to l do
  if lamp[i] then inc(sol);
end;

procedure closer;
var
 t                      : longint;
begin
 close(fe);
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.