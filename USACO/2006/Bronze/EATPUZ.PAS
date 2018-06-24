  {$I-,Q-,R-,S-}

{Problema 12: Rompecabezas Comestible [Rob Kolstad, 2006]

Bessie est  haciendo una dieta en la cual ella no puede comer m s de C
(10 <= C <= 35,000) calor¡as por d¡a. El Granjero Juan est  molest ndola
poni‚ndole B (1 <= B <= 21) baldes de comida, cada uno de los cuales con
alg£n n£mero (potencialmente no £nico) de calor¡as (en el rango
1..35,000). Bessie no tiene auto-control: una vez que ella comienza a
alimentarse de un balde, ella lo consume totalmente.

Por ejemplo, considere un l¡mite de 40 calor¡as y 6 baldes con tamaños 7,
13, 17, 19, 29, y 31. Bessie podr¡a comer 7 + 31 = 38 calorias, pero a£n
m s podr¡a comer tres baldes: 7 + 13 + 19 = 39 calor¡as. Ella no puede
encontrar una combinaci¢n mejor.

NOMBRE DEL PROBLEMA: eatpuz

FORMATO DE ENTRADA:

* L¡nea 1: Dos enteros separados por espacio:  C y B.

* L¡nea 2: B enteros separados por espacio que son respectivamente el
      n£mero de calor¡as en el balde 1, 2, etc.

ENTRADA EJEMPLO (archivo eatpuz.in):

40 6
7 13 17 19 29 31

FORMATO DE SALIDA:

* L¡nea 1: Una sola l¡nea con un solo entero que es el mayor n£mero de
      calor¡as que Bessie puede consumir y a£n cumplir con la dieta.

SALIDA EJEMPLO (archivo eatpuz.out):

39

  ****  Para free Pascal ****

 }



const
 max            = 35001;

type
 Trange         = longint;
 ta             = array[0..22] of boolean;

var
 fe,fs          : text;
 n,m,sol        : longint;
 tab            : array[0..22] of Trange;
 best           : array[0..max] of Trange;
 mk             : array[0..max] of ^ta;

procedure open;
var
 i              : longint;
begin
 assign(fe,'eatpuz.in'); reset(fe);
 assign(fs,'eatpuz.out'); rewrite(fs);
 readln(fe,n,m);
 for i:=1 to m do
  read(fe,tab[i]);
 close(fe);
end;

procedure work;
var
 i,j,k,p         : longint;
begin
 new(mk[0]); fillchar(mk[0]^,sizeof(mk[0]^),false);
 for i:=1 to n do
  begin
   k:=0; p:=0;
   new(mk[i]); fillchar(mk[i]^,sizeof(mk[i]^),false);
   for j:=1 to m do
    if (i - tab[j] >= 0) and (best[i-tab[j]] + tab[j] > best[i])
     and (not mk[i-tab[j]]^[j]) then
      begin
       best[i]:=best[i-tab[j]] + tab[j];
       k:=i-tab[j];
       p:=j;
      end;
   if best[i] < best[i-1] then
    begin
     best[i]:=best[i-1];
     mk[i]^:=mk[i-1]^;
    end
    else
    begin
     mk[i]^:=mk[k]^;
     mk[i]^[p]:=true;
    end;
  end;
end;

procedure closer;
begin
 writeln(fs,best[n]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.