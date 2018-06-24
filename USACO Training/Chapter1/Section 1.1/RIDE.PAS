  {$I-,Q-,R-,S-}

{Tu Viaje Esta Aqui
Es un hecho bien conocido que detrs de cada buen cometa hay un OVNI. Estos
OVNIs vienen frecuentemente a reclutar apoyos de aqu en la tierra.
Desdichadamente, ellos solamente tienen espacio para recoger a un grupo de
seguidores en cada viaje. Ellos, sin embargo, permiten que los grupos sepan
de antemano cules sern recogidos por cada cometa usando un metodo inteligente:
ellos eligen un nombre para el cometa el cual, junto con el nombre del grupo,
puede ser usado para determinar si es el turno para un grupo particular para
irse (Quin piensas que pone los nombres de los cometas. Los detalles del mtodo
de determinacin son dados a continuacin; tu trabajo es escribir un programa el
cual tome el nombre de un grupo y el nombre de un cometa y luego determine si
el grupo debera irse con el OVNI detrs de ese cometa o no.

Tanto el nombre del grupo y el nombre del cometa son convertidos en un numero
de la siguiente manera: el nmero final es simplemente el producto de todas las
letras en el nombre, donde "A" es 1 y "Z" es 26. Por ejemplo, el grupo "USACO"
sera 21 * 19 * 1 * 3 * 15 = 17955. Si el nmero del grupo mdulo 47 es el mismo
que el nmero del cometa mdulo 47, entonces t necesitas decirle al grupo
Alstense (Recuerda que "a mod b" es el residuo despus de dividir a por b;
34 mod 10 es 4.)

Escribe un programa el cual lea el nombre de un cometa y el nombre de un grupo
y encuentre si de acuerdo al mtodo antes descrito si el grupo debe ir en el
OVNI detrs de ese cometa y ese caso , imprima "GO", y si no "STAY". Los nombre
de los grupos y de los cometas sern cadenas de letras maysculas sin espacios o
caracteres de puntuacin, hasta de 72 caracteres de longitud.

NOMBRE DEL PROGRAMA: ride
FORMATO DE LA ENTRADA
Linea 1:  Una cadena de caracteres en mayúscula de longitud 1..72 que es el
nombre del cometa

Linea 2:  Una cadena de caracteres en mayúscula de longitud 1..72 que es el
nombre del grupo.

NOTA: El archivo de entrada tiene un carcter de nueva linea al final de cada
lnea, no tiene un "return". Algunas veces los programadores codifican para el
paradigma Windows de "nueva linea" seguido por "return", no uses eso! Usa
rutinas simples como "readln" (para Pascal) y, para C/C++, "fscanf" y
"fid>>string".

ENTRADA EJEMPLO (archivo ride.in)
COMETHALEBOPP
HEAVENSGATE

FORMATO DE SALIDA
Una sola línea conteniendo o la palabra "GO" o la palabra "STAY".
SALIDA EJEMPLO (archivo ride.out)
GO
}

var
 fe,fs          : text;
 n,m            : longint;
 St,Tm          : string[72];

procedure open;
begin
 assign(fe,'ride.in'); reset(fe);
 assign(fs,'ride.out'); rewrite(fs);
 readln(fe,St);
 readln(fe,Tm);
 close(fe);
end;

procedure work;
var
 i              : longint;
begin
 n:=1;
 for i:=1 to length(St) do
  begin
   n:=(n*(ord(St[i])-64)) mod 47;
  end;
 m:=1;
 for i:=1 to length(Tm) do
  begin
   m:=(m*(ord(Tm[i])-64)) mod 47;
  end;
end;

procedure closer;
begin
 if n=m then
  writeln(fs,'GO')
 else
  writeln(fs,'STAY');
 close(fs);
end;

begin
 open;
 work;
 closer;
end.