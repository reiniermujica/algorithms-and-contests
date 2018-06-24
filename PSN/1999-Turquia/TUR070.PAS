{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{70ş Gangsters                                            Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 N gangster van a un  restaurant. El  i-‚simo  gangster  llega  en  el
 tiempo Ti y tiene peligrosidad Pj. La puerta del restaurant tiene k+1
 estados para estar abierta expresados  por  un entero en el rango [0,
 k]. El estado de abertura puede  cambiar de uno en  uno en una unidad
 de tiempo, por ejemplo:  abre en 1, cierra en 1 o permanece igual. En
 el momento inicial  del tiempo la puerta  est  cerrada (estado 0). El
 i-‚simo gangster entra al restaurant solo si  la puerta est   abierta
 especialmente para ‚l, por ejemplo, cuando  el estado  de abertura de
 la  puerta  coincida con su corpulencia. Si en el  momento de  tiempo
 cuando  el gangster llega  al restaurant, el estado de abertura no es
 igual a su corpulencia, entonces  el  gangster se va y no retorna. El
 restaurant trabaja en el intervalo de tiempo [0, T].

 El objetivo es cojer los gangster con el m ximo total de peligrosidad
 en el restaurant abriendo y cerrando la puerta apropiadamente.

 Entrada

 . La primera l¡nea del fichero de entrada contiene los valores de  N,
 K  y  T  separados  por  espacios  (1 ó N ó 100),  (1 ó K ó 100),
 (1 ó T ó 30000).

 . La segunda l¡nea del fichero contiene los momentos de tiempo cuando
 el  gangster  viene  al  restaurant  T1, t2,  ...  Tn,  separdos  por
 espacios, (0 ó Ti ó T para i = 1, 2, ..., N).

 . La tercera l¡nea del fichero contiene el valor  de la  peligrosidad
 de los gangster P1, P2, ..., Pn separdos por espacios  (0 ó Pi ó 300,
 para i = 1, 2, ..., N).

 . La cuarta l¡nea contiene los  valores  de las  corpulencia  de  los
 gangster  S1, S2, ..., Sn separados por espacios (0  ó Si ó  K,  para
 i = 1, 2, ..., N).

 Todos los valores en el fichero de entrada son enteros.

 Salida

 Escribir en el  fichero de salida un entero que se corresponde con la
 suma m xima de peligrosidad de  los  gangster en el restaurant. En el
 caso que ning£n gangster pueda entrar al restaurant  la  salida  debe
 ser un 0.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada #1  ³       ³Ejemplo de Entrada # 2 ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³4 10 20                ³       ³2 17 100               ³
 ³10 16 8 16             ³       ³5 0                    ³
 ³10 11 15 1             ³       ³50 33                  ³
 ³10 7 1 8               ³       ³6 1                    ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿       ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Salida #1   ³       ³Ejemplo de Salida #2   ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´       ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³26                     ³       ³0                      ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

}

var
 fe,fs                  : text;
 n,k,t,sol              : longint;
 Ti,Pel,Cor,Door        : array[1..100] of longint;

procedure open;
var
 t                      : integer;
begin
 assign(fe,'tur070.in'); reset(fe);
 assign(fs,'tur070.out'); rewrite(fs);
 readln(fe,n,k,t);
 for t:=1 to n do read(fe,Ti[t]);
 readln(fe);
 for t:=1 to n do read(fe,Pel[t]);
 readln(fe);
 for t:=1 to n do read(fe,Cor[t]);
 close(fe);
end;

procedure swap(var n1,n2 : longint);
var
 t                       : longint;
begin
 t:=n1; n1:=n2; n2:=t;
end;

procedure qsort(ini,fin : longint);
var
 i,j,k                  : longint;
begin
 i:=ini; j:=fin; k:=Ti[(i+j) div 2];
 repeat
  while Ti[i] < k do inc(i);
  while Ti[j]>k do dec(j);
  if i<=j then
   begin
   swap(Ti[i],Ti[j]);
   swap(Pel[i],Pel[j]);
   swap(Cor[i],Cor[j]);
   inc(i); dec(j);
   end;
 until i>j;
 if i<fin then qsort(i,fin);
 if j>ini then qsort(ini,j);
end;

procedure work;
var
 i,j                  : longint;
begin
 fillchar(Door,sizeof(Door),0);
 for i:=n downto 1 do
  if Ti[i] >= Cor[i] then
   begin
   door[i]:=pel[i];
   for j:=i+1 to n do
    begin
     if (abs(Ti[i]-Ti[j]) >= abs(Cor[i]-Cor[j]))
      and (Pel[i] + Door[j] > door[i]) then
      begin
       door[i]:=door[j] + Pel[i];
       if door[i] > sol then
        sol:=door[i];
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
 qsort(1,n);
 work;
 closer;
end.