  {$I-,Q-,R-,S-}

{Problema 12: Ensamblaje DNA [Competencia Woburn, 2005]

El Granjero Juan ha encontrado la secuencia DNA de su vaca productora
de leche campeona, las secuencias DNA de Bessie son listas ordenadas
(cadenas) conteniendo las letras 'A', 'C', 'G', y 'T'.

Como es usual para secuencias DNA, los resultados son un conjunto de
cadenas que son fragmentos secuenciados de DNA, no cadenas enteras
DNA. Un par de cadenas como 'GATTA' y 'TACA' lo m s posible es que
representen la cadena 'GATTACA' en tanto que los caracteres que se
superponen son mezclados, desde que ellos fueron posiblemente
duplicados en el proceso de secuenciaci¢n.

Mezclar un par de cadenas requiere encontrar la mayor superposiciòn
entre las dos y luego eliminarla en tanto las dos cadenas se
concatenan. Las superposiciones son entre el final de una cadena y el
comienzo de otra cadena, NUNCA EN EL MEDIO DE UNA CADENA.

Por ejemplo, las cadenas 'GATTACA' and 'TTACA' se suporponen
completamente. Por otra parte las cadenas 'GATTACA' y 'TTA' no tienen
ninguna superposici¢n, desde que los caracteres coincidentes aparecen
en la mitad de la otra cadena, no al comienzo de la otra. Aqu¡ hay
algunos ejemplos de mezclar cadenas, incluyendo aquellas sin
superposici¢n:

  GATTA + TACA -> GATTACA
	TACA + GATTA -> TACAGATTA
	TACA + ACA -> TACA
	TAC + TACA -> TACA
	ATAC + TACA -> ATACA
	TACA + ACAT -> TACAT

Dado un conjunto de N (2 <= N <= 7) secuencias DNA todas las cuales
tienen longitudes en el rango 1..7, encuentre e imprima la secuecia
m s corta posible obtenible mezclando repetidamente todas las N
cadenas usando el procedimiento antes descrito. Todas las cadenas
deben ser mezcladas en la secuencia resultante para la secuencia
resultante.

NOMBRE DEL PROBLEMA: dna

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero N

* L¡neas 2..N+1: Cada l¡nea contiene una sola subsecuencia DNA

ENTRADA EJEMPLO (archivo dna.in):

4
GATTA
TAGG
ATCGA
CGCAT

FORMATO DE SALIDA:

* L¡nea 1: La longitud de la cadena m s corta posible obtenida
  mezclando las subsecuencias. Es siempre posible - y requerido -
  mezclar todas las cadenas de la entrada para obtener esta cadena.

SALIDA EJEMPLO (archivo dna.out):

13

DETALLES DE LA SALIDA:

Tal cadena es "CGCATCGATTAGG".
}

var
 fe,fs          : text;
 n,m,sol        : longint;
 tab            : array[1..8] of string;
 mk             : array[1..8] of boolean;

procedure open;
var
 i              : longint;
begin
 assign(fe,'dna.in'); reset(fe);
 assign(fs,'dna.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  readln(fe,tab[i]);
 close(fe);
end;

function conc(x,y : string) : string;
var
 i,j,k,t          : longint;
 s1,s2            : string;
 ok               : boolean;
begin
 j:=1; s1:='';
 for i:=length(x)-length(y) + 1 to length(x) do
  begin
   if x[i] = y[1] then
    begin
     t:=j+1; ok:=true;
     for k:=i+1 to length(x) do
      if x[k] <> y[t] then
       begin
        ok:=false;
        break;
       end
      else inc(t);
     if ok then
      begin
       for k:=1 to i do s1:=s1 + x[k];
       for k:=j+1 to length(y) do s1:=s1 + y[k];
       conc:=s1;
       exit;
      end;
    end;
  end;
  conc:=x+y;
end;

procedure comb(x,y : longint; st : string);
var
 i                 : longint;
 s                 : string;
begin
 if y = n then
  begin
   if x < sol then
    sol:=x;
  end
  else
 for i:=1 to n do
  if not mk[i] then
   begin
    mk[i]:=true;
    s:=conc(st,tab[i]);
    comb(length(s),y+1,s);
    mk[i]:=false;
   end;
end;

procedure work;
var
 i             : longint;
begin
 sol:=maxlongint;
 for i:=1 to n do
  begin
   fillchar(mk,sizeof(mk),false);
   mk[i]:=true;
   comb(length(tab[i]),1,tab[i]);
  end;
 writeln(fs,sol);
 close(fs);
end;

begin
 open;
 work;
end.
