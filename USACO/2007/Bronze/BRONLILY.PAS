{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{Problema 12: Estanque de Nenúfares Bronce [Ho/Kolstad, 2007]

GJ ha instalado un estanque hermoso para el disfrute estético y ejercicio 
de sus vacas. El estanque rectangular ha sido particionado en celdas 
cuadradas de M filas y N columnas (1 <= M <= 30; 1 <= N <= 30). Algunas 
de las celdas tienen nenúfares asombrosamente robustos, otras tienen 
rocas; las restantes tienen simplemente, agua azul, fresca, hermosa.

Bessie está practicando sus movimientos de ballet saltando de un nenúfar a 
otro y está actualmente ubicada en uno de los nenúfares. Ella quiere ir a 
otro nenúfar en el estanque saltando de un nenúfar a otro.


Sorprendentemente, solo para los iniciados, los saltos de Bessie entre 
nenúfares siempre se parecen a los movimientos de un caballo de ajedrez: 
movers M1 (1 <= M1 <= 30) 'cuadrados' en una dirección y luego M2 ((1 <= 
M2 <= 30; M1 !=M2) mas en una dirección ortogonal ( o tal vez M2 en una 
dirección y luego M1 en una dirección ortogonal). Bessie algunas veces 
podría tener hasta 8 posibilidades para su salto.

Dada la distribución del estanque y el formato de los saltos de Bessie,
determine el menor número de saltos que Bessie debe hacer para moverse de 
su ubicación inicial a su ubicación final, un hecho que siempre es 
posible para los conjuntos de entrada a usar.

NOMBRE DEL PROBLEMA: bronlily

FORMATO DE ENTRADA:

* Línea 1: Cuatro enteros separados por espacio: M, N, M1 y M2.

* Líneas 2..M+1: La línea i+1 describe la fila i del estanque usando N
      enteros separados por espacio con estos valores: 0 indica agua
      vacía; 1 indica un nenúfar; 2 indica una roca; 3 indica el nenúfar
      desde el cual Bessie comienza; 4 indica el nenúfar que es el
      destino de Bessie.

ENTRADA EJEMPLO (archivo bronlily.in):

4 5 1 2
1 0 1 0 1
3 0 2 0 4
0 1 2 0 0
0 0 0 1 0

DETALLES DE LA ENTRADA:

Bessie comienza en la izquierda de la fila 2; su destino está en la 
derecha de la fila 2. Varios nenúfares y rocas ocupan el estaque.

FORMATO DE SALIDA:

* Línea 1: Un solo entero que es el minimo numero de saltos entre
      nenúfares que Bessie debe hacer para ir de su lugar inicial a
      su destino.

SALIDA EJEMPLO (archivo bronlily.out):

2

DETALLES DE LA SALIDA:

De manera inteligente Bessie salta en el nenúfar en la  fila 1, columna 3
en su camino al lado derecho.
}
var
 fe,fs                     : text;
 n,m,m1,m2,s1,s2,f1,f2     : integer;
 mtx                       : array[0..36,0..36] of integer;
 a                         : array[boolean,1..1000,1..2] of integer;

procedure open;
var
 t0,t1                     : integer;
begin
 assign(fe,'bronlily.in'); reset(fe);
 assign(fs,'bronlily.out'); rewrite(fs);
 read(fe,m,n,m1,m2);
 for t0:=1 to m do
  begin
   for t1:=1 to n do
    begin
     read(fe,mtx[t0,t1]);
     if mtx[t0,t1] = 0 then mtx[t0,t1]:=maxint;
     if mtx[t0,t1] = 1 then mtx[t0,t1]:=0;
     if mtx[t0,t1] = 2 then mtx[t0,t1]:=maxint;
     if mtx[t0,t1] = 3 then
      begin
        s1:=t0; s2:=t1; mtx[t0,t1]:=0;
      end;
     if mtx[t0,t1] = 4 then
      begin
       f1:=t0; f2:=t1; mtx[t0,t1]:=0;
      end;
    end;
  end;
 close(fe);
end;

procedure swap(p : integer);
var
 t               : integer;
begin
 m1:=abs(m1); m2:=abs(m2);
 case p of
  1..2:begin
     t:=m1; m1:=m2; m2:=t;
    end;
  3..4:begin
     t:=m1; m1:=m2; m2:=t;
     m1:=-m1;
    end;
  5..6:begin
     t:=m1; m1:=m2; m2:=t;
     m1:=-m1; m2:=-m2;
    end;
  7..8:begin
    t:=m1; m1:=m2; m2:=t;
    m2:=-m2;
   end;
 end;
end;

procedure work;
var
 i,j,cp,ch,x,y                  : integer;
 s                              : boolean;
 z                              : array[1..2] of integer;
begin
 cp := 1; ch := 0; s:=true; a[s,1,1]:=s1; a[s,1,2]:=s2;
 while cp>0 do
  begin
   for i:=1 to cp do
    begin
     x:=a[s,i,1]; y:=a[s,i,2];
     for j:=1 to 8 do
      begin
       z[1]:=x+m1; z[2]:=y+m2;
       if (z[1] > 0) and (z[1] <= m) and (z[2] > 0) and (z[2] <= n)
        and (mtx[z[1],z[2]] = 0){ and (mtx[z[1],z[2]] <> 2)} then
         begin
          inc(ch);
          a[not s,ch,1]:=z[1]; a[not s,ch,2]:=z[2];
          mtx[z[1],z[2]] := mtx[x,y] + 1;
         end;
       swap(j);
      end;
    end;
    cp:=ch; ch:=0; s:= not s;
  end;
 write(fs,mtx[f1,f2]);
 close(fs);
end;

begin
 open;
 work;
end.