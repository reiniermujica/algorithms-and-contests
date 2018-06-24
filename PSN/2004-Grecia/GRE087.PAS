{$B-,I-,Q-,R-,S-}
{$M 64000,0,655360}
{87¦ Búsqueda.                                              Grecia 2004
----------------------------------------------------------------------

El joven Ralph pidio prestado un  carro y lo dirigio a las  del pueblo
para divertirse. Lo que el no conocia era que el carro pertenecio a la
policia y este tenia un  dispositivo que estaba concebido para  enviar
informacion acerca del movimiento del carro'.

El dispositivo es más bien viejo y envia solamente información  acerca
de una  dirección del  movimiento del  carro. Escriba  un programa que
ayude a la policia a encontrar el carro utilizando un mapa del pueblo,
su posición  inicial y  una secuencia  de direcciones  que guiaron  al
carro.  El  programa  debe determinar  todas  las  posibles posiciones
finales del carro.
  
Un mapa  del pueblo  es rectangular  y los  caracteres son usados para
describir donde el carro puede y donde no se puede manejar. Los puntos
('.') denotan  a los  lugares del   pueblo donde   se puede manejar un
carro, los caracteres 'X'  denotan los lugares del pueblo por donde no
se puede manejar. La posicion inicial del carro que maneja Ralph  esta
denotada con el caracter '*'. Un carro puede guiarse de un lado a otro
de  la  posición  inicial  position.  Un carro puede guiarse en cuatro
direcciones: al  norte  (up),  al sur  (down),  al oeste  (left)  y al
este (right). Una descripcion descripcion de los movimientos de  Ralph
con  un  carro es  dada  con una  secuencia  de direcciones.  En  cada
direccion dada  Ralph guia  su carro  a traves  de una  o más  lugares
transitables del pueblo.

Entrada

La primera linea del fichero de entrada SEARCH.IN contiene dos numeros
naturales R  y C,  1 <=  R <=  50,  1  <= C  <= 50,  separados por  un
caracter espacio character,  numero de filas  y columnas del  mapa del
pueblo. Cada una de las   próximas R  lineas   contiene una  secuencia
de  C  caracteres   ('.'  (un  punto),  'X'    '*')  describiendo   la
correspondiente  parte  del   mapa.  La  siguiente,(R+2)-esima   linea
contiene  un numero  natural  N,   1   <= N <=  1000,  longitud de  la
secuencia  de  direcciones. Cada  una  de  las  siguientes   N  lineas
contiene  una  de las   siguientes secuencias  de caracteres:   NORTH,
SOUTH,   WEST   y  EAST,   describiendo direcciones  de movimiento del
carro. Dos direcciones consecutivas no son la misma.
 
Salida

El fichero de salida SEARCH.OUT  debe contener el mapa de  los pueblos
en R  lineas (como en  el fichero  de entrada),  donde el  carater '*'
debe denotar solamente las posibles posiciones finales del carro.

Ejemplos de Entrada y Salida
 
Ejemplo #1         Ejemplo #2          Ejemplo #3

+-----------+      +-----------+       +-----------+
¦ SEARCH.IN ¦      ¦ SEARCH.IN ¦       ¦ SEARCH.IN ¦
+-----------¦      +-----------¦       +-----------¦
¦ 3 4       ¦      ¦ 4 5       ¦       ¦ 10 9      ¦
¦ ....      ¦      ¦ .....     ¦       ¦ ........X ¦
¦ *..X      ¦      ¦ .X...     ¦       ¦ X..XX..X. ¦
¦ X.X.      ¦      ¦ ...*X     ¦       ¦ .X.XX.X.. ¦
¦ 2         ¦      ¦ X.X..     ¦       ¦ ...XX.... ¦
¦ EAST      ¦      ¦ 3         ¦       ¦ ...XX.... ¦
¦ NORTH     ¦      ¦ NORTH     ¦       ¦ .XXX..XX. ¦
+-----------+      ¦ WEST      ¦       ¦ .......X. ¦
+------------+     ¦ SOUTH     ¦       ¦ ..XXX.X.. ¦
¦ SEARCH.OUT ¦     +-----------+       ¦ X.X....X. ¦
+------------¦     +------------+      ¦ *.....X.. ¦
¦ .**.       ¦     ¦ SEARCH.OUT ¦      ¦ 4         ¦
¦ ...X       ¦     +------------¦      ¦ EAST      ¦
¦ X.X.       ¦     ¦ .....      ¦      ¦ NORTH     ¦
+------------+     ¦ *X*..      ¦      ¦ EAST      ¦
                   ¦ *.*.X      ¦      ¦ SOUTH     ¦
                   ¦ X.X..      ¦      +-----------+
                   +------------+      +------------+
                                       ¦ SEARCH.OUT ¦
                                       +------------¦
                                       ¦ ........X  ¦
                                       ¦ X..XX.*X.  ¦
                                       ¦ .X.XX.X..  ¦
                                       ¦ ...XX....  ¦
                                       ¦ ...XX.***  ¦
                                       ¦ .XXX..XX*  ¦
                                       ¦ .......X*  ¦
                                       ¦ ..XXX*X.*  ¦
                                       ¦ X.X..*.X*  ¦
                                       ¦ ....**X.*  ¦
                                       +------------+
}
const
 mov          : array[1..4,1..2] of shortint=((-1,0),(0,1),(1,0),(0,-1));
 nam          : array[1..4] of char=('N','E','S','W');

