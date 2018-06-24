  {$I-,Q-,R-,S-}

{Problema 8: Fiesta Vacuna Plata [Richard Ho, 2006]

Una vaca de cada una de N granjas (1 <= N <= 1000) convenientemente
numeradas 1..N van a ir a una gran fiesta vacuna que tendrá lugar en
la granja #X (1 <= X <= N). Un total de  M (1 <= M <= 100,000)
carreteras unidireccionlaes (de un sentido) conectan pares de granjas;
la carretera i requiere Ti (1 <= Ti <= 100) unidades de tiempo para
recorrerse.

Cada vaca debe caminar a la fiesta, y luego cuando se acabe la fiesta,
volver a su granja. Cada vaca es floja y por lo tanto elige una ruta
óptima con el tiempo más corta. La ruta de regreso de una vaca podría
ser diferente de su ruta original debido a que las carreteras son de
un sentido.

De todas las vacas, ¿cuál es la cantidad más grande de tiempo que una
vaca debe gastar caminando a la fiesta y devolviéndose?

NOMBRE DEL PROBLEMA: sparty

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por espacios, respectivamente N y M
      y x.

* Líneas 2..M+1: La línea i+1 describe la carretera i con tres enteros
      separados por espacios: Ai, Bi, y Ti. La carretera descrita va
      de la granja Ai a la granja Bi, requiriendo Ti unidades para
      recorrerse

ENTRADA EJEMPLO (archivo sparty.in):

4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

DETALLES DE LA ENTRADA:

Cuatro vacas, ocho carreteras: la fiesta es en la granja 2.

FORMATO DE LA SALIDA:

* Línea 1: Un entero: La máxima cantidad de tiempo que cualquier vaca
      debe caminar.

SALIDA EJEMPLO (archivo sparty.out):

10

DETALLES DE LA SALIDA:

La vaca 4 va directamente a la fiesta (3 unidades) y se devuelve via
las granjas 1 y 3 (7 unidades), para un total de 10 unidades de
tiempo.

}

{ Free Pascal , Dos Dijkstra }

const
 max             = 100001;
 cow             = 1001;

var
 fe,fs           : text;
 n,m,sol,p       : longint;
 tab             : array[1..max,1..5] of longint;
 cam             : array[1..cow,1..2] of longint;
 suma,d          : array[0..cow] of longint;
 s               : array[1..cow] of boolean;

procedure open;
var
 i               : longint;
begin
 assign(fe,'sparty.in'); reset(fe);
 assign(fs,'sparty.out'); rewrite(fs);
 readln(fe,n,m,p);
 for i:=1 to m do
  begin
   readln(fe,tab[i,1],tab[i,2],tab[i,3]);
   tab[i,4]:=cam[tab[i,1],1]; cam[tab[i,1],1]:=i;
   tab[i,5]:=cam[tab[i,2],2]; cam[tab[i,2],2]:=i;
  end;
 close(fe);
end;

procedure dijkstra(node,ini,fin : longint);
var
 i,j,k,x                        : longint;
begin
 fillchar(s,sizeof(s),false);
 s[node]:=true; d[node]:=0; x:=node;
 for i:=1 to n-1 do
  begin
   j:=cam[x,ini];
   while (j <> 0) do
    begin
     k:=d[x] + tab[j,3];
     if d[tab[j,fin]] > k then
      d[tab[j,fin]]:=k;
     j:=tab[j,3+ini];
    end;
   x:=0;
   for j:=1 to n do
    if (not s[j]) and (d[j] < d[x]) then
     x:=j;
   s[x]:=true;
  end;
end;

procedure work;
var
 i               : longint;
begin
 sol:=0;
 fillchar(d,sizeof(d),127);
 d[0]:=maxlongint;
 dijkstra(p,2,1);
 for i:=1 to n do
  begin
   suma[i]:=d[i];
  end;
 fillchar(d,sizeof(d),127);
 d[0]:=maxlongint;
 dijkstra(p,1,2);
 for i:=1 to n do
  begin
   suma[i]:=suma[i] + d[i];
   if suma[i] > sol then
    sol:=suma[i];
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