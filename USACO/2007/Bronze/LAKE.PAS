 {$I-,Q-,R-,S-}

{Problema 13: Evite los Lagos (Jeffrey Wang, 2007)

La granja del Granjero Juan quedó inundada después de la tormenta más 
reciente, un hecho únicamente agravado por la información que sus vacas 
temen a muerte el agua. Su agencia de seguro solamente le pagará a él, 
sin embargo, una cantidad dependiendo del tamaño del mayor “lago” en su
granja.

La granja está representada como una cuadrícula rectangular con N (1<= N 
<= 100) filas y M (1 <= M <= 100) columnas. Cada celda en la cuadrícula 
está seca o sumergida, y exactamente K (1 <= K <= N*M) de las celdas 
están sumergidas. Como uno esperaría, un lago tiene una celda central a 
la cual están conectadas otras celdas compartiendo un borde (no una 
esquina). Cualquier celda que comparta un borde con la celda central o 
comparta un borde con cualquier celda conectada se vuelve una celda 
conectada y es parte del lago.

NOMBRE DEL PROBLEMA: lake

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por enteros: N, M, y K

* Líneas 2..K+1: La línea i+1 describe una ubicación sumergida con dos
     enteros separados por espacio que son su fila y columna R y C

ENTRADA EJEMPLO (archivo lake.in):

3 4 5
3 2
2 2
3 1
2 3
1 1

DETALLES DE LA ENTRADA:

La granja es una cuadrícula con tres filas y cuatro columnas; cinco de 
las celdas están sumergidas: Ellas están ubicadas en las posiciones (fila 
3, columna 2); (fila 2, columna 2); (fila 3, columna 1); (fila 2, columna 
3); (fila 1, columna 1):
              # . . .
              . # # .
              # # . .


FORMATO DE SALIDA:

* Línea 1: El número de celdas que contiene el lago más grande.

SALIDA EJEMPLO (archivo lake.out):

4

DETALLES DE LA SALIDA:

El mayor lago consiste en las cuatro primeras celdas de la entrada.
 }

const
 max               = 101;
 mov               : array[1..4,1..2] of shortint
  =((1,0),(0,1),(-1,0),(0,-1));

var
 fe,fs             : text;
 n,m,k,sol,cp,ch   : longint;
 tab               : array[1..max,1..max] of byte;
 sav               : array[boolean,1..max*max*2+1,1..2] of longint;

procedure open;
var
 i,x,y             : longint;
begin
 assign(fe,'lake.in'); reset(fe);
 assign(fs,'lake.out'); rewrite(fs);
 readln(fe,n,m,k);
 for i:=1 to k do
  begin
   readln(fe,x,y);
   tab[x,y]:=1;
  end;
 close(fe);
end;

function bfs(x,y : longint) : longint;
var
 i,j,k,h1,h2     : longint;
 s               : boolean;
begin
 cp:=1; ch:=0; s:=true;
 sav[s,1,1]:=x; sav[s,1,2]:=y;
 k:=1;
 while cp > 0 do
  begin
   for i:=1 to cp do
    for j:=1 to 4 do
     begin
      h1:=sav[s,i,1] + mov[j,1];
      h2:=sav[s,i,2] + mov[j,2];
      if (h1 > 0) and (h1 <= n) and (h2 > 0) and (h2 <= m)
       and (tab[h1,h2]=1) then
        begin
         inc(ch);
         sav[not s,ch,1]:=h1;
         sav[not s,ch,2]:=h2;
         tab[h1,h2]:=0;
         inc(k);
        end;
     end;
   s:=not s;
   cp:=ch;
   ch:=0;
  end;
  bfs:=k;
end;

procedure work;
var
 i,j,k          : longint;
begin
 for i:=1 to n do
  for j:=1 to m do
   begin
    if tab[i,j] = 1 then
     begin
      tab[i,j]:=0;
      k:=bfs(i,j);
      if sol < k then
       sol:=k;
     end;
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