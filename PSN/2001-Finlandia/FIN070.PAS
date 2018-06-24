  {$I-,Q-,R-,S-}

{70¦ Comprando Frutas.                                   Finlandia 2001
----------------------------------------------------------------------

Un eminente profesor de matemáticas tenía la siguiente costumbre:
cuando  iba  de compras (comprando frutas, por ejemplo naranjas), a él
le  gustaba  comprar exactamente 1 kg si esto fuera posible. Un alumno
suyo  decidió  hacer  lo  mismo.  El  profesor  podía  hacer todos los
cálculos  necesarios  en  la  mente, pero el estudiante debe llevar su
computadora.

Cuando el estudiante va a comprar, él puede pesar todas las frutas.
Crear  un programa en el cual el estudiante debe introducir el peso de
las  frutas pesadas en gramos. El programa debe terminar si es posible
que  el  estudiante compre 1 kg exacto de frutas y si puede determinar
una  combinación  de  los  pesos  de  las  frutas,  que  cumpla con la
condición.

Entrada

En  la  primera  fila del archivo de entrada FRUITS.IN está escrito el
número N de frutas, donde 1 <= N <= 50. En las siguientes N filas está
escrito  un  número entero (el peso de cada fruta), cada uno entre 1 y
1000.

Salida

Se escribirá en el archivo de salida FRUITS.OUT:
La  cadena  "No",  si  es  imposible comprar exactamente 1 kg. En caso
contrario  escriba  los pesos de la combinaciún determinada (cuya suma
es igual a 1000), escribiendo un número por fila.

+-----------+ +------------+
¦ FRUITS.IN ¦ ¦ FRUITS.OUT ¦
+-----------¦ +------------¦
¦ 5         ¦ ¦ 500        ¦
¦ 200       ¦ ¦ 200        ¦
¦ 300       ¦ ¦ 300        ¦
¦ 200       ¦ +------------+
¦ 400       ¦
¦ 500       ¦
+-----------+
 }

const
 mx             = 1001;

var
 fe,fs          : text;
 n              : longint;
 tab,sav,link   : array[1..mx] of longint;
 mk             : array[1..mx] of boolean;

procedure open;
begin
 assign(fe,'fruits.in'); reset(fe);
 assign(fs,'fruits.out'); rewrite(fs);
 readln(fe,n);
end;

procedure closer(x : longint);
var
 i                 : longint;
begin
 writeln(fs,sav[x]);
 i:=link[x];
 while (i <> 0) do
  begin
   writeln(fs,sav[i]);
   i:=link[i];
  end;
 close(fs);
 close(fe);
 halt;
end;

procedure work;
var
 i,j,k,t,c        : longint;
begin
 readln(fe,tab[1]);
 k:=1; sav[1]:=tab[1]; mk[tab[1]]:=true;
 for i:=2 to n do
  begin
   readln(fe,c); t:=k;
   for j:=1 to k do         { Meto los objetos en la mochila }
    begin
     if (tab[j] + c <= 1000) and (not mk[tab[j] + c]) then
      begin
       inc(t);
       tab[t]:=tab[j] + c;
       sav[t]:=c;
       link[t]:=j;
       mk[tab[j] + c]:=true;
       if tab[t]=1000 then
        closer(t);
      end;
    end;
   if (not mk[c]) then     { Si el objeto actual no esta lo meto }
    begin
     k:=t + 1;
     tab[k]:=c;
     sav[k]:=c;
     if tab[k]=1000 then
      closer(k);
    end
   else
    k:=t;
  end;
 writeln(fs,'NO');          { Si no hay solucion }
 close(fs);
 close(fe);
end;

begin
 open;
 work;
end.