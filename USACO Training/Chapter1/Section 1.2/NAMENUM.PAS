 {$I-,Q-,R-,S-}

{Nombre Ese Número

Entre los numerosos rancheros de Winsconsin, es costumbre marcar las vacas
con números seriales para complacer al Departamento de Contaduria. A las vacas
no les gusta este sistema de denominación y quisieran llamar a los mimebros de
la manada por un nombre placentero en lugar de decir, "Oiga, #4734,get venga".

Ayude a lasa vacas escribiendo un programa que traducirá el número serial de
una vaca en nombres posibles asocioados únicamente con ese número serial.
Desde que todas las vacas tienen telefónos celulares en estos días, use el
mapeo estandar norteamericano para obtener letras a partir de números
(excepto por "Q" y "Z"):

          2: A,B,C     5: J,K,L    8: T,U,V
          3: D,E,F     6: M,N,O    9: W,X,Y
          4: G,H,I     7: P,R,S

Se le proporcionan nombres aceptables para el ganado en un archivo llamado
"dict.txt", el cual contiene una lista con menso de 5,000 nombres aceptables
de vacas (todas las letras en mayúsculas). Tome el número de marca de una
vaca y reporte cuáles de todas las palabras posibles a las cuales ese número
mapea están en el diccionario dadoel cual está suministrado como dict.txt en
el ambiente de calificación (y está ordenado en orden ascendente).

Por ejemplo, el número de marca 4734 produce todos los siguientes nombres:

GPDG GPDH GPDI GPEG GPEH GPEI GPFG GPFH GPFI GRDG GRDH GRDI
GREG GREH GREI GRFG GRFH GRFI GSDG GSDH GSDI GSEG GSEH GSEI
GSFG GSFH GSFI HPDG HPDH HPDI HPEG HPEH HPEI HPFG HPFH HPFI
HRDG HRDH HRDI HREG HREH HREI HRFG HRFH HRFI HSDG HSDH HSDI
HSEG HSEH HSEI HSFG HSFH HSFI IPDG IPDH IPDI IPEG IPEH IPEI
IPFG IPFH IPFI IRDG IRDH IRDI IREG IREH IREI IRFG IRFH IRFI
ISDG ISDH ISDI ISEG ISEH ISEI ISFG ISFH ISFI

Como suele suceder, el único de estos 81 nombres en la lista de nombres
válidos es "GREG".

Escriba un programa que dado un número de marca de una vaca imprima todos los
nombres válidos que puedn ser generados a partir de ese numero o ``NONE'' si
no hay nombres válidos. Los números seriales pueden tener hasta doce dígitos
de longitud.

NOMBRE DEL PROGRAMA: namenum

FORMATO DE ENTRADA

Una sola línea con un número de 1 a 12 dígitos de longitud.

ENTRADA EJEMPLO (archivo namenum.in)

4734

FORMATO DE SALIDA

Una lista de nombres válidos que pueden ser generados desde la entrada, uno
por línea, en orden alfabético ascendente.

SALIDA EJEMPLO (archivo namenum.out)

GREG

}

const
 ord0              = ord('0');
 dict              : array['A'..'Y'] of char
  =('2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7',
   '7','8','8','8','9','9','9');

var
 fe,fs             : text;
 n,i,sol           : longint;
 st,res,tmp        : string;

procedure open;
begin
 assign(fe,'namenum.in'); reset(fe);
 assign(fs,'namenum.out'); rewrite(fs);
 readln(fe,st);
 close(fe);
 assign(fe,'dict.txt'); reset(fe);
end;

procedure work;
begin
 sol:=0; n:=length(st);
 while not eof(fe) do
  begin
   readln(fe,tmp);
   if length(tmp) = n then
    begin
     res:='';
     for i:=1 to length(tmp) do
      res:=res + dict[tmp[i]];
     if res = st then
      begin
       inc(sol);
       writeln(fs,tmp);
      end;
    end;
  end;
 if sol = 0 then
  writeln(fs,'NONE');
 close(fs);
end;

begin
 open;
 work;
end.