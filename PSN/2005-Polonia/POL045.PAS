  {$I-,Q-,R-,S-}

{45ş Verificando una coartada.                             Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un crimen  ha sido  cometido: una  carga de  grano ha  sido tomada del
establo por una  de las vacas  de GJ. GJ  est  tratando de  determinar
cual de sus C (1 <=  C <= 100) vacas es la  culpable. Afortunadamente,
un sat‚lite que pasaba por la zona  tom¢ una imagen de su granja M  (1
<= M <= 70000)  segundos antes que el  crimen tuviera lugar, dando  la
ubicaci¢n de  todas las  vacas. El  quiere saber  cuales vacas  ten¡an
tiempo para llegar al establo y robar el grano.

La  granja  del Granjero  Juan  comprende F  (1  <= F  <=  500) campos
numerados 1..F que est n  conectados por P (1  <= P <= 1,000)  caminos
bidireccionales cuyo  tiempo de  recorrido est   en el  rango 1..70000
segundos (las  vacas caminan  muy despacio).  El campo  1 contiene  al
establo. No toma ning£n tiempo desplazarse dentro de un campo.

Dada la distribuci¢n de la granja del Granjero Juan y la ubicaci¢n  de
cada vaca cuando el sat‚lite pas¢ por encima, determine el conjunto de
vacas que podr¡an ser culpables.

NOMBRE DEL PROLEMA: alibi

FORMATO DE ENTRADA:

- L¡nea 1: Cuatro enteros separados por espacios: F, P, C y M

- L¡neas 2..P+1: Tres  enteros separados por espacios  describiendo un
  camino:  F1, F2  y T.  El camino  conecta F1  y F2 y se requieren  T
  segundos para recorrerlo.
- L¡neas P+2..P+C+1: Un entero por l¡nea, la ubicaci¢n de una vaca. La
  primera  l¡nea da  el n£mero  del campo  donde  est   la vaca  1, la
  segunda de la vaca 2, etc.

ENTRADA EJEMPLO (archivo alibi.in):

7 6 5 8
1 4 2
1 2 1
2 3 6
3 5 5
5 4 6
1 7 9
1
4
5
3
7


DETALLES DE LA ENTRADA:

Campos/distancias como esto:
          6
      4------5
      |      |
     2|      |
      |      |
7-----1      |5
      |      |
     1|      |
      |      |
      2------3
          6

FORMATO DE SALIDA

- L¡nea 1:  Un solo  entero  N,  el numero  de vacas  que podr¡an  ser
  culpables del crimen.

- L¡neas 2..N+1: Un  solo n£mero de vaca  en cada l¡nea que  es una de
  las vacas que podr¡an ser culpables del crimen. La lista debe  estar
  en orden ascendente.

SALIDA EJEMPLO (archivo alibi.out):

4
1
2
3
4

DETALLES DE LA SALIDA:

Cualquier vaca,  excepto la  5 podr¡a  haberlo hecho.  A la  vaca 5 le
hubiera tomado 9 segundos llegar al establo.

}

{ Free Pascal , Dijkstra }

const
 inf              = 2139062143;
 max              = 501;
 cow              = 101;

var
 fe,fs            : text;
 n,m,time,c,sol   : longint;
 cost             : array[0..max,0..max] of longint;
 s                : array[0..max] of boolean;
 d                : array[0..max] of longint;
 posi,list        : array[0..cow] of longint;

procedure open;
var
 i,j,k,t          : longint;
begin
 assign(fe,'alibi.in'); reset(fe);
 assign(fs,'alibi.out'); rewrite(fs);
 readln(fe,n,m,c,time);
 fillchar(cost,sizeof(cost),127);
 for i:=1 to m do
  begin
   readln(fe,j,k,t);
   if (cost[j,k] > t) then
    begin
     cost[j,k]:=t;
     cost[k,j]:=t;
    end;
  end;
 for i:=1 to c do
  readln(fe,posi[i]);
 close(fe);
end;

procedure dijkstra;
var
 i,j,x            : longint;
begin
 fillchar(s,sizeof(s),false);
 s[1]:=true; d[1]:=0;
 for i:=1 to n-1 do
  begin
   x:=0;
   for j:=1 to n do
    if (not s[j]) and (d[j] < d[x]) then
     x:=j;
   s[x]:=true;
   for j:=1 to n do
    if (cost[x,j] <> inf) and (d[j] > cost[x,j] + d[x]) then
     d[j]:=cost[x,j] + d[x];
  end;
end;

procedure work;
var
 i                : longint;
begin
 fillchar(d,sizeof(d),127);
 for i:=2 to n do
  if (cost[1,i] <> inf) then
   d[i]:=cost[1,i];
 dijkstra;
 sol:=0;
 for i:=1 to c do
  begin
   if (d[posi[i]] <= time) then
    begin
     inc(sol);
     list[sol]:=i;
    end;
  end;
end;

procedure closer;
var
 i                : longint;
begin
 writeln(fs,sol);
 for i:=1 to sol do
  writeln(fs,list[i]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.