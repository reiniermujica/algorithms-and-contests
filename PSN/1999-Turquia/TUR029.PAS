{$A+,B-,D+,E+,F-,G-,I-,L+,N+,O-,P-,Q-,R-,S-,T-,V-,X+,Y+}
{$M 65384,0,655360}
{29ş Compre barato y Compre m s barato                     Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  anuncio  de " compre  barato"  es  la  f¢rmula  del  ‚xito  en los
supermercados. Pero para  ser  considerado  un  gran  comprador  usted
tambi‚n tiene que seguir la premisa de: "Comprar barato, pero aun m s
barato".

Esto es, cada vez que  usted  compre un producto, este tiene que tener
un precio m s barato que la £ltima vez que usted compr¢ un producto.
Mientras m s  veces usted compre a menos precio usted ser  considerado
un mejor comprador.

A usted le ser n dados los precios diarios de venta de un producto por
muchos d¡as. Usted  puede comprar m s de una vez un producto en varios
d¡as; recuerde que  cada  vez  que usted compre el producto, el precio
debe ser menor que el d¡a previo que usted compr¢ el producto.

Su  tarea  ser   escribir  un programa el cual identifique cu les d¡as
usted  debe  comprar  un  producto (siguiendo  la  regla  del  p rrafo
anterior) para maximizar el n£mero de veces que usted comprar .

Por ejemplo, suponga que en d¡as sucesivos los precios de  venta de un
producto son:

D¡a      1  2  3  4  5  6  7  8  9 10 11 12
Precio  68 69 54 70 68 64 70 62 67 78 98 87

En el ejemplo de arriba, el mejor puede comprar como m ximo 4 veces si
sigue la regla de que cada compra tiene un precio menor que la previa.
Los cuatro d¡as en esta secuencia son:

D¡a     4  5  6  8     ¢     D¡a     2  5  6  8
Precio 70 68 64 62           Precio 69 68 64 62

Archivo de Entrada

Contiene en la primera l¡nea el n£mero N  de d¡as (1 <= N <= 5000). En
las pr¢xim s N l¡neas en cada una se  escribir   el  precio (un entero
positivo) del producto en cada d¡a.

Archivo de Salida

Contendr  en una l¡nea dos enteros positivos  separados por un espacio
en blanco. El primero la longitud de la secuencia m s larga de precios
decrecientes. El  segundo, el n£mero  de  secuencias  que  tienen  esa
longitud. Dos soluciones  son consideradas iguales si ellas repiten la
misma cadena de precios descendentes  aunque  sean encontradas en d¡as
diferentes.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de Entrada ³ ³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 12                 ³ ³ 4 2               ³
³ 68                 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 69                 ³
³ 54                 ³
³ 70                 ³
³ 68                 ³
³ 64                 ³
³ 70                 ³
³ 62                 ³
³ 67                 ³
³ 78                 ³
³ 98                 ³
³ 87                 ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}

var
 fe,fs                  : text;
 n,sol,max              : integer;
 a,res,c                : array[1..5001] of integer;

procedure open;
begin
 assign(fe,'tur029.in'); reset(fe);
 assign(fs,'tur029.out'); rewrite(fs);
end;

procedure work;
var
 i,j,p,s                : integer;
begin
 sol:=0; max:=0;
 readln(fe,n);
 for i:=n downto 1 do
  begin
   c[i]:=1;
   readln(fe,a[i]);
   for j:=i+1 to n do
    if (a[i] < a[j]) then
      begin
       if (res[j] > res[i]) then
        begin
         res[i]:=res[j];
         c[i]:=c[j];
         p:=a[j];
        end
        else
       if (res[i] = res[j]) and (a[j] <> p) then
        begin
         c[i]:=c[i] + c[j];
         p:=a[j];
        end;
      end;
   inc(res[i]);
   if res[i] > sol then
    begin
     sol:=res[i];
     max:=c[i];
     s:=i;
    end
    else
   if (res[i]=sol) and (a[s] <> a[i]) then
    max:=max + c[i];
  end;
 close(fe);
end;

procedure closer;
begin
 writeln(fs,sol,' ',max);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.