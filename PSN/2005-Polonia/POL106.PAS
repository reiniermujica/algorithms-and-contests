  {$I-,Q-,R-,S-}

{컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴쩡컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
    �       \ 栢栢� /     �     �
    /\     \ 栢栢栢� /   /\     �        CUBIOI 14, Problema A
   /  \     栢栢栢栢�   /  \    �
  /    \    栢栢栢栢�  /    \   �
        \  / 栢栢栢� \       \  �                                SKIAREA
         \  / 栢栢� \         \ 쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
     Nowy Sacz, Polonia 2005    � Puntuaci줻: 30 ptos.
    17th Olympiad in Informatic � Tiempo L죑ite: Alumnos.
컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴좔컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴

� Area de Esqu� Vacuna.

El primo del Granjero Juan, el Granjero Ron, GR, quien vive en las
monta쨅s de Colorado, ha ense쨅do recientemente a esquiar a sus vacas.
Desafortunadamente, sus vacas son algo t죑idas y les da pena esquiar
entre multitudes de gente de los centros vacacionales locales, por lo
tanto GR ha decidido construir su propia 쟲ea privada de esqu� detr쟳
de su granja.

El 쟲ea de esqu� de GR es un rect쟮gulo de ancho W y largo L de
cuadrados de terreno (1 <= W <= 500; 1 <= L <= 500).  Cada cuadrado de
terreno est� en una altura H encima del nivel del mar (0 <= H <=
9,999). Las vacas pueden esquiar horizontal y verticalmente entre
cualesquiera dos cuadrados de terreno adyacentes, pero nunca
diagonalmente. Las vacas pueden esquiar de un cuadrado m쟳 alto a uno
m쟳 bajo pero no en sentido contrario y ellas pueden esquiar en
cualquier direcci줻 entre dos cuadrados adyacentes de la misma altura.

GR quiere construir su 쟲ea de esqu� de tal manera que sus vacas
puedan desplazarse entre cualesquiera dos cuadrados usando una
combinaci줻 de esqu� (como se ha descrito antes) y elevadores. Se
puede poner un elevador conectando cualesquiera dos cuadrados del 쟲ea
de esqu�, independientemente de su altura. Los elevadores son
bidireccionales. Los elevadores pueden cruzarse sobre otros desde que
ellos pueden construirse en alturas variables sobre la superficie, y
varios elevadores pueden comenzar o terminar en el mismo cuadrado.
Como es caro construir elevadores, GR quiere minimizar el n즡ero de
elevadores que 굃 tiene que construir para permitir que sus vacas se
desplacen entre todos los cuadrados de su 쟲ea de esqu�.

Encuentre el m죒imo n즡ero de elevadores requeridos para asegurarse
que las vacas puedan desplazarse de cualquier cuadrado a cualquier
otro a trav굎 de una combinaci줻 de esqu� y de elevadores.

FORMATO DE ENTRADA:

- L죒ea 1. Dos enteros separados por espacios: W y L

- L죒eas 2..L+1: L l죒eas, cada una con W enteros separados por
  espacios correspondientes a las alturas de cada cuadrado de terreno.

ENTRADA EJEMPLO (archivo skiarea.in):

9 3
1 1 1 2 2 2 1 1 1
1 2 1 2 3 2 1 2 1
1 1 1 2 2 2 1 1 1

FORMATO DE SALIDA:

- L죒ea 1: Un solo entero igual al m죒imo n즡ero de elevadores que GR
  necesita construir para asegurarse que sus vacas puedan ir de
  cualquier cuadrado a cualquier otro mediante una combinaci줻 de
  esquiar y de elevadores.

SALIDA EJEMPLO (archivo skiarea.out):

3

DETALLES DE LA SALIDA:

GR construye los tres elevadores. Usando (1, 1) como la esquina
inferior izquierda, los elevadores son (3, 1) <-> (8, 2), (7, 3) <->
(5, 2), y (1, 3) <-> (2, 2). Todas las posiciones est쟮 ahora
conectadas. Por ejemplo, si una vaca quiere ir de (9, 1) a (2, 2),
podr죂 esquiar (9, 1) -> (8, 1) -> (7, 1) -> (7, 2) -> (7, 3), tomar
el elevador (7, 3) -> (5, 2), esquiar (5, 2) -> (4, 2) -> (3, 2) ->
(3, 3) -> (2, 3) -> (1, 3), y luego tomar el elevador (1, 3) - > (2,
2). No hay soluci줻 usando menos de tres cables de ascenci줻. No hay
soluci줻 usando menos de tres elevadores.
 }

const
 mx             = 501;
 mov            : array[1..4,1..2] of shortint
  =((0,1),(1,0),(-1,0),(0,-1));

var
 fe,fs          : text;
 n,m,sol,act    : longint;
 a,comp         : array[1..mx,1..mx] of longint;
 sav            : array[boolean,1..mx*mx,1..2] of longint;
 padre,hijo     : array[0..mx*mx] of boolean;

procedure open;
var
 i,j            : longint;
begin
 assign(fe,'skiarea.in'); reset(fe);
 assign(fs,'skiarea.out'); rewrite(fs);
 readln(fe,m,n);
 for i:=1 to n do
  begin
   for j:=1 to m do
    read(fe,a[i,j]);
   readln(fe);
  end;
 close(fe);
end;

procedure bfs(x,y : longint);
var
 cp,ch,i,j,h1,h2  : longint;
 z                : array[1..2] of longint;
 s                : boolean;
begin
 cp:=1; ch:=0; s:=true;
 sav[s,1,1]:=x; sav[s,1,2]:=y;
 while cp > 0 do
  begin
   for i:=1 to cp do
    begin
     h1:=sav[s,i,1]; h2:=sav[s,i,2];
     for j:=1 to 4 do
      begin
       z[1]:=h1 + mov[j,1]; z[2]:=h2 + mov[j,2];
       if (z[1] > 0) and (z[1] <= n) and (z[2] > 0) and (z[2] <= m) then
        begin
         if (a[z[1],z[2]] = a[h1,h2]) and (comp[z[1],z[2]] = 0) then
          begin
           inc(ch);
           sav[not s,ch,1]:=z[1];
           sav[not s,ch,2]:=z[2];
           comp[z[1],z[2]]:=act;
          end
          else
         if (a[z[1],z[2]] > a[h1,h2]) then
          begin
           hijo[comp[z[1],z[2]]]:=true;
           padre[comp[h1,h2]]:=true;
          end
          else
         if (a[z[1],z[2]] < a[h1,h2]) then
          begin
           hijo[comp[h1,h2]]:=true;
           padre[comp[z[1],z[2]]]:=true;
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
var
 i,j,k            : longint;
begin
 act:=0;
 for i:=1 to n do
  for j:=1 to m do
   begin
    if (comp[i,j] = 0) then
     begin
      inc(act);
      comp[i,j]:=act;
      bfs(i,j);
     end;
   end;
 if (act > 1) then
  begin
   j:=0; k:=0;
   for i:=1 to act do
    if not hijo[i] then inc(j);
   for i:=1 to act do
    if not padre[i] then inc(k);
   if (j > k) then sol:=j
              else sol:=k;
  end
 else
  sol:=0;
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