var
 fe,fs        : text;
 s            : boolean;
 x,y,m,c1,c2  : longint;
 map,sol      : array[1..50,1..50] of char;
 hp           : array[1..50,1..50] of boolean;
 a            : array[1..1001] of integer;
 sa           : array[boolean,1..2501,1..2] of integer;

procedure open;
var
 t1,t2        : longint;
 q            : char;
begin
 assign(fe,'search.in'); reset(fe);
 assign(fs,'search.out'); rewrite(fs);
 readln(fe,x,y);
 for t1:=1 to x do
  begin
   for t2:=1 to y do
    begin
     read(fe,map[t1,t2]);
     sol[t1,t2]:=map[t1,t2];
     if (map[t1,t2]='*') then
      begin
       c1:=t1; c2:=t2;
       sol[t1,t2]:='.';
       map[t1,t2]:='.';
      end;
    end;
   readln(fe);
  end;
 readln(fe,m);
 for t1:=1 to m do
  begin
   readln(fe,q);
   for t2:=1 to 4 do
    if nam[t2] = q then
     begin
      a[t1]:=t2;
      break;
     end;
  end;
 close(fe);
end;

function search(q,w : integer) : boolean;
begin
 search:=false;
 if (q>0) and (q<=x) and (w>0) and (w<=y)
  and (map[q,w] = '.') and (hp[q,w] = false) then
   search:=true;
end;

procedure work;
var
 i,k,nh,np,x1,y1               : longint;
begin
 np:=1; nh:=0; s:=true; fillchar(hp,sizeof(hp),0);
 sa[s,1,1]:=c1; sa[s,1,2]:=c2;  x1:=c1; y1:=c2;
 for k:=1 to m-1 do
  begin
     for i:=1 to np do
       begin
        x1:=sa[s,i,1] + mov[a[k],1]; y1:=sa[s,i,2] + mov[a[k],2];
        while search(x1,y1) do
         begin
         inc(nh);
         sa[not s,nh,1]:=x1;
         sa[not s,nh,2]:=y1;
         hp[x1,y1]:=true;
         x1:=x1 + mov[a[k],1];
         y1:=y1 + mov[a[k],2];
         end;
        end;
     np:=nh; nh:=0; s:=not s; fillchar(hp,sizeof(hp),0);
  end;
 for i:=1 to np do
  begin
   x1:=sa[s,i,1] + mov[a[m],1]; y1:=sa[s,i,2] + mov[a[m],2];
   while search(x1,y1) do
         begin
         sol[x1,y1]:='*';
         x1:=x1 + mov[a[m],1];
         y1:=y1 + mov[a[m],2];
         end;
  end;
end;

procedure closer;
var
 t1,t2        : longint;
begin
 for t1:=1 to x do
  begin
   for t2:=1 to y do write(fs,sol[t1,t2]);
   writeln(fs);
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.