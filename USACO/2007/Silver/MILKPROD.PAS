 {$I-,Q-,R-,S-}

{Problema 7: Tiempo Lechero [Jeffrey Wang, 2007]

Bessie es una vaca muy trabajadora. De hecho, ella est  tan enfocada
en maximizar su productividad que ella decide planificar sus
siguientes N (1 <= N <= 1,000,000) horas (convenientemente rotuladas
0..N-1) de tal manera que ella produzca tanta leche como sea posible.

El Granjero Juan tiene una lista de M (1 <= M <= 1,000) intervalos
posiblemente sobrelapados en los cuales ‚l est  disponible para
orde¤o. Cada intervalo i tiene una hora inicial (0 <= hora_inicial_i <
N), y hora de finalizaci¢n (hora_incial_i < hora_final_i <= N), y una
eficiencia correspondiente (1 <= eficiencia_i <= 1,000,000) la cual
indica cu ntos galones de leche ‚l puede obtener de Bessie en ese
intervalo. El Granejro Juan comienza y termina a orde¤ar al comienzo
de la hora inicial y al final de la hora final, respectivamente.
Cuando es orde¤ada, Bessie debe ser orde¤ada durante un intervalo
completo.

Sin embargo, a£n Bessie tiene sus limitaciones. Despu‚s de ser
orde¤ada durante cualquier intervalo, ella debe descansar R (1 <= R <=
N) horas antes de comenzar a ser orde¤ada nuevamente. Dada la lista de
intervalos del Granjero Juan, determine la m xima cantidad de leche
que Bessie puede producir en las N horas.

NOMBRE DEL PROBLEMA: milkprod

FORMATO DE ENTRADA:

* L¡nea 1: Tres enteros separados por espacios: N, M, y R.

* L¡neas 2..M+1: La l¡nea i+1 describe el intervalo i‚simo de GJ con
     tres enteros separados por espacios: hora_inicial_i,
     hora_final_i, y eficiencia_i

ENTRADA EJEMPLO (archivo milkprod.in):

12 4 2
1 2 8
10 12 19
3 6 24
7 10 31


DETALLES DE LA ENTRADA:

Bessie quiere planificar las siguientes 12 horas; el Granjero Juan
tiene 4 intervalos no sobrelapados en los cuales ‚l puede orde¤arla;
Bessie debe descansar 2 horas despu‚s de cada orde¤ada. El primer
intervalo va de la hora 1 a la hora 2, el segundo de la hora 10 a la
hora 12, el tercero de la hora 3 a la hora 6, y el cuarto de la hora 7
a la hora 10. El Granjero Juan puede obtener 8, 19, 24, y 31 galones
de leche, respectivamente, de Bessie en esos intervalos.

FORMATO DE SALIDA:

* L¡nea 1: El m ximo n£mero de galones de leche que Bessie puede
     producir en las N horas

SALIDA EJEMPLO (archivo milkprod.out):

43

DETALLES DE LA SALIDA:

Si Bessie usa el primer intervalo, ella no puede usar el tercero 
debido a que necesita 2 horas de descanso. Si usa el segundo, ella no 
puede usar el cuarto. Finalmente, si ella usa el tercero, ella no 
puede usar el cuarto. La mejor situaci¢n es elegir los intervalos
segundo y tercero, produciendo 43 galones de leche.
 }

const
 max                = 1001;

var
 fe,fs              : text;
 n,m,r,sol          : longint;
 tab                : array[0..max,1..3] of longint;
 best               : array[0..max] of longint;

procedure open;
var
 i                  : longint;
begin
 assign(fe,'milkprod.in'); reset(fe);
 assign(fs,'milkprod.out'); rewrite(fs);
 readln(fe,n,m,r);
 for i:=1 to m do
  readln(fe,tab[i,1],tab[i,2],tab[i,3]);
 close(fe);
end;

procedure qsort(ini,fin,p : longint);
var
 i,j,k                    : longint;
begin
 i:=ini; j:=fin; k:=tab[(i+j) div 2,p];
 repeat
  while tab[i,p] < k do inc(i);
  while tab[j,p] > k do dec(j);
  if i<=j then
   begin
    tab[0]:=tab[i]; tab[i]:=tab[j]; tab[j]:=tab[0];
    inc(i); dec(j);
   end;
 until i>j;
 if i<fin then qsort(i,fin,p);
 if j>ini then qsort(ini,j,p);
end;

procedure work;
var
 i,j,act          : longint;
begin
 qsort(1,m,2);  { A lo mejor se puede eliminar un qsort }
 qsort(1,m,1);  {  no probe, pero asi da en tiempo }
 sol:=0;
 for i:=m downto 1 do
  begin
   act:=0; best[i]:=tab[i,3];
   for j:=i+1 to m do
    begin
     if (tab[i,2]+r <= tab[j,1]) and (best[j] > act) then
      act:=best[j];
    end;
   best[i]:=best[i] + act;
   if best[i] > sol then sol:=best[i];
  end;
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
end.