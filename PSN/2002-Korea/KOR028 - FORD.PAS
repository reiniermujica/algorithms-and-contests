 {$I-,Q-,R-,S-}

{28� Diga Cheese                                             Korea 2002
----------------------------------------------------------------------

Hab�a  una  vez    un pedazo grande de queso, viv�a en �l un �caro del
queso llamada Amelia Acaro del Queso. Amelia estaba realmente contenta
porque ella estaba rodeada por los m�s deliciosos quesos que ella pudo
haber comido. Sin embargo, ella sent�a que hab�a algo que le faltaba a
su vida.

Una  ma�ana,  meintras so�aba con quesos fue interrumpida por un ruido
que  jam�s  hab�a oido. Pero ella inmediatamente se da cuenta que esto
era  el  sonido de un �caro de queso macho rullendo en el mismo pedazo
de  queso!  (determinando  el  g�nero del �caro del queso justo por el
sonido  de esta rodeadura no es un m�todo f�cil, pero todos los �caros
de queso lo pueden hacer. Esto es porque sus padres lo hacen).

Nada  puede  detener  a  Amelia  ahora.  Ella ten�a que conocer lo m�s
pronto  posible  al  �caro.  Por  lo tanto ella tiene que encontrar el
camino  m�s  r�pido  para  llegar  al  otro  �caro. Amelia puede roer
complemante  un  1  mm de queso en diez segundos. Para reunirse con el
otro  �caro por el camino directo puede no ser r�pido. El queso en que
Amelia  vive  est�  lleno  de  huecos.  Estos  huecos,  los cuales son
burbujas  de  aire  atrapados  en el queso son esf�ricos para la mayor
parte.  Pero  ocasionalmente  estos  huecos  esf�ricos  se superponen,
creando  huecos  compuestos de todos los tipos. Pasando a trav�s de un
hueco  en  el queso Amelia toma un tiempo esencialmente cero, dado que
ella  puede  volar desde un extremo al otro inst�ntaneamente. As� ella
puede  aprovechar  viajar a trav�s de huecos para llegar al otro �caro
r�pidamente.

Para    este  problema,  usted  escribir�  un  programa  que  dado  la
localizaci�n  de  ambos �caros y los huecos en el queso, determinar el
menor  tiempo  que  se  toma  Amelia para alcanzar al otro �caro. Para
resolver este problema, usted puede asumir que el queso tiene un largo
infinito.  Esto es porque el queso es tan largo como nunca permita que
Amelia  abandone  el  queso  al  alcanzar el otro �caro (especialmente
puesto  que  el  �caro de queso comil�n pueda comersela a ella). Usted
tambi�n  puede  asumir que el otro �caro espera ansiosamente el arribo
de Amelia y no se mover� mientras que Amelia est� en el camino.

Entrada

La  entrada  es  mediante el fichero texto ACARO.IN con la descripci�n
siguiente:

. La  primera  l�nea contiene un  simple entero N (0 <= N <= 100) , el
  n�mero  de  huecos  en  el  queso.  En las siguientes N l�neas hay 4
  enteros separados por un espacio en blanco cada uno Xi, Yi, Zi y Ri.
  Estos describen el centro (Xi, Yi, Zi) y el radio Ri (Ri > 0) de los
  huecos.  Todos  los  valores  est�n  expresados  en  mil�metros.  La
  descripci�n concluye con dos l�neas conteniendo 3 enteros cada una.
  La  primera  l�nea  contiene los valores Xa, Ya y Za; la posici�m de
  Amelia  en  el queso, la segunda l�nea contiene los valores Xb, Yb y
  Zb las posiciones del otro �caro.

Salida

La  salida  es hacia el fichero texto ACARO.OUT con una sola l�nea con
un  solo  valor  entero que representa el menor tiempo en segundos que
toma Amelia en llegar al otro �caro, redondeado al entero cercano.

Ejemplos de Entrada y Salida:

  Ejemplo #1                      Ejemplo  #2
 +------------+ +-----------+    +----------+ +-----------+
 � ACARO.IN   � � ACARO.OUT �    � ACARO.IN � � ACARO.OUT �
 +------------� +-----------�    +----------� +-----------�
 � 1          � � 100       �    � 1        � � 20        �
 � 20 20 20 1 � +-----------+    � 5 0 0 4  � +-----------+
 � 0 0 0      �                  � 0 0 0    �
 � 0 0 10     �                  � 10 0 0   �
 +------------+                  +----------+
}

{ Ford }

const
 max               = 102;

var
 fe,fs             : text;
 n,i,j             : byte;
 k                 : real;
 a                 : array[1..max,1..4] of integer;
 cost              : array[1..max,1..max] of real;
 d                 : array[0..max] of real;

procedure open;
begin
 assign(fe,'acaro.in'); reset(fe);
 assign(fs,'acaro.out'); rewrite(fs);
 readln(fe,n);
 for i:=2 to n+1 do
  readln(fe,a[i,1],a[i,2],a[i,3],a[i,4]);
 readln(fe,a[1,1],a[1,2],a[1,3]);
 n:=n+2;
 readln(fe,a[n,1],a[n,2],a[n,3]);
 close(fe);
end;

function dist(x,y,z,k,x1,y1,z1,k1 : real) : real;
var
 r1,r2,r3,best                    : real;
begin
 r1:=abs(x-x1); r2:=abs(y-y1); r3:=abs(z-z1);
 best:=sqrt(sqr(r1)+sqr(r2)+sqr(r3));
 best:=best-k-k1;
 if best > 0 then dist:=best
 else dist:=0;
end;

procedure calcula;
begin
 for i:=1 to n do
  for j:=1 to i-1 do
   begin
    k:=dist(a[i,1],a[i,2],a[i,3],a[i,4],a[j,1],a[j,2],a[j,3],a[j,4]);
    cost[i,j]:=k;
    cost[j,i]:=k;
   end;
end;

procedure ford(ini : byte);
var
 cp,ch,x           : byte;
 sav               : array[boolean,1..max] of byte;
 s                 : boolean;
 mk                : array[1..max] of boolean;
begin
 d[ini]:=0; s:=true; cp:=1;
 sav[s,1]:=1; ch:=0;
 while cp > 0 do
  begin
   fillchar(mk,sizeof(mk),false);
   for i:=1 to cp do
    begin
     x:=sav[s,i];
     for j:=1 to n do
       begin
        k:=cost[x,j] + d[x];
        if d[j] > k then
         begin
          d[j]:=k;
          if not mk[j] then
           begin
            mk[j]:=true;
            inc(ch);
            sav[not s,ch]:=j;
           end;
         end;
       end;
    end;
    cp:=ch;
    ch:=0;
    s:=not s;
  end;
end;

procedure work;
begin
 calcula;
 for i:=1 to n do
  d[i]:=500000;
 ford(1);
end;

procedure closer;
begin
 writeln(fs,d[n]*10:0:0);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.
