 {$I-,Q-,R-,S-}

{49� Las Torres Gemelas.                                    M�xico 2006
----------------------------------------------------------------------

Habia una vez, en un antiguo Imperio, dos  torres de formas  similares
en dos ciudades diferentes.  Las torres estaban construidas  por losas
circulares puestas unas sobre las otras. Cada una de las losas era  de
la  misma  altura  y  tenian  radio  completo.  Sin  embargo,  no   es
sorprendente  que  las dos  torres  fueran de  forma  diferente, ellas
ten�an muchas losas en comun.

Sin embargo,  mas de  mil a�os  despu�s que ellas  fueron construidas,
el Emperador orden�  a sus arquitectos  eliminar algunas de  las losas
de las dos torres tal que ellas tengan la misma forma y tama�o,  y  al
mismo tiempo  permanezcan  tal altas  como  sea posible.  El  orden de
las losas en la nueva torre tiene que ser el mismo que ellas tenian en
la torre  original. El  emperador pens�  que, de  esta manera  las dos
torres ser�an el simbolo de armonia e igualdad entre las dos ciudades.
El decidi� nombrarlas a ellas las Torres Gemelas

Ahora, alrededor  de dos  mil a�os  despu�s, a usted  se le  reta  con
un  simple  problema  de aplanamiento:  dada  la  descripci�n  de  dos
torres diferentes a usted se  le pide  solamente  encontrar el  n�mero
de   losas  en  la  m�s  alta  de  las torres  gemelas  que  puede ser
construida desde ellas.

Entrada

El  fichero  de entrada  TOWER.IN  contiene en  la  primera l�nea  dos
enteros N1  y  N2  (1  <=   N1, N2  <=  1000)  indicando el  numero de
losas  respectivamente   en   las   dos   torres.  La   segunda  linea
contiene   N1 enteros  positivos  los  que  representan   el  radio de
las losas  (de arriba hacia  debajo) en  la primera  torre. La tercera
linea  contiene  N2  enteros positivos   los   que    representan   el
radio de las  losas (de arriba hacia  debajo) en   la segunda torre.

Salida

El fichero de entrada TOWER.OUT el n�mero de losas en la torre (en una
torre) en la posible torre gemela m�s alta que puede ser construida
de ella.

Ejemplo de Entrada y de Salida

Ejemplo # 1

+----------------------+ +------------+
� TOWER.IN             � � TOWER.OUT  �
+----------------------� +------------�
� 7 6                  � � 4          �
� 20 15 10 15 25 20 15 � +------------+
� 15 25 10 20 15 20    �
+----------------------+

Ejemplo # 2

+----------------------------+ +-----------+
� TOWER.IN                   � � TOWER.OUT �
+----------------------------� +-----------�
� 8 9                        � � 6         �
� 10 20 20 10 20 10 20 10    � +-----------+
� 20 10 20 10 10 20 10 10 20 �
+----------------------------+

 }

const
 mx                 = 1001;

var
 fe,fs              : text;
 n,m,sol            : longint;
 tab                : array[1..mx,1..2] of longint;
 best               : array[boolean,0..mx] of longint;

procedure open;
var
 i                  : longint;
begin
 assign(fe,'tower.in'); reset(fe);
 assign(fs,'tower.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to n do read(fe,tab[i,1]);
 readln(fe);
 for i:=1 to m do read(fe,tab[i,2]);
 close(fe);
end;

procedure work;
var
 i,j                : longint;
 ok                 : boolean;
begin
 ok:=false;
 for i:=1 to n do
  begin
   ok:=not ok;
   for j:=1 to m do
    begin
     if (tab[i,1] = tab[j,2]) then
      best[ok,j]:=best[not ok,j-1] + 1
     else
      if best[ok,j-1] > best[not ok,j] then
       best[ok,j]:=best[ok,j-1]
      else
       best[ok,j]:=best[not ok,j];
    end;
  end;
  sol:=best[ok,m];
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.