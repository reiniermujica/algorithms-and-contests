 {$I-,Q-,R-,S-}

{Viernes Trece
Es Viernes 13 realmente un evento poco usual?

Esto es, el 13 del mes cae en un Viernes menos frecuentemente que cualquier
otro d�a de la semana? Para responder esta pregunta, escriba un programa que
calcular� la frecuencia con que el 13 de cada mes cae en Domingo, Lunes,
Martes, Mi�rcoles, Jueves, Viernes, y S�bado sobre un per�odo dado de N a�os.
El per�odo de tiempo a examinar ser� desde el 1 de Enero de 1900 al 31 de
Diciembre de 1900+N+1 para un n�mero dado de a�os N. N es un n�mero no
negativo y no exceder� 400.

Hay unos pocos hechos que usted debe conocer antes de resolver este problema:

El 1 de Enero de 1900 fue un Lunes.
Septiembre, Abril, Junio y Noviembre tienen 30 d�as, todos los dem�s tienen
31 excepto Febrero el cual tiene 28 d�as excepto en los a�os bisiestos los
cuales tienen 29
Cada a�o divisible por 4 es un a�o bisiesto (1992=4*498, por lo tanto 1992
es un a�o bisiesto, pero 1990 no es un a�o bisiesto)
La anterior regla no se cumple para a�os de siglo. Los a�os de siglo
divisibles por 400 son bisiestos, los otros no. Por lo tanto los a�os de siglo
1700, 1800, 1900 y 2100 no son bisiestos, pero 2000 si es bisiesto.
No use ninguna funci�n de fecha en su lenguaje de programaci�n.

Tampoco precalcule las respuestas, por favor.

NOMBRE DEL PROGRAMA: friday

FORMATO DE ENTRADA

Una l�nea con el entero N.

ENTRADA EJEMPLO (archivo friday.in)

20

FORMATO DE SALIDA

Siete enteros separados por espacio en una l�nea. Estos enteros representan
el n�mero de veces que el 13 cae en S�bado, Domingo, Lunes, Martes,..,Viernes

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