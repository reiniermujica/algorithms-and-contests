{$B-,I-,Q-,R-,S-}
{$M 65384,0,655360}
{10¦ Configuraciones de teclado.                           Croacia 2007
----------------------------------------------------------------------

La Compañía IslaMovil ha instalado un nuevo servicio en sus  teléfonos
móviles con el objetivo de  hacerlos más baratos. La novedad  consiste
en que al  trasmitir mensajes de  texto cada operación  de clic en  el
teclado tiene  un valor  de 1  centavo. El  nuevo sistema tiene varias
configuraciones de teclado  las cuales en  dependencia del mensaje  se
pueden ir alternando, sin gastos  en dicha operación. El teclado  va a
tener siempre 9 teclas y la tecla #, que es la tecla de control. A las
teclas numéricas en dependencia de la configuración se les asigna  una
determinada secuencia de caracteres.

Tomemos inicialmente un  teclado, en cada  tecla pueden existir  uno o
varios caracteres del  alfabeto inglés y  todas las letras  aparecerán
una sola  vez sin  repetición en  una configuración,  colocadas en  un
orden, por ejemplo en la tecla  4 están las letras ghi, entonces  para
colocar la  letra i  en un  mensaje hay  que oprimir  la tecla  4 tres
veces.

Si tuviéramos dos teclados como en el ejemplo de abajo

1
w	2
abc	3
def
4
ghi	5
jkl	6
mno
7
pqrs	8
tuv	9
xyz

Configuración1

1
yz	2
cgm	3
knl
4
ea	5
jbiv	6
xrth
7
dfw	8
ps	9
uoq

Configuración 2

El   mensaje  Computadora  puede ser  escrito  de  la siguiente  forma
utilizando solamente la configuración 1 con un costo de 20 centavos.

	C	o	m	p	u	t	a	d	o	r	a
#1	222	666	6	7	88	8	2	3	666	777	2

Si para escribir el mismo mensaje utilizáramos las dos configuraciones
el costo del mensaje sería de 18 centavos.

	C	o		m	p		u	T		a	d	o		r	a
#2	2	99	#1	6	7	#2	9	666	#1	2	3	666	#2	66	44

Siempre es posible escribir un mensaje usando las configuraciones  del
teclado disponible. El problema entonces radica en minimizar el  gasto
al enviar un mensaje.

Tarea

Hacer un programa que permita:

-	Leer  desde fichero  de entrada  TCONFIG.IN el  mensaje que se desea
  enviar y las configuraciones del teclado del dispositivo.

-	Determinar el menor costo posible con que puede enviarse el mensaje,
  así como la secuencia de clic que fueron necesarios.

-	Escribir hacia  el fichero  de salida  TCONFIG.OUT el  menor costo
  encontrado y  la secuencia  de clic  que se  necesitan para   enviar
  el mensaje con ese costo.

Entrada

El fichero de entrada TCONFIG.IN contiene:
Línea 1: N (1 <= N <= 5000) el número de caracteres del mensaje.
Línea 2: el mensaje, escrito sin espacios y con caracteres en
mayúsculas y minúsculas.
Línea 3: C (1 <= C <= 10), cantidad de configuraciones de teclados.
Línea 4..C*9 + C-1: Se escribirán para cada configuración el número de
la tecla y los caracteres asociados a dicha tecla en el orden que
ellos aparecen. Una configuración se separa de la otra por una línea
en blanco.

Salida

El fichero de salida TCONFIG.OUT contiene:
Línea 1: el entero CM el cual representan el costo del mensaje.
Línea 2..en adelante: en cada una  de ellas el carácter del mensaje  y
la cantidad de veces  que esa tecla se  oprimió, en el caso  de ser el
carácter de control colocamos el símbolo de # y la configuración  para
la cual se cambio.

Ejemplo de Entrada y Salida

TCONFIG.IN

11
Computadora
2
1 w
2 abc
3 def
4 ghi
5 jkl
6 mno
7 pqrs
8 tuv
9 wxyz

1 yz
2 gcm
3 knl
4 ea
5 jbiv
6 xrt
7 dfw
8 ps
9 uoq


TCONFIG.OUT

18
#2
C 2
o 99
#1
m 6
p 7
#2
u 9
t 666
#1
a 2
d 3
o 666
#2
r 66
a 44
}

var
 fe,fs                : text;
 n,m,sol              : longint;
 men                  : array[1..10000] of char;
 tec                  : array[1..50,1..9] of string[26];
 best                 : array['a'..'z',1..3] of longint;

procedure open;
var
 i,j                  : longint;
 st                   : string[2];
begin
 assign(fe,'tconfig.in'); reset(fe);
 assign(fs,'tconfig.out'); rewrite(fs);
 readln(fe,n);
 readln(fe);
 readln(fe,m);
 for i:=1 to m do
  begin
   for j:=1 to 9 do
    readln(fe,st,tec[i,j]);
   readln(fe);
  end;
 close(fe);
end;

procedure work;
var
 i,j,k,l,p            : longint;
begin
 sol:=0;
 fillchar(best,sizeof(best),0);
 reset(fe);
 readln(fe);
 for i:=1 to n do
  begin
   read(fe,men[i]);
   if (best[men[i],1] = 0) then
   begin
   for j:=1 to m do
     begin
      for k:=1 to 9 do
      begin
       l:=pos(men[i],tec[j,k]);
       if (l > 0) then
        if (best[men[i],3] > l) or (best[men[i],3] = 0) then
         begin
          best[men[i],1]:=j;
          best[men[i],2]:=k;
          best[men[i],3]:=l;
          p:=l;
          break;
         end;
      end;
     end;
   sol:=sol+p;
   end
   else
    sol:=sol+best[men[i],3];
  end;
 close(fe);
end;

procedure mos(x,z : longint);
var
 h                : longint;
begin
 for h:=1 to z do write(fs,x);
 writeln(fs);
end;

procedure closer;
var
 i                : longint;
begin
 writeln(fs,sol);
 writeln(fs,'#',best[men[1],1]);
 write(fs,men[1],' ');
 mos(best[men[1],2],best[men[1],3]);
 for i:=2 to n do
  begin
   if (best[men[i-1],1] = best[men[i],1]) then
    begin
     write(fs,men[i],' ');
     mos(best[men[i],2],best[men[i],3])
    end
    else
     begin
      writeln(fs,'#',best[men[i],1]);
      write(fs,men[i],' ');
      mos(best[men[i],2],best[men[i],3]);
     end;
  end;
 close(fs);
end;

begin
 open;
 work;
 closer;
end.