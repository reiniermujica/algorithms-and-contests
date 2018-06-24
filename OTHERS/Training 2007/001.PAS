{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
     _/_/_/   _/_/_/
         _/ _/
    _/_/_/ _/
       _/ _/      IPVCE "Ernesto Guevara"
 _/_/_/   _/_/_/  Concurso Central de Computaci¢n 2003-2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ş P e s o                                       Copa Lenin 10mo grado
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En el almacen de la escuela todos los dias se tienen que pesar los distintos
productos que se utilizan para elaborar la comida, para ello el almacenero
tiene una pesa y discos de pesos distintos expresados en Kg; La  cantidad de
discos de un mismo peso es infinita.
Tarea escriba un programa que permita al almacenero conocer la menor cantidad
de discos que debe usar para pesar k Kg de un producto.

Fichero de entrada

El fichero de entrada PESO.IN contiene
- linea 1 un entero n (1<=n<=50), el numero de discos de pesos distintos
- linea 2 un entero k (1<=k<=100) el peso del producto que el
  almacenero entregara
- linea 3 hasta n+2 en cada una hay un entero que representa el peso
  de cada disco con que cuenta el almacenero(cada disco no sera mayor
  que 100 Kg)

Fichero de Salida

El fichero de salida PESO.OUT contiene  la lista de los discos a usar,
uno en cada linea

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄ¿
³ PESO.IN ³ ³ PESO.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄ´
³ 4       ³ ³ 2        ³
³ 12      ³ ³ 5        ³
³ 2       ³ ³ 5        ³
³ 5       ³ ÀÄÄÄÄÄÄÄÄÄÄÙ
³ 8       ³
³ 9       ³
ÀÄÄÄÄÄÄÄÄÄÙ






Nota la solucion no necesariamente es unica usted debe escribir una de
ellas
}

const
 max               = 101;

var
 fe,fs             : text;
 n,m               : longint;
 disk,best         : array[0..max] of byte;
 c                 : array[0..max] of longint;
 mk                : array[1..max] of boolean;

procedure open;
var
 i                 : byte;
begin
 assign(fe,'peso.in'); reset(fe);
 assign(fs,'peso.out'); rewrite(fs);
 readln(fe,m);
 readln(fe,n);
 for i:=1 to m do
  readln(fe,disk[i]);
 close(fe);
end;

procedure work;
var
 i,j               : longint;
begin
 fillchar(c,sizeof(c),127);
 mk[1]:=true; c[0]:=0;
 for i:=1 to n do
  if (mk[i]) then
   begin
     for j:=1 to m do
      begin
        if (n - i + 1 >= disk[j]) and (c[i+disk[j]-1] > c[i-1]) then
         begin
           mk[i+disk[j]]:=true;
           c[i+disk[j]-1]:=c[i-1] + 1;
           best[i+disk[j]-1]:=j;
         end;
      end;
   end;
end;

procedure closer;
var
 j,k               : longint;
begin
 k:=best[n]; j:=n;
 while k<>0 do
  begin
   writeln(fs,disk[k]);
   j:=j - disk[k];
   k:=best[j];
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.