 {$I-,Q-,R-,S-}

{ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
     _/_/_/   _/_/_/
         _/ _/
    _/_/_/ _/     T o p e   v s   L e n i n
       _/ _/      IPVCE "Ernesto Guevara", Ju 14/Dic
 _/_/_/  _/_/_/   Concurso Central de Computaci¢n  Y2K-'01
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
  Once y Doce Grados                              P r o b l e m a   A
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

ş Construyendo con Bloques.
  Tiempo L¡mite de Ejecuci¢n : 5 sgdos a 40 MHz.

Las alumnos quieren construir una torre con bloques que ellos
encontraron. Ellos quieren decirle a usted como ser  la altura de la
torre, d ndole los tama¤os de los bloques. Cada bloque con una unidad
de altura tiene un ancho y una longitud. Los bloques tienen que estar
amontonados con todas sus aristas paralelas al conjunto de axisas y
los bloques pueden ser rotados 90 grados, si usted lo desea. Para
construir una torre estable, cada bloque m s alto no puede ser m s
largo  que el bloque sobre el cual ‚l descansa (el ancho y la longitud
de cada bloque m s alto no puede ser mayor que el ancho y la longitud
de los bloques sobre los cuales el descansa.

Su tarea es determinar la altura de la torre estable m s alta posible
que puede ser constru¡da con la colecci¢n dada de bloques.

Entrada

L¡nea 1: un entero B, 1 <= B <= 100, el n£mero de bloques.
L¡nea 2 .. B+1: B l¡neas, cada una con dos enteros denotando el ancho
         y la longitud de un bloque cuadrado. Cada una de estas
         dimensiones es al menos una unidad y como m ximo 100
         unidades. Los bloques ser n numerados a partir del n£mero 1
         seg£n el orden en que aparezcan.

Salida

El fichero de salida contendr  en la primera l¡nea un entero B,
indicando el n£mero de bloques que tendr  la torre estable m s alta
posible. En las pr¢ximas B l¡neas aparecer n en cada una un entero
indicando el n£mero del bloque que fue ubicado en la torre estable.
Los bloques ser n ubicados desde la base hasta la cima de la torre.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ BLOQUES.IN       ³ ³ BLOQUES.OUT     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5                ³ ³ 4               ³
³ 3 7              ³ ³ 4               ³
³ 4 5              ³ ³ 2               ³
³ 4 5              ³ ³ 3               ³
³ 5 6              ³ ³ 5               ³
³ 2 2              ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 }

const
 mx               = 101;

var
 fe,fs            : text;
 n,k,sol          : longint;
 tab              : array[1..mx,1..3] of longint;
 best,cam,res     : array[1..mx] of longint;

procedure swap(var n1,n2 : longint);
var
 t                       : longint;
begin
 t:=n1; n1:=n2; n2:=t;
end;

procedure open;
var
 i                : longint;
begin
 assign(fe,'bloques.in'); reset(fe);
 assign(fs,'bloques.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  begin
   readln(fe,tab[i,1],tab[i,2]);
   if tab[i,1] > tab[i,2] then
    swap(tab[i,1],tab[i,2]);
   tab[i,3]:=i;
  end;
 close(fe);
end;

procedure qsort(ini,fin,p : longint);
var
 i,j,k                    : longint;
begin
 i:=ini; j:=fin; k:=tab[(i+j) div 2,p];
 repeat
  while (tab[i,p] < k) do inc(i);
  while (tab[j,p] > k) do dec(j);
  if i<=j then
   begin
    swap(tab[i,1],tab[j,1]);
    swap(tab[i,2],tab[j,2]);
    swap(tab[i,3],tab[j,3]);
    inc(i); dec(j);
   end;
 until i>j;
 if (i < fin) then qsort(i,fin,p);
 if (j > ini) then qsort(ini,j,p);
end;

procedure build;
var
 i,j,l                  : longint;
begin
 qsort(1,n,1); l:=tab[1,1]; j:=1;
 for i:=2 to n do
  begin
   if tab[i,1] <> l then
    begin
     qsort(j,i-1,2);
     l:=tab[i,1];
     j:=i;
    end;
  end;
end;

procedure work;
var
 i,j                    : longint;
begin
 build;
 sol:=0; k:=1;
 for i:=n-1 downto 1 do
  begin
   best[i]:=0;
   for j:=i+1 to n do
    begin
     if (tab[i,1] <= tab[j,1]) and (tab[i,2] <= tab[j,2])
      and (best[j] + 1 > best[i]) then
       begin
        best[i]:=best[j] + 1;
        cam[i]:=j;
       end;
    end;
   if best[i] > sol then
    begin
     sol:=best[i];
     k:=i;
    end;
  end;
end;

procedure closer;
var
 i,j                    : longint;
begin
 writeln(fs,sol+1);
 res[1]:=tab[k,3]; j:=1;
 while cam[k] <> 0 do
  begin
   inc(j);
   res[j]:=tab[cam[k],3];
   k:=cam[k];
  end;
 for i:=sol+1 downto 1 do
  writeln(fs,res[i]);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.