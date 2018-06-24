  {$I-,Q-,R-,S-}

{Problema 8: Charcos  de Lodo [Jeffey  Wang, 2007]

El Granjero Juan ha salido de su casa temprano a las 6 AM para el
ordeño diario de Bessie. Sin embargo, en la tarde anterior el vio una
fuerte lluvia, y los campos están algo enlodados. GJ comienza en el
punto (0,0) en el plano de coordenadas y se dirige hacia Bessie quien
está ubicada en el punto (X, Y) (-500 &lt;= X &lt;= 500; -500 &lt;= Y &lt;= 500).
El puede ver N charcos de lodo, ubicados en los puntos (A_i, B_i) (-
500 &lt;= A_i &lt;= 500; -500 &lt;= B_i &lt;= 500)del campo. Cada charco ocupa
solo el punto en el que está.

Habiendo comprado recientemente botas nuevas, el Granjero Juan no
quiere absolutamente ensuciarlas parándose sobre lodo, pero quiere
llegar a donde Bessie tan rápido como sea posible. A él ya se le hizo
tarde debido a que él tuvo que contar todos los charcos. Si el
Granjero Juan puede viajar únicamente paralelo a los ejes y girar en
puntos con coordenadas enteras, ¿cuál es la distancia más corta que él
debe viajar para llegar a donde Bessie y mantener limpias sus botas?
Siempre existirá un camino sin lodo que el Granjero Juan pueda tomar
para llegar a donde Bessie.

NOMBRE DEL PROBLEMA: mud

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por espacio: X, Y, y N.

* Líneas 2..N+1: la línea i+1 contiene dos enteros separados por
     espacio

ENTRADA EJEMPLO (archivo mud.in):

1 2 7
0 2
-1 3
3 1
1 1
4 2
-1 1
2 2

DETALLES DE LA ENTRADA:

Bessie está en el punto (1, 2). El Granjero Juan ve 7 charcos de lodo;
ubicados en los puntos: (0, 2); (-1, 3); (3, 1); (1, 1); (4, 2); (-1,
1). Gráficamente:


   4 . . . . . . . .
   3 . M . . . . . .
Y  2 . . M B M . M .
   1 . M . M . M . .
   0 . . * . . . . .
  -1 . . . . . . . .
    -2-1 0 1 2 3 4 5

           X


FORMATO DE SALIDA:

* Línea 1: La distancia mínima que el Granjero Juan debe viajar para
     llegar a donde está Bessie sin parase en lodo.

SALIDA EJEMPLO (archivo mud.out):

11

DETALLES DE LA SALIDA:

El mejor camino para el Granjero Juan es (0, 0); (-1, 0); (-2, 0);
(-2, 1); (-2, 2); (-2, 3); (-2, 4); (-1, 4); (0, 4); (0, 3); (1, 3);
y (1,2), llegando finalmente a donde Bessie:


   4 ******* . . . .
   3 * M . * . . . .
Y  2 * . M B M . M .
   1 * M . M . M . .
   0 ***** . . . . .
  -1 . . . . . . . .
    -2-1 0 1 2 3 4 5

           X

 }

const
 mx             = 501;
 mov            : array[1..4,1..2] of shortint
  = ((1,0),(0,1),(-1,0),(0,-1));

var
 fe,fs          : text;
 n              : longint;
 posi           : array[1..2] of longint;
 tab            : array[-mx..mx,-mx..mx] of longint;
 sav            : array[boolean,1..mx*mx,1..2] of longint;

procedure open;
var
 i,a,b          : longint;
begin
 assign(fe,'mud.in'); reset(fe);
 assign(fs,'mud.out'); rewrite(fs);
 readln(fe,posi[1],posi[2],n);
 for i:=1 to n do
  begin
   readln(fe,a,b);
   tab[a,b]:=-1;
  end;
 close(fe);
end;

procedure closer(x : longint);
begin
 writeln(fs,x);
 close(fs);
 halt;
end;

procedure work;
var
 cp,ch,h1,h2,i,j     : longint;
 s                   : boolean;
 z                   : array[1..2] of longint;
begin
 cp:=1; ch:=0; s:=true;
 sav[s,1,1]:=0; sav[s,1,2]:=0;
 while cp > 0 do
  begin
   for i:=1 to cp do
    begin
     h1:=sav[s,i,1]; h2:=sav[s,i,2];
     for j:=1 to 4 do
      begin
       z[1]:=h1 + mov[j,1]; z[2]:=h2 + mov[j,2];
       if (z[1] > -501) and (z[1] < 501) and (z[2] > -501) and (z[2] < 501)
        and (tab[z[1],z[2]] = 0) then
         begin
          if (z[1] = posi[1]) and (z[2] = posi[2]) then
           closer(tab[h1,h2] + 1);
          inc(ch);
          sav[not s,ch,1]:=z[1];
          sav[not s,ch,2]:=z[2];
          tab[z[1],z[2]]:=tab[h1,h2] + 1;
         end;
      end;
    end;
   s:=not s;
   cp:=ch;
   ch:=0;
  end;
end;

begin
 open;
 work;
end.