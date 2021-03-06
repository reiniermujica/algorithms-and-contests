 {$I-,Q-,R-,S-}

{Un n�mero que se lee lo misma de derecha a izquierda que cuando se lee de
derecha a izquierda. El n�mero 123231 es pal�ndromo, el n�mero 777778 no lo
es. Por supuesto, los pal�ndromos no tienen ceros iniciales ni finales, por
lo tanto 0220 no es un pal�ndromo.

El n�mero 21 (base 10) no es un pal�ndromo en base 10, pero el n�mero 21
(base 10) es, de hecho, un pal�ndromo en base 2 (10101).

Escriba un programa que lea dos n�meros (expresados en base 10):

    * N (1 <= N <= 15)
    * S (0 < S < 10000)

y encuentre e imprima (en base 10) los primeros N n�meros estrictamente
mayores que S que son pal�ndromos cuando se escriben en dos o m�s baes
num�ricas (2 <= base <= 10).

Las soluciones a este problema no requieren manipular enteros mayores que los
est�ndares de 32 bits.

NOMBRE DEL PROGRAMA: dualpal
FORMATO DE ENTRADA

Una sola l�nea con los enteros N y S separados por un espacio.
ENTRADA EJEMPLO (archivo dualpal.in)

3 25

FORMATO DE SALIDA
N l�neas, cada una con un n�mero en base 10 que es pal�ndromo cuando se
expresa en al menos dos bases 2..10. Los n�meros deben estar impresos del
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