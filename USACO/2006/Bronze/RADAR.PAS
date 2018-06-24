 {$I-,Q-,R-,S-}

{Problema 12: Marcas RADAR [Tradicional, 2006]

GJ ha estado marcando las vacas con un n£mero serial. Est n de moda
las marcas `RADAR`, llamadas as¡ porque ellas se leen igual hacia
delante y hacia atr s: ellas son pal¡ndromos. Todas las vacas quieren
que sus hijas sean marcadas con el nuevo estilo. 

Cada madre quiere que la marca de su hija sea derivada de su propia 
marca no-RADAR sumando la marca de la madre y su reversa. Algunas 
veces (por ejemplo, 12 + 21 = 33) esto da directamente un pal¡ndromo.
Algunas veces el proceso debe ser repetido varias veces hasta que 
aparezca la marca RADAR. Considere la marca '87' que requiere cuatro 
pasos para convertirse en una marca RADAR:


          Marca    Reverso Suma
   Paso 1:   87 +    78 =  165
   Paso 2:  165 +   561 =  726
   Paso 3:  726 +   627 = 1353
   Paso 4: 1353 +  3531 = 4884

Dada la marca de la madre (un entero positivo), determine el n£mero de
pasos y la marca RADAR que resulte de aplicar el procedimiento 
descrito. Ninguna respuesta ser  mayor que dos billones.


NOMBRE DEL PROBLEMA: radar

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero, la marca de la madre no pal¡ndromo.


ENTRADA EJEMPLO (archivo radar.in):

87

FORMATO DE SALIDA:

* L¡nea 1: Dos enteros separados por espacio, que son
     respectivamente: el n£mero de pasos para encontrar la marca RADAR y
     la marca RADAR encontrada.

SALIDA EJEMPLO (archivo radar.out):

4 4884
}

var
 fe,fs              : text;
 n,m,sol            : longint;
 st,t               : string;
 c                  : integer;

procedure open;
begin
 assign(fe,'radar.in'); reset(fe);
 assign(fs,'radar.out'); rewrite(fs);
 readln(fe,n);
 close(fe);
end;

function palin(x : string) : boolean;
var
 i,j             : longint;
begin
 j:=length(x);
 for i:=1 to (j div 2) do
  if (x[i] <> x[j-i+1]) then
   begin
    palin:=false;
    exit;
   end;
 palin:=true;
end;

procedure work;
var
 i,j,k,x,y          : longint;
begin
 sol:=0;
 str(n,st);
 while (not palin(st)) do
  begin
   inc(sol);
   k:=length(st); t:='';
   for i:=k downto 1 do
    begin
     t:=t + st[i];
    end;
   val(st,x,c);
   val(t,y,c);
   j:=x + y;
   str(j,st);
  end;
end;

procedure closer;
begin
 writeln(fs,sol,' ',st);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.