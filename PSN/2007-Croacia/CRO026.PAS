 {$I-,Q-,R-,S-}

{¦ Configuraciones de teclado.                           Croacia 2007
----------------------------------------------------------------------

La Compañía IslaMovil ha instalado un nuevo servicio en sus  teléfonos
móviles con el objetivo de  hacerlos más baratos. La novedad  consiste
en que al  trasmitir mensajes de  texto cada operación  de clic  sobre
un caracter en  el teclado tiene   un valor  de 1  centavo. El   nuevo
sistema  tiene  varias  configuraciones  de  teclado   las  cuales  en
dependencia  del  mensaje   se  pueden  ir  alternando.  El  cambio de
configuración de teclado cuesta solamente 1 centavo. El teclado  va  a
tener siempre 9 teclas y la tecla #, que es la tecla de control. A las
teclas numéricas en dependencia de la configuración se les asigna  una
determinada secuencia de caracteres.

Tomemos inicialmente un  teclado, en cada  tecla pueden existir  uno o
varios caracteres del  alfabeto inglés y  todas las letras  aparecerán
una sola  vez sin  repetición en  una configuración,  colocadas en  un
orden, por ejemplo si  en la tecla  4  están las letras ghi,  entonces
para colocar la  letra i  en un  mensaje hay  que oprimir  la tecla  4
tres veces.

Siempre es posible escribir un mensaje usando las configuraciones  del
teclado disponible. El problema entonces radica en minimizar el  gasto
al enviar un mensaje.

Tarea

Hacer un programa que permita:

-	Leer  desde fichero  de entrada  TCONFIG2.IN el  mensaje que se desea
  enviar y las configuraciones del teclado del dispositivo.

-	Determinar el menor costo posible con que puede enviarse el mensaje,
  así como la secuencia de clic que fueron necesarios.

-	Escribir hacia  el fichero  de salida  TCONFIG2.OUT el  menor costo
  encontrado y  la secuencia  de clic  que se  necesitan para   enviar
  el mensaje con ese costo.

Entrada

El fichero de entrada TCONFIG2.IN contiene:
Línea 1: N (1 <= N <= 5000) el número de caracteres del mensaje.
Línea 2: el mensaje, escrito sin espacios y con caracteres en
minúsculas.
Línea 3: C (1 <= C <= 10), cantidad de configuraciones de teclados.
Línea 4..C*9 + C-1: Se escribirán para cada configuración el número de
la tecla y los caracteres asociados a dicha tecla en el orden que
ellos aparecen. Una configuración se separa de la otra por una línea
en blanco.

Salida

El fichero de salida TCONFIG2.OUT contiene:
Línea 1: el entero CM el cual representan el costo del mensaje.
Línea 2..en adelante: en cada una  de ellas el carácter del mensaje  y
la tecla a la que le corresponde el carácter la cantidad de veces que
esa tecla se  oprimió, en el caso  de ser el carácter de control colocamos
el símbolo de # y la configuración  para la cual se cambio.

Ejemplo de Entrada y Salida

+--------------+ +--------------+
¦ TCONFIG2.IN  ¦ ¦ TCONFIG2.OUT ¦
+--------------¦ +--------------¦
¦ 11           ¦ ¦ 20           ¦
¦ computadora  ¦ ¦ #2           ¦
¦ 2            ¦ ¦ c 22         ¦
¦ 1 w          ¦ ¦ o 99         ¦
¦ 2 abc        ¦ ¦ #1           ¦
¦ 3 def        ¦ ¦ m 6          ¦
¦ 4 ghi        ¦ ¦ p 7          ¦
¦ 5 jkl        ¦ ¦ u 88         ¦
¦ 6 mno        ¦ ¦ t 8          ¦
¦ 7 pqrs       ¦ ¦ a 2          ¦
¦ 8 tuv        ¦ ¦ d 3          ¦
¦ 9 xyz        ¦ ¦ #2           ¦
¦ a 2          ¦ ¦ o 99         ¦
¦              ¦ ¦ r 66         ¦
¦ 1 yz         ¦ ¦ a 44         ¦
¦ 2 gcm        ¦ +--------------+
¦ 3 knl        ¦
¦ 4 ea         ¦
¦ 5 jbiv       ¦
¦ 6 xrt        ¦
¦ 7 dfw        ¦
¦ 8 ps         ¦
¦ 9 uoq        ¦
+--------------+
 }

const
 mx             = 5001;

var
 fe,fs          : text;
 n,m            : longint;
 ch             : char;
 cad            : array[1..mx] of char;
 best           : array[1..2] of longint;
 tab            : array[1..11,'a'..'z',1..2] of longint;
 t1             : array[boolean,1..mx] of longint;
 cam            : array[1..mx,1..11] of longint;
 res            : array[1..mx] of longint;

procedure open;
var
 i,j,k,l        : longint;
begin
 assign(fe,'tconfig2.in'); reset(fe);
 assign(fs,'tconfig2.out'); rewrite(fs);
 readln(fe,n);
 for i:=1 to n do
  read(fe,cad[i]);
 readln(fe);
 readln(fe,m);
 for i:=1 to m do
  begin
   for j:=1 to 9 do
    begin
     read(fe,k); read(fe,ch); l:=0;
     while not eoln(fe) do
      begin
       inc(l);
       read(fe,ch);
       tab[i,ch,1]:=l;
       tab[i,ch,2]:=k;
      end;
     readln(fe);
    end;
   readln(fe);
  end;
 close(fe);
end;

procedure work;
var
 i,j,k,k2       : longint;
 s              : boolean;
begin
 s:=false;
 best[1]:=maxlongint;
 for i:=1 to m do
  begin
   t1[s,i]:=tab[i,cad[1],1] + 1;
   cam[1,i]:=i;
   if t1[s,i] < best[1] then
    begin
     best[1]:=t1[s,i];
     best[2]:=i;
    end;
  end;
 s:=true;
 for i:=2 to n do
  begin
   for j:=1 to m do
    begin
     k:=t1[not s,j] + tab[j,cad[i],1];
     k2:=best[1] + tab[j,cad[i],1] + 1;
     if k < k2 then
      begin
       t1[s,j]:=k;
       cam[i,j]:=j;
      end
     else
      begin
       t1[s,j]:=k2;
       cam[i,j]:=best[2];
      end;
    end;
   best[1]:=maxlongint;
   for j:=1 to m do
    begin
     if t1[s,j] < best[1] then
      begin
       best[1]:=t1[s,j];
       best[2]:=j;
      end;
    end;
   s:=not s;
  end;
end;

procedure writer(x,c : longint);
var
 i                   : longint;
begin
 for i:=1 to x do
  write(fs,c);
 writeln(fs);
end;

procedure closer;
var
 i,j,k          : longint;
begin
 writeln(fs,best[1]);
 k:=best[2]; j:=n; res[n]:=k;
 while (j <> 1) do
  begin
   k:=cam[j,k];
   dec(j);
   res[j]:=k;
  end;
 writeln(fs,'#',res[1]);
 write(fs,cad[1],' ');
 writer(tab[res[1],cad[1],1],tab[res[1],cad[1],2]);
 for i:=2 to n do
  begin
   if (res[i] = res[i-1]) then
    begin
     write(fs,cad[i],' ');
     writer(tab[res[i],cad[i],1],tab[res[i],cad[i],2]);
    end
   else
    begin
     writeln(fs,'#',res[i]);
     write(fs,cad[i],' ');
     writer(tab[res[i],cad[i],1],tab[res[i],cad[i],2]);
    end;
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.