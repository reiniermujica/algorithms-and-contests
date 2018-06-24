 {$I-,Q-,R-,S-}

{Cuadrados Palíndrómicos

Los palíndromos son números que se leen igual hacia adelante que hacia atrás.
El número 12321 es un palíndromo típico.

Dada una base numérica B (2 <= B <= 20 base 10), imprima todos los enteros
N (1 <= N <= 300 base 10) tales que el cuadrado de N es un palíndromo cuando
se expresa en base B; también imprima el valor de ese cuadrado palíndromo.
Use las letras 'A', 'B', y sucesivas para representar los números 10, 11, y
sucesivos.

Imprima ambos el número y su cuadrado en base B.

NOMBRE DEL PROGRAMA: palsquare

FORMATO DE ENTRADA

Una sola línea con B, la base (especificado en base 10).
ENTRADA EJEMPLO (archivo palsquare.in)

10

FORMATO DE SALIDA

Líneas con dos enteros representados en base B. El primer entero es el número
cuyo cuadrado es palíndromo; el segundo entero es el cuadrado en sí.

SALIDA EJEMPLO (archivo palsquare.out)

1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
}

var
 fe,fs           : text;
 n               : longint;
 cad,t1,t2       : string;

procedure open;
begin
 assign(fe,'palsquare.in'); reset(fe);
 assign(fs,'palsquare.out'); rewrite(fs);
 readln(fe,n);
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

function convert(n1 : longint) : string;
var
 c                  : longint;
 res                : string;
begin
 res:='';
 while (n1 > 0) do
  begin
   c:=n1 mod n;
   res:=res + cad[c + 1];
   n1:=n1 div n;
  end;
 convert:=res;
end;

procedure work;
var
 i,j                : longint;
begin
 cad:='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';
 for i:=1 to 300 do
  begin
   t1:=convert(sqr(i));
   if palin(t1) then
    begin
     t2:=convert(i);
     for j:=length(t2) downto 1 do
      write(fs,t2[j]);
     write(fs,' ');
     for j:=length(t1) downto 1 do
      write(fs,t1[j]);
     writeln(fs);
    end;
  end;
 close(fs);
end;

begin
 open;
 work;
end.