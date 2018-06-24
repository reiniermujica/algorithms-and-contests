 {$I-,Q-,R-,S-}

{Un número que se lee lo misma de derecha a izquierda que cuando se lee de
derecha a izquierda. El número 123231 es palíndromo, el número 777778 no lo
es. Por supuesto, los palíndromos no tienen ceros iniciales ni finales, por
lo tanto 0220 no es un palíndromo.

El número 21 (base 10) no es un palíndromo en base 10, pero el número 21
(base 10) es, de hecho, un palíndromo en base 2 (10101).

Escriba un programa que lea dos números (expresados en base 10):

    * N (1 <= N <= 15)
    * S (0 < S < 10000)

y encuentre e imprima (en base 10) los primeros N números estrictamente
mayores que S que son palíndromos cuando se escriben en dos o más baes
numéricas (2 <= base <= 10).

Las soluciones a este problema no requieren manipular enteros mayores que los
estándares de 32 bits.

NOMBRE DEL PROGRAMA: dualpal
FORMATO DE ENTRADA

Una sola línea con los enteros N y S separados por un espacio.
ENTRADA EJEMPLO (archivo dualpal.in)

3 25

FORMATO DE SALIDA
N líneas, cada una con un número en base 10 que es palíndromo cuando se
expresa en al menos dos bases 2..10. Los números deben estar impresos del
menor al mayor.

SALIDA EJEMPLO (archivo dualpal.out)

26
27
28

}

var
 fe,fs           : text;
 n,m             : longint;
 t1              : string;

procedure open;
begin
 assign(fe,'dualpal.in'); reset(fe);
 assign(fs,'dualpal.out'); rewrite(fs);
 readln(fe,m,n);
 close(fe);
end;

function palin(x : string) : boolean;
var
 a,b             : longint;
begin
 a:=1; b:=length(x);
 while (x[a] = x[b]) and (a < b) do
  begin
   inc(a);
   dec(b);
  end;
 if a>=b then palin:=true
        else palin:=false;
end;

function convert(n1,b : longint) : string;
var
 c                    : longint;
 res,tmp              : string;
begin
 res:='';
 while (n1 > 0) do
  begin
   c:=n1 mod b;
   str(c,tmp);
   res:=res + tmp;
   n1:=n1 div b;
  end;
 convert:=res;
end;

procedure work;
var
 i,k,cont           : longint;
begin
 k:=0;
 while (k < m) do
  begin
   inc(n); cont:=0;
   for i:=2 to 10 do
    begin
     t1:=convert(n,i);
     if palin(t1) then inc(cont);
    end;
   if (cont >= 2) then
    begin
     writeln(fs,n);
     inc(k);
    end;
  end;
 close(fs);
end;

begin
 open;
 work;
end.