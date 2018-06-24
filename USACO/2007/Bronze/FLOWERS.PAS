 {$I-,Q-,R-,S-}

{Problema 12: Jardín de Flores [Rob Kolstad, 2007]

Imagine la sorpresa de Betsy cuando ella rodeó el establo y encontró que 
le Granjero Juan ha construido un invernadero secreto que ahora tiene 
flores maravillosas. Su mente corrió rápidamente y se llenó de visiones 
de un florido jardín en su pequeña mente bovina.

“Yo pienso que haré una larga fila de F (7 <= F <= 10,000) flores contra 
la cerca”, ella pensó. “Plantaré rosas en cada tercer hoyo, begonias en
cada séptimo hoyo que aún estén disponibles, y margaritas en cada cuarto 
hoyo que aún esté disponible.” Betsy pensaba cuántos hoyos abiertos 
quedarían. Ella se dio cuenta que el número dependería en cual hoyo ella 
comenzaría a plantar cuando ella intentara llenar cada eNésimo hoyo con 
una clase de flores.

Ayude a Betsy a saber cuantos hoyos abiertos quedaran. Lea un conjunto de 
K (1 <= K <= 100) descriptores de plantaciones, cada uno de los cuales 
dice una ubicación inicial L (1 <= L <= F) -- L=1 es la primera flor -- y 
un intervalo I (1 <= I <= F) para plantar flores. Deduzca el número de 
hoyos vacíos que permanecerán libres después de plantar todo el conjunto.

Si Betsy siguió su visión original, ella podría especificar la plantación
como sigue:

      30 3     [30 hoyos en total; 3 clases de flores]
      1 3      [comenzar en el hoyo 1 y plantar rosas cada tercer hoyo]
      3 7      [comenzar en el hoyo 3 y plantar begonias cada séptimo
hoyo]
      1 4      [comenzar en el hoyo 1 y plantar margaritas cada cuarto
hoyo]

Por lo tanto, el jardín vacío se vería como esto:

. . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
Luego, después de plantar las rosas:
     R . . R . . R . . R . . R . . R . . R . . R . . R . . R . .
Luego, después de plantar las begonias:
     R . B R . . R . . R . . R . . R B . R . . R . B R . . R . .
Luego, después de plantar las margaritas:
     R . B R M . R . M R . . R . . R B . R . M R . B R . . R M .

Quedan 13 hoyos vacíos después de la plantación

NOMBRE DEL PROBLEMA: flowers

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio: N y K.

*Líneas 2..K+1: La línea j contiene dos enteros separados por espacio que
        especifican la plantación de una clase de flor: L_j y I_j

ENTRADA EJEMPLO (archivo flowers.in):

30 3
1 3
3 7
1 4

DETALLES DE LA ENTRADA

Como en el texto del problema

FORMATO DE SALIDA:

* Línea 1: Una sola línea con un solo entero que es el número de hoyos
que
         permanecen vacíos después de completar la plantación.

SALIDA EJEMPLO (archivo latin.out):

13

DETALLE DE LA SALIDA

Como en el texto
 }

const
 mx             = 10001;

var
 fe,fs          : text;
 n,m,sol        : longint;
 mk             : array[1..mx] of boolean;

procedure open;
begin
 assign(fe,'flowers.in'); reset(fe);
 assign(fs,'flowers.out'); rewrite(fs);
 readln(fe,n,m);
end;

procedure work;
var
 i,j,k          : longint;
begin
 sol:=0;
 for i:=1 to m do
  begin
   readln(fe,j,k);
   while j <= n do
    begin
     if not mk[j] then
      begin
       mk[j]:=true;
       inc(sol);
      end;
     j:=j + k;
    end;
  end;
end;

procedure closer;
begin
 writeln(fs,n-sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.