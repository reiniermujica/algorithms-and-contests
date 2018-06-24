 {$I-,Q-,R-,S-}

{18¦ Adquisición de Partes                                 Polonia 2005
----------------------------------------------------------------------

Las vacas  han sido  enviadas en  una misión  a través delespacio para
adquirir una  nueva máquina  ordeñadora para  su establo.  Ellas están
viajando a través de un conglomerado de estrellas conteniendo N (1  <=
N <= 50,000) planetas, cada uno con una tienda.

Las vacas  han determinado  cuáles de  K (1  <= K  <= 1,000)  tipos de
objetos (numerados 1..K) de cada planeta en el conglomerado desean,  y
cuáles  productos  deben  comerciar.  Ningún  planeta  ha desarrollado
dinero, por lo  tanto ellos trabajan  con el sistema  de trueque: todo
los intercambios consisten de que cada parte da exactamente un  objeto
(presumiblemente de tipos diferentes).

Las vacas parten de la Tierra  con un paquete de heno de  alta calidad
(ítem  1),  y ellas  desean  una nueva  máquina  ordeñadora (ítem  K).
Ayúdelas  a  encontrar  la  mejor   manera  de  hacer  una  serie   de
intercambios en los planetas del conglomerado para obtener el ítem  K.
Si esta tarea es imposible, dé como salida -1.

NOMBRE DEL PROBLEMA: acquire

FORMATO DE ENTRADA:

- Línea 1: Dos enteros separados por espacios, N y K.
- Líneas 2..N+1:  La Línea  i+1  contiene  dos enteros   separados por
  espacio,  a_i  y  b_i   respectivamente,  que  son  los    productos
  de intercambio   del   planeta  i.  El   planeta dará   el  ítem b_i
  con  el propósito de recibir el ítem a_i.

ENTRADA EJEMPLO (archivo acquire.in):

6 5
1 3
3 2
2 3
3 1
2 5
5 4

FORMATO DE SALIDA:

* Línea 1: El mínimo número de intercambios T requeridos para obtener
  la máquina ordeñadora, la cual es el ítem K (o -1 si las vacas no
  pueden obtener el ítem K).

* Líneas 2..T+1: La lista ordenada de objetos que las vacas poseen
  durante la secuencia de intercambios.

SALIDA EJEMPLO (archivo acquiere.out):

4
1
3
2
5

DETALLES DE LA SALIDA

Las vacas  poseen 4  objetos en  total: primero  ellas intercambian el
objeto 1 por el objeto 3, luego  el objeto 3 por el objeto 2,  y luego
el objeto 2 por el objeto 5.
}

const
 mx             = 50001;
 inf            = 2139062143;

var
 fe,fs          : text;
 n,m            : longint;
 tab            : array[1..mx,1..3] of longint;
 d,cam,last     : array[0..mx] of longint;
 s              : array[1..mx] of boolean;

procedure open;
var
 i              : longint;
begin
 assign(fe,'acquire.in'); reset(fe);
 assign(fs,'acquire.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to n do
  begin
   readln(fe,tab[i,1],tab[i,2]);
   tab[i,3]:=last[tab[i,1]];
   last[tab[i,1]]:=i;
  end;
 close(fe);
end;

procedure work;
var
 i,j,x          : longint;
begin
 fillchar(d,sizeof(d),127);
 d[1]:=0; s[1]:=true; x:=1;
 for i:=1 to m-1 do
  begin
   s[x]:=true;
   j:=last[x];
   while j<>0 do
    begin
     if d[tab[j,2]] > d[x] + 1 then
      begin
       d[tab[j,2]]:=d[x] + 1;
       cam[tab[j,2]]:=x;
      end;
     j:=tab[j,3];
    end;
   x:=0;
   for j:=1 to m do
    if (d[j] < d[x]) and (not s[j]) then
     x:=j;
  end;
end;

procedure closer;
var
 i,j              : longint;
begin
 if d[m] = inf then
  writeln(fs,-1)
 else
  begin
   writeln(fs,d[m]+1);
   fillchar(d,sizeof(d),0);
   j:=cam[m]; i:=1;
   d[1]:=m;
   while j<>0 do
    begin
     inc(i);
     d[i]:=j;
     j:=cam[j];
    end;
   for j:=i downto 1 do writeln(fs,d[j]);
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.