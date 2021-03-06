{
 ID: Reinier C�sar Mujica Hern�ndez
 PROG: bigfact
 GRADO: 11
 CENTRO: IPVCE "Ernesto Guevara"
}

{Problema 12: Max Factor [Hal Burch, 2005]

Para mejorar la organizaci�n de su granja, el Granjero Juan rotula 
cada una de sus N (1 <= N <= 5,000) vacas con un n�mero serial 
distinto en el rango 1..20,000. Desafortunadamente, �l es incapaz de 
hacer que las vacas interpreten algunos n�meros seriales tan bien como 
otras. En particular, una vaca cuyo n�mero serial tenga el factor 
primo m�s grande disfruta la posici�n social m�s alta entre las otras 
vacas.

(Recuerde que un n�mero primo es simplemente un n�mero que no tenga 
divisores excepto 1 y el mismo. El n�mero 7 es un n�mero primo, 
mientras que el n�mero 6, siendo divisible por 2 y 3, no lo es).

Dado un conjunto de N (1 <= N <= 5,000) n�meros eriales en el rango 
1..20,000, determien aquel que tenga el factor primo m�s grande.

NOMBRE DEL PROBLEMA: bigfact

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, N

* L�neas 2..N+1: Los n�meros seriales a ser considerados, uno por
        l�nea.

ENTRADA EJEMPLO (archivo bigfact.in):

4
36
38
40
42

FORMATO DE SALIDA:

L�nea 1: El entero con el factor primo m�s grande. Si hay m�s de
        uno, de c�mo salida el que aparezca m�s temprano en el 
        archivo de entrada.


SALIDA EJEMPLO (archivo bigfact.out):

38

DETALLES DE LA SALIDA:

19 es un factor primo de 38. Ning�n otro numero tiene un factor primo 
m�s grande.
}

 {$I-,Q-,R-,S-}

var
 fe,fs                 : text;
 n,act,sol             : longint;

procedure open;
begin
 assign(fe,'bigfact.in'); reset(fe);
 assign(fs,'bigfact.out'); rewrite(fs);
 readln(fe,n);
end;

procedure work;
var
 i,j,k,s               : longint;
begin
 j:=-maxlongint; sol:=1;
 for i:=1 to n do
  begin
   readln(fe,act);
   k:=2; s:=act;
   while (act <> 1) do
    begin
     while (act mod k <> 0) do inc(k);
     act:=act div k;
     if k > j then
      begin
       j:=k;
       sol:=s;
      end;
    end;
  end;
end;

procedure closer;
begin
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
 closer;
end.