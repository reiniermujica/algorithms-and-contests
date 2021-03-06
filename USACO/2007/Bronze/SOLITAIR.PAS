 {$I-,Q-,R-,S-}

{Problema 11: Solitario Vacuno [Rob Kolstad, 2007]

El fin del verano en la granja es un tiempo lento, muy lento. Betsy tiene
poco que hacer aparte de jugar solitario. Por razones evidentes, el
solitario vacuno no es tan desafiante como un n�mero de juegos de
solitario jugado por humanos.

El solitario vacuno es jugado usando un arreglo N x N (3 <= N <= 7) de
cartas normales con cuatro palos (Tr�boles(C), Diamantes(D),
Corazones(H), y Espadas(S)) de 13 cartas (As, 2, 3, 4,..., 10(T),
Sota(J), Reina(Q), Rey(K)). Las cartas son nombradas con dos caracteres:
su valor (A, 2, 3, 4,...,9, T, J, Q, K) seguido de su palo (C, D, H, S).
Aqu� hay un arreglo t�pico cuando N=4:

     8S AD 3C AC     (Ocho de Espadas, As de Diamantes, etc.)
     8C 4H QD QS
     5D 9H KC 7H
     TC QC AS 2D

Para jugar este juego de solitario, Betsy comienza en la esquina inferior
izquierda (TC) y procede usando exactamente 2*N-2 movimientos de
'derecha' o 'arriba' para la esquina superior derecha. A trav�s del
camino ella acumula puntos por cada carta (el As vale 1 punto, el 2 vale
2 puntos,..., el 9 vale 9 puntos, la T vale 10 puntos, J vale 11, Q vale
12, y K vale 13) conforme va haciendo el recorrido. Su prop�sito es
obtener el m�s alto puntaje.

Si el camino de Betsy hubiera sido TC-QC-AS-2C-7H-QS-AC, su puntaje
habr�a sido 10+12+1+2+7+12+1=45. Si ella hubiera tomado el lado izquierdo
y luego hacia arriba (TC-5D-8C-8S-AD-3C-AC), su puntaje habr�a sido
10+5+8+8+1+3+1=36, no tan bueno como con la otra ruta. El mejor puntaje
para este arreglo es 69 puntos TC-QC-9H-KC-QD-QS-AC =>
10+12+9+13+12+12+1).

Betsy quiere conocer el mejor puntaje que ella puede obtener. Una de las
vacas sabias una vez le dijo a ella algo acerca de �trabajar del final
hacia el comienzo�, pero ella no entendi� lo que esta vaca le dec�a.

NOMBRE DEL PROBLEMA: solitair

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero N.

* L�neas 2..N+1: La l�nea i+1 tiene una lista de las cartas de la fila i
(la fila 1 es
         la fila superior) usando N nombres de cartas separadas por
espacio organizados
         en el orden obvio.

ENTRADA EJEMPLO (archivo solitair.in):

4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D

FORMATO DE SALIDA:

* L�nea 1: Una sola l�nea con un entero que es el mejor puntaje posible
que Betsy
         puede obtener

SALIDA EJEMPLO (archivo solitair.out):

69
}

const
 mx                     = 101;
 mov                    : array[1..2,1..2] of shortint = ((-1,0),(0,1));

var
 fe,fs                  : text;
 n,sol                  : longint;
 sav                    : array[boolean,1..mx*mx*mx,1..2] of longint;
 best,tab               : array[1..mx,1..mx] of longint;
 mk                     : array[1..mx,1..mx] of boolean;

function cost(x : char) : longint;
begin
 case x of
  '2'..'9' : cost:=ord(x)-48;
  'A'      : cost:=1;
  'T'      : cost:=10;
  'J'      : cost:=11;
  'Q'      : cost:=12;
  'K'      : cost:=13;
 end;
end;

procedure open;
var
 i,j                    : longint;
 st                     : char;
begin
 assign(fe,'solitair.in'); reset(fe);
 assign(fs,'solitair.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(fe,st);
     tab[i,j]:=cost(st);
     read(fe,st);
     read(fe,st);
    end;
  end;
 close(fe);
end;

procedure work;
var
 i,j,cp,ch,h1,h2,x,y    : longint;
 s                      : boolean;
begin
 fillchar(best,sizeof(best),0);
 x:=n; y:=1; best[x,y]:=tab[x,y];
 s:=true; sav[s,1,1]:=x; sav[s,1,2]:=y;
 cp:=1; ch:=0; sol:=best[x,y];
 while cp>0 do
  begin
   fillchar(mk,sizeof(mk),false);
   for i:=1 to cp do
    begin
     x:=sav[s,i,1]; y:=sav[s,i,2];
     for j:=1 to 2 do
      begin
       h1:=x + mov[j,1]; h2:=y + mov[j,2];
       if (h1 > 0) and (h1 <= n) and (h2 > 0) and (h2 <= n)
        and (best[h1,h2] < best[x,y] + tab[h1,h2]) then
         begin
          best[h1,h2]:=best[x,y] + tab[h1,h2];
          if best[h1,h2] > sol then sol:=best[h1,h2];
          if not mk[h1,h2] then
           begin
            inc(ch);
            sav[not s,ch,1]:=h1;
            sav[not s,ch,2]:=h2;
            mk[h1,h2]:=true;
           end;
         end;
      end;
    end;
   s:=not s;
   cp:=ch;
   ch:=0;
  end;
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