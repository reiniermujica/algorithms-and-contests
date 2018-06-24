  {$I-,Q-,R-,S-}

{ş Cortando Rect ngulos                                 Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 A usted se le da un rect ngulo cuyas  longitudes  de  sus  lados  son
 n£meros  enteros.  Usted  quiere  cortar  el  rect ngulo  en la menor
 cantidad de cuadrados, cuyas longitudes  de  sus  lados  son  tambi‚n
 n£meros  enteros.  Los  cortes, paralelos a los lados, son hechos con
 una m quina que puede solamente cortar de lado a lado del rect ngulo.
 Los rect ngulos obtenidos son cortados separadamente.

 Datos de Entrada

 El fichero de entrada contiene dos enteros positivos  en  la  primera
 l¡nea:  las  longitudes  de  los  lados del rect ngulo. Cada lado del
 rect ngulo tiene por longitud como m¡nimo 1 y como m ximo 100.

 Datos de Salida

 El fichero de salida contiene una l¡nea en la cual su  programa  debe
 escribir  el  n£mero  m¡nimo  de  cuadrados  resultantes  despu‚s  de
 realizado los cortes ¢ptimos.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ Ejemplo de Entrada ³ ³ Ejemplo de Salida ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 5 6                ³ ³ 5                 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 }

const
 mx                = 101;

var
 fe,fs             : text;
 n,m,sol,act       : longint;
 tab               : array[1..mx,1..mx] of longint;

procedure open;
begin
 assign(fe,'corte.in'); reset(fe);
 assign(fs,'corte.out'); rewrite(fs);
 readln(fe,n,m);
 close(fe);
end;

function min(n1,n2 : longint) : longint;
begin
 if n1 < n2 then min:=n1
            else min:=n2;
end;

procedure work;
var
 i,j,k,mn          : longint;
begin
 if n > m then act:=n
          else act:=m;
 for i:=1 to act do
  begin
   tab[i,1]:=i;
   tab[1,i]:=i;
   tab[i,i]:=1;
  end;
 for i:=2 to act do  { Vertical }
  for j:=2 to act do { Horizontal }
   if i<>j then
    begin
     mn:=i*j;
     for k:=1 to (j div 2) do { Cortes Horizontales }
      mn:=min(mn,tab[k,i] + tab[j-k,i]);
     for k:=1 to (i div 2) do { Cortes Verticales }
      mn:=min(mn,tab[k,j] + tab[i-k,j]);
     tab[i,j]:=mn;
     tab[j,i]:=mn;
    end;
 sol:=tab[n,m];
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