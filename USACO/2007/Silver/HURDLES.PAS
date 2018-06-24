  {$I-,Q-,R-,S-}

{Problema 6: Vallas Vacunas [Neal Wu, 2007]

El Granjero Juan quiere que las vacas se preparen para la competencia
de salto del condado, por lo tanto Bessie y la pandilla est n
practicando saltar sobre vallas. Ellas se est n cansando, sin embargo,
ellas quieren ser capaces de usar tan poca energ¡a como sea posible
para saltar las vallas.

Obviamente, no es dif¡cil para una vaca saltar sobre varias vallas
peque¤as, pero saltar una valla alta puede ser muy estresante. Por lo
tanto, las vacas £nicamente est n preocupadas por la altura de la
valla m s alta que tienen que saltar.

El cuarto de pr ctica de las vacas tiene N (1 <= N <= 300) estaciones,
convenientemente numeradas 1..N. Un conjunto de M (1 <= M <= 25,000)
caminos de una v¡a conectan pares de estaciones; los caminos est n
tambi‚n convenientemente numerados 1..M. El camino i va de la estaci¢n
S_i a la estaci¢n E_i y contiene exactamente una valla de altura H_i
(1 <= H_i <= 1,000,000). Las vacas deben saltar las vallas en todos
los caminos que ellas recorran.

Las vacas tienen T (1 <= T <= 40,000) tareas a completar. La tarea I
comprende dos n£meros diferentes; A_i y B_i (1 <= A_i <= N; 1 <= B_i
<= N), que denotan que una vaca tiene que viajar de la estaci¢n A_i a
la estaci¢n B_i (recorriendo uno o m s caminos a trav‚s alguna ruta).
Las vacas quieren tomar un camino que minimice la altura de la mayor
valla que ellas deben saltar cuando viaja de A_i a B_i. Su tarea es
escribir un programa que determine el camino cuya mayor valla sea la
menor y reporte esa altura.

NOMBRE DEL PROBLEMA: hurdles

FORMATO DE ENTRADA:

* L¡nea 1: Tres enteros separados por espacios: N, M y T

* L¡neas 2..M+1: La l¡nea i+1 contiene tres enteros separados por
     espacios: S_i, E_i y H_i

* L¡neas M+2..M+T+1: La l¡nea i+M+1 contiene dos enteros separados por
     espacio que describen la tarea i: A_i y B_i

ENTRADA EJEMPLO (archivo hurdles.in):

5 6 3
1 2 12
3 2 8
1 3 5
2 5 3
3 4 4
2 4 8
3 4
1 2
5 1

FORMATO DE SALIDA:

* L¡neas 1..T: La l¡nea i contiene el resultado de la tarea i y dice
     la posible menor altura m xima necesaria para ir entre las
     estaciones. D‚ como salida -1 si es imposible viajar entre las
     dos estaciones.

SALIDA EJEMPLO (archivo hurdles.OUT):

4
8
-1

DETALLES DE LA SALIDA:

Pregunta #1: La mejor manera es simplemente viajar en el camino de la
estaci¢n 3 a la estaci¢n 4.
Pregunta #2: Hay un camino de la estaci¢n 1 a la estaci¢n 2, pero una
mejor manera ser¡a viajar de la estaci¢n 1 a la estaci¢n 3 y luego a
la estaci¢n 2.
Pregunta #3: No hay caminos que comiencen en la estaci¢n 5, por lo
tanto es claro que no hay manera de llegar a la estaci¢n 1 desde la
estaci¢n 5.

}

const
 mx                = 301;
 inf               = 2139062143;

var
 fe,fs             : text;
 n,m,t,i,a,b,c     : longint;
 tab               : array[1..mx,1..mx] of longint;

procedure open;
begin
 assign(fe,'hurdles.in'); reset(fe);
 assign(fs,'hurdles.out'); rewrite(fs);
 readln(fe,n,m,t);
 fillchar(tab,sizeof(tab),127);
 for i:=1 to m do
  begin
   readln(fe,a,b,c);
   tab[a,b]:=c;
  end;
end;

function min(n1,n2 : longint) : longint;
begin
 if n1 < n2 then
  min:=n1
 else min:=n2;
end;

function max(n1,n2 : longint) : longint;
begin
 if n1 > n2 then
  max:=n1
 else max:=n2;
end;

procedure floyd;
var
 j,k             : longint;
begin
 for i:=1 to n do
  for j:=1 to n do
   if tab[j,i] <> inf then
    begin
     for k:=1 to n do
      tab[j,k]:=min(tab[j,k],max(tab[j,i],tab[i,k]));
    end;
end;

procedure work;
begin
 floyd;
 for i:=1 to t do
  begin
   readln(fe,a,b);
   if tab[a,b] <> inf then
    writeln(fs,tab[a,b])
   else writeln(fs,-1);
  end;
 close(fe);
 close(fs);
end;

begin
 open;
 work;
end.