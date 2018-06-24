 {$I-,Q-,R-,S-}

{Problema 13: Soñar Contando [Rob Kolstad, 2006]

Bessie estaba dormitando en el d¡a un d¡a en que ella estaba entre el
cansancio y esa deliciosa pereza que todos sentimos cuando estamos 
cansados. Por un momento, ella cont¢ ovejas y no pudo dormir. La mente de
Bessie es afilada y visualiza los n£meros conforme ella va contando. Ella
comenz¢ a darse cuenta de los d¡gitos y pens¢: ¿Cu ntas instancias de
cada d¡gito aparecen en una secuencia de conteo?

Escriba un programa que responda esta pregunta. Dados dos enteros M y N 
(1 &lt;= M &lt;= N &lt;= 2,000,000,000 y N-M &lt;= 500,000), ¿cu ntas ocurrencias de
cada d¡gito aparecen?

Considere la secuencia: 129..137: 129, 130, 131, 132, 133, 134, 135, 136,
137. Cuente los d¡gitos para encontrar:

   1x0      1x5
  10x1      1x6
   2x2      1x7
   9x3      0x8
   1x4      1x9

NOMBRE DEL PROBLEMA: dream

FORMATO DE ENTRADA:

* L¡nea 1: Dos enteros separados por espacio: M y N

Entrada Ejemplo (archivo dream.in):

129 137

FORMATO DE SALIDA:

* L¡nea 1: Diez enteros separados por espacios que son el n£mero de veces
      que cada d¡gito (0..9) aparece cuando se cuenta a trav‚s de la
      secuencia. 

ARCHIVO EJEMPLO (archivo dream.out):

1 10 2 9 1 1 1 1 0 1


DETALLES DE LA SALIDA:

Un cero, diez unos, etc.
}

var
 fe,fs          : text;
 n,m            : longint;
 c              : integer;
 sol            : array[0..9] of longint;

procedure open;
begin
 assign(fe,'dream.in'); reset(fe);
 assign(fs,'dream.out'); rewrite(fs);
 readln(fe,n,m);
 close(fe);
end;

procedure work;
var
 i,act,j        : longint;
 st             : string;
begin
 fillchar(sol,sizeof(sol),0);
 for i:=n to m do
  begin
   str(i,st);
   for j:=1 to length(st) do
    begin
     val(st[j],act,c);
     inc(sol[act]);
    end;
  end;
end;

procedure closer;
var
 i             : longint;
begin
 for i:=0 to 9 do
  write(fs,sol[i],' ');
 close(fs);
end;

begin
 open;
 work;
 closer;
end.