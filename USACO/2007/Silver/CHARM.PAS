  {$I-,Q-,R-,S-}

{Problema 6: Brazalete de Dijes [Kolstad/Cox, 2006]

Bessie ha ido a la joyería del centro comercial y ha visto un
brazalete de dijes. Por supuesto, ella quisiera llenarlo con los
mejores dijes posibles de N (1 &lt;= N &lt;= 3,402) dijes disponibles. Cada
dije i tiene un peso W_i (1 &lt;= W_i &lt;= 400) y una factor de
'deseabilidad'  D_i (1 &lt;= D_i &lt;= 100). Bessie puede únicamente soporta
un brazalete de dijes cuyo peso sea menor que M (1 &lt;= M &lt;= 12,880).

Dado el peso límite como una restricción y una lista de los dijes con
sus pesos y factores de deseabilidad, deduzca la mayor suma posible de
deseabilidades.

NOMBRE DEL PROBLEMA: charm

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio: N y M

* Líneas 2..N+1: La línea i+1 describe el dije i con dos enteros
     separados por espacio: W_i y D_i

ENTRADA EJEMPLO (archivo charm.in):

4 6
1 4
2 6
3 12
2 7

DETALLES DE LA ENTRADA:

Cuatro dijes potenciales, peso máximo 6

FORMATO DE SALIDA:

* Línea 1: Un solo entero que es la suma más grande de deseabilidades
     de dijes que puede ser obtenida dadas las restricciones de peso

SALIDA EJEMPLO (archivo charm.out):

23

DETALLES DE LA SALIDA:

Sin el segundo dije posible, el valor 4+12+7=23 es el valor más alto
con un peso 1+2+3&lt;=6
 }

const
 mx                = 13001;

var
 fe,fs             : text;
 n,m,sol           : longint;
 best              : array[0..mx] of longint;

procedure open;
begin
 assign(fe,'charm.in'); reset(fe);
 assign(fs,'charm.out'); rewrite(fs);
 readln(fe,m,n);
end;

function max(n1,n2 : longint) : longint;
begin
 if n1 > n2 then max:=n1
            else max:=n2;
end;

procedure work;
var
 i,j,zi,va         : longint;
begin
 for i:=1 to m do        { metiendo el i-esimo objeto }
  begin
   readln(fe,zi,va);
   for j:=n downto 1 do  { metiendolo en todos los tama¤os }
    begin
     if (best[j] <> 0) and (j + zi <= n) then
      best[j + zi]:=max(best[j] + va,best[j + zi]);
    end;
   if (best[zi] < va) then best[zi]:=va;
  end;
 sol:=0;
 for i:=1 to n do
  sol:=max(sol,best[i]);
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