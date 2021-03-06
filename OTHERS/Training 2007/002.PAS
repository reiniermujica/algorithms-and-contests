 {$I-,Q-,R-,S-}

{컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
     _/_/_/   _/_/_/
         _/ _/
    _/_/_/ _/     T o p e   v s   L e n i n
       _/ _/      IPVCE "Ernesto Guevara", Ju 14/Dic
 _/_/_/  _/_/_/   Concurso Central de Computaci줻  Y2K-'01
컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴
  Once y Doce Grados                              P r o b l e m a   A
컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴

� Construyendo con Bloques.
  Tiempo L죑ite de Ejecuci줻 : 5 sgdos a 40 MHz.

Las alumnos quieren construir una torre con bloques que ellos
encontraron. Ellos quieren decirle a usted como ser� la altura de la
torre, d쟮dole los tama쨚s de los bloques. Cada bloque con una unidad
de altura tiene un ancho y una longitud. Los bloques tienen que estar
amontonados con todas sus aristas paralelas al conjunto de axisas y
los bloques pueden ser rotados 90 grados, si usted lo desea. Para
construir una torre estable, cada bloque m쟳 alto no puede ser m쟳
largo  que el bloque sobre el cual 굃 descansa (el ancho y la longitud
de cada bloque m쟳 alto no puede ser mayor que el ancho y la longitud
de los bloques sobre los cuales el descansa.

Su tarea es determinar la altura de la torre estable m쟳 alta posible
que puede ser constru죆a con la colecci줻 dada de bloques.

Entrada

L죒ea 1: un entero B, 1 <= B <= 100, el n즡ero de bloques.
L죒ea 2 .. B+1: B l죒eas, cada una con dos enteros denotando el ancho
         y la longitud de un bloque cuadrado. Cada una de estas
         dimensiones es al menos una unidad y como m쟸imo 100
         unidades. Los bloques ser쟮 numerados a partir del n즡ero 1
         seg즢 el orden en que aparezcan.

Salida

El fichero de salida contendr� en la primera l죒ea un entero B,
indicando el n즡ero de bloques que tendr� la torre estable m쟳 alta
posible. En las pr쥅imas B l죒eas aparecer쟮 en cada una un entero
indicando el n즡ero del bloque que fue ubicado en la torre estable.
Los bloques ser쟮 ubicados desde la base hasta la cima de la torre.

旼컴컴컴컴컴컴컴컴커 旼컴컴컴컴컴컴컴컴�
� BLOQUES.IN       � � BLOQUES.OUT     �
쳐컴컴컴컴컴컴컴컴캑 쳐컴컴컴컴컴컴컴컴�
� 5                � � 4               �
� 3 7              � � 4               �
� 4 5              � � 2               �
� 4 5              � � 3               �
� 5 6              � � 5               �
� 2 2              � 읕컴컴컴컴컴컴컴컴�
읕컴컴컴컴컴컴컴컴켸
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