{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{ş Slikar.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El malo emperor Cactus  tiene en su poseci¢n la Poci¢n M gina y  tiene
inundado el bosque encantado!  El   Pintor  y  los tres peque¤o erisos
ahora tienen que  retornar a la  cueva del Castor  donde ellos estar n
libre  de  riesgo antes  que  se llene  de  agua tan  r pido  como sea
posible!

El mapa del bosuqe encantado consiste de R filas y C columans.  Campos
vac¡os son representados por  '.'  caracteres,  campos inundados   por
'*'  y   rocas   pos   'X'. Adicionalmente,  la  cueva  del  Castor es
representada  por 'D'  y el  Pintor y  los  tres  peque¤os erisos  son
mostrado como por 'S'.

Cada minuto  el Pintor  y  los  tres the  three  peque¤o erisos pueden
moverse  para  los  4  campos  vecinos  (arriba,  abajo,  izquierda  o
derecha). Cada minito la inundaci¢n se expande  tambi‚n por todos  los
campos vac¡os  que tiene  al menos  una cada  en com£n  con los campos
inundados convirti‚ndose en  inundados tambi‚n. Tan  poco el agua,  el
Pintor y los tres peque¤o erisos  pueden pasar a trav‚s de las  rocas.
Naturalmente,  el Pintor y  los tres peque¤os erisos  no pueden  pasar
por los  campos inundados,  y el  agua no  puede inundar  la cueva del
castor.

Escriba un programa  que, dado un  mapa del Bosque  Encantado, de como
salida  el tiempo  m s peuqe¤o  necesitado por  el Pintor  y los  tres
peque¤o erisos llegar seguro a la cueva del Castoe.

Nota: La Pintor y los tres peque¤os erisos no pueden moverse al mismo
campo que est  cerca de ser inundado (en el mismo minuto).

Entrada

La primera l¡nea del fichero SLIKAR.IN contine dos enteros enteros,  R
y C, menores  o iguales a  50.  Las sigueintes  R l¡neas  cada  una de
ella contine C  caracteres ('.', '*',  'X', 'D' o  'S'). El mapa  debe
contener exactamente un caracter 'D' y exactamente un caracter 'S'.

Salida

El fichero de  salida SLIKAR.OUT debe  contener el tiempo  m s peque¤o
posible para qoe  el Pintor y  los tres peque¤os  erisos neceario para
llegar con seguridad a la cueva  del Castor. Si es to es  imposible la
salida debe mostra la palabra "KAKTUS" en una simple l¡nea.

Ejemplo de Entrada y Salida:

SLIKAR.IN              SLIKAR.IN               SLIKAR.IN
3 3                    3 3                     3 6
D.*                    D.*                     D...*.
...                    ...                     .X.X..
.S.                    ..S                     ....S.

SLIKAR.OUT             SLIKAR.OUT              SLIKAR.OUT
3                      KAKTUS                  8

Calificaci¢n del segundo ejemplo de prueba: El mejor de ello puede ser
ir a lo largo del borde de abajo y entonces el borde izquiedo, y puede
flooded un minuto antes de alcanzar la guardida.

}

const
 max            = 51;
 mov            : array[1..4,1..2] of shortint
  =((0,1),(1,0),(-1,0),(0,-1));

var
 fe,fs          : text;
 n,m,sol,time   : longint;
 tab            : array[0..max,0..max] of longint;
 sav            : array[boolean,1..2,0..max*max,1..2] of byte;
 posi           : array[0..2,0..2] of byte;
 p              : array[0..4] of longint;

procedure open;
var
 i,j            : longint;
 ch             : char;
begin
 assign(fe,'slikar.in'); reset(fe);
 assign(fs,'slikar.out'); rewrite(fs);
 readln(fe,n,m);
 fillchar(sav,sizeof(sav),0);
 p[3]:=0;
 for i:=1 to n do
  begin
    for j:=1 to m do
     begin
      read(fe,ch);
      case ch of
       '.' : tab[i,j]:= 0;
       'X' : tab[i,j]:=-1;
       'S' : begin
              posi[1,1]:=i;
              posi[1,2]:=j;
              tab[i,j]:=0;
             end;
       'D' : begin
              posi[2,1]:=i;
              posi[2,2]:=j;
              tab[i,j] :=-1;
             end;
       '*' : begin
              inc(p[3]);
              sav[true,2,p[3],1]:=i;
              sav[true,2,p[3],2]:=j;
              tab[i,j]:=-1;
             end;
      end;
     end;
    readln(fe);
  end;
 close(fe);
end;

procedure closer(x : longint);
begin
 if x = -1 then
  writeln(fs,'KAKTUS')
 else
  writeln(fs,x);
 close(fs);
 halt;
end;

procedure work;
var
 i,j,x,y           : longint;
 s                 : boolean;
 z                 : array[1..2] of byte;
 mk                : array[0..max,0..max] of boolean;
begin
 p[1]:=1; p[2]:=0; p[4]:=0; s:=true; time:=0;
 sav[s,1,1,1]:=posi[1,1]; sav[s,1,1,2]:=posi[1,2];
 while p[1] > 0 do
  begin
   fillchar(mk,sizeof(mk),false);
   inc(time);
   for i:=1 to p[3] do    {Bfs 2}
    begin
     x:=sav[s,2,i,1]; y:=sav[s,2,i,2];
     for j:=1 to 4 do
      begin
       z[1]:=x+mov[j,1]; z[2]:=y+mov[j,2];
       if (z[1] > 0) and (z[1] <= n) and (z[2] > 0) and (z[2] <=m)
        and (tab[z[1],z[2]] = 0) and (not mk[z[1],z[2]]) then
        begin
         inc(p[4]);
         sav[not s,2,p[4],1]:=z[1];
         sav[not s,2,p[4],2]:=z[2];
         tab[z[1],z[2]]:=-1;
         mk[z[1],z[2]]:=true;
        end;
      end;
    end;                   {End Bfs2}
   for i:=1 to p[1] do     {Bfs 1}
    begin
     x:=sav[s,1,i,1]; y:=sav[s,1,i,2];
     for j:=1 to 4 do
      begin
       z[1]:=x+mov[j,1]; z[2]:=y+mov[j,2];
       if not mk[z[1],z[2]] then
        begin
         if (z[1] = posi[2,1]) and (z[2] = posi[2,2]) then
          closer(time);
         if (z[1] > 0) and (z[1] <= n) and (z[2] > 0) and (z[2] <=m)
          and (tab[z[1],z[2]] = 0) then
           begin
            inc(p[2]);
            sav[not s,1,p[2],1]:=z[1];
            sav[not s,1,p[2],2]:=z[2];
            tab[z[1],z[2]]:=time;
            mk[z[1],z[2]]:=true;
           end;
        end;
      end;
    end;                   {End Bfs1}
   p[1]:=p[2];
   p[3]:=p[4];
   p[2]:=0;                 {xor}
   p[4]:=0;
   s:=not s;
  end;
end;

begin
 release(heaporg);
 open;
 work;
 closer(-1);
end.