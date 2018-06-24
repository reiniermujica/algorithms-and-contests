{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{
97¦ Paseo Vespertino.                                      México 2006
----------------------------------------------------------------------

Como todos sabemos, a las vacas les gustan las novedades. Por lo tanto
muchas veces  somos llamados  para ayudarles  a evitar  duplicación de
esfuerzos o escenarios. Otra pregunta importante ha aparecido.

Betsy está feliz pasteando en un campo de R (1 <= R <= 20) filas por C
(1 <= C <= 30) columnas de lotes de pasteo (denotados por '.') y lotes
rocosos  (denotados por   'R'). El  lote (1,  1) está  en la   esquina
superior izquierda de esta cuadrícula.  El sol se está ocultando,  por
lo tanto es tiempo de devolverse al establo, el cual está al sur y  al
este de Betsy.

Betsy quiere usar una ruta nueva al establo cada noche. Ella no  puede
caminar sobre los lotes  rocosos y solo se  desplazará hacia el sur  y
hacia el este hacia el establo, nunca al norte ni al oeste. Por  favor
calcule cuantas tardes  puede ella deambular  en una nueva  ruta antes
que ella tenga que repetir una ruta usada anteriormente.

Como ejemplo, considere esta distribución para la zona de pasteo de
Besty:

              B . . .       B = Betsy    . = lote para caminar
              R . . .       R = Rocas
              . . . B       B = Establo

Aquí están las seis maneras en que ella puede caminar al establo:

B## . .    B## . .    B#### .    B## . .   B######   B#### .
R # . .    R ### .    R . # .    R #####   R . . #   R . ###
. ####B    . . ##B    . . ##B    . . . B   . . . B   . . . B


NOMBRE DEL PROBLEMA: stroll

FORMATO DE ENTRADA:

- Línea 1: Dos enteros separados por espacio, respectivamente: R y C

-  Líneas 2..R+1:  La línea  i+1 representa  la fila  i y  contiene  C
elementos separados por espacios que representan lotes en el campo. El
primer elemento es el elemento en la columna 1 o fila 1. Cada elemento
es una 'B', 'R', o  '.'. Las 'B's no son ambiguas.

ENTRADA EJEMPLO (archivo STROLL.IN):

3 4
B . . .
R . . .
. . . B


FORMATO DE SALIDA:

- Línea 1: Un solo entero que es el número de caminos únicos de  Betsy
al establo. La respuesta no excederá 2,000,000,000.


SALIDA EJEMPLO (archivo STROLL.OUT):

6
}
const
 mov                    : array[1..2,1..2] of shortint
  =((1,0),(0,1));

var
 fe,fs                  : text;
 r,c                    : byte;
 sol                    : longint;
 posi                   : array[1..2,1..2] of byte;
 mtx                    : array[1..30,1..40] of longint;
 m                      : array[1..30,1..40] of boolean;

procedure open;
var
 i,j,t                  : byte;
 x                      : string[1];
begin
 assign(fe,'stroll.in'); reset(fe);
 assign(fs,'stroll.out'); rewrite(fs);
 readln(fe,r,c);
 t:=0;
 for i:=1 to r do
  begin
  for j:=1 to c do
   begin
    read(fe,x);
    if (x = 'B')  then
     begin
      inc(t);
      posi[t,1]:=i; posi[t,2]:=j;
     end;
    if (x='.') then mtx[i,j]:=0;
    if (x='R') then mtx[i,j]:=-1;
    read(fe,x);
   end;
  readln(fe);
  end;
 close(fe);
end;

function valid(x,y : byte) : boolean;
begin
 valid:=false;
 if (x>0) and (x<=r) and (y>0) and (y<=c)
  and (mtx[x,y] <> -1) then
   valid:=true;
end;

procedure bfs;
var
 cp,ch,x,y,i,j          : integer;
 sav                    : array[boolean,1..601,1..2] of integer;
 s                      : boolean;
begin
 s:=true; cp:=1; ch:=0; sol:=0; mtx[posi[1,1],posi[1,2]]:=1;
 sav[s,1,1]:=posi[1,1]; sav[s,1,2]:=posi[1,2];
 r:=posi[2,1]; c:=posi[2,2];
 while cp > 0 do
  begin
   fillchar(m,sizeof(m),false);
   for i:=1 to cp do
    for j:=1 to 2 do
     begin
      x:=sav[s,i,1] + mov[j,1]; y:=sav[s,i,2] + mov[j,2];
      if valid(x,y) then
       begin
       mtx[x,y]:=mtx[x,y]+mtx[sav[s,i,1],sav[s,i,2]];
       if not m[x,y] then
        begin
         inc(ch);
         sav[not s,ch,1]:=x;
         sav[not s,ch,2]:=y;
         m[x,y]:=true;
        end;
       end;
     end;
   cp:=ch;
   ch:=0;
   s:=not s;
  end;
end;

procedure closer;
begin
 writeln(fs,mtx[posi[2,1],posi[2,2]]);
 close(fs);
end;

begin
 open;
 bfs;
 closer;
end.
