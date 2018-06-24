 {$I-,Q-,R-,S-}

{Viernes Trece
Es Viernes 13 realmente un evento poco usual?

Esto es, el 13 del mes cae en un Viernes menos frecuentemente que cualquier
otro día de la semana? Para responder esta pregunta, escriba un programa que
calculará la frecuencia con que el 13 de cada mes cae en Domingo, Lunes,
Martes, Miércoles, Jueves, Viernes, y Sábado sobre un período dado de N años.
El período de tiempo a examinar será desde el 1 de Enero de 1900 al 31 de
Diciembre de 1900+N+1 para un número dado de años N. N es un número no
negativo y no excederá 400.

Hay unos pocos hechos que usted debe conocer antes de resolver este problema:

El 1 de Enero de 1900 fue un Lunes.
Septiembre, Abril, Junio y Noviembre tienen 30 días, todos los demás tienen
31 excepto Febrero el cual tiene 28 dìas excepto en los años bisiestos los
cuales tienen 29
Cada año divisible por 4 es un año bisiesto (1992=4*498, por lo tanto 1992
es un año bisiesto, pero 1990 no es un año bisiesto)
La anterior regla no se cumple para años de siglo. Los años de siglo
divisibles por 400 son bisiestos, los otros no. Por lo tanto los años de siglo
1700, 1800, 1900 y 2100 no son bisiestos, pero 2000 si es bisiesto.
No use ninguna función de fecha en su lenguaje de programación.

Tampoco precalcule las respuestas, por favor.

NOMBRE DEL PROGRAMA: friday

FORMATO DE ENTRADA

Una línea con el entero N.

ENTRADA EJEMPLO (archivo friday.in)

20

FORMATO DE SALIDA

Siete enteros separados por espacio en una línea. Estos enteros representan
el número de veces que el 13 cae en Sábado, Domingo, Lunes, Martes,..,Viernes

SALIDA EJEMPLO (archivo friday.out)

36 33 34 33 35 35 34
}

const
 max          = 7;
 mes          : array[1..12] of byte=
  (31,28,31,30,31,30,31,31,30,31,30,31);

var
 fe,fs        : text;
 n            : longint;
 sol          : array[1..max] of longint;

procedure open;
begin
 assign(fe,'friday.in'); reset(fe);
 assign(fs,'friday.out'); rewrite(fs);
 readln(fe,n);
 close(fe);
end;

function bis(x : longint) : boolean;
begin
 bis:=false;
 if (x mod 4 = 0) and ((x mod 100 <> 0) or (x mod 400 = 0)) then
  bis:=true
end;

procedure work;
var
 act,i,j,k        : longint;
begin
 act:=2;
 for i:=1900 to 1900+n-1 do
  begin
   if bis(i) then
    mes[2]:=29;
   for j:=1 to 12 do
    begin
     for k:=1 to mes[j] do
      begin
       if act = 7 then
        act:=1
       else
        inc(act);
       if k = 13 then
        inc(sol[act]);
      end;
    end;
   mes[2]:=28;
  end;
end;

procedure closer;
var
 i      : longint;
begin
 for i:=1 to 7 do
  write(fs,sol[i],' ');
 close(fs);
end;

begin
 open;
 work;
 closer;
end.