{$B-,I-,Q-,R-,S-}
{$M 16384,0,655360}
{66þ Comida Ol¡mpica                                         Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En  los Juegos Ol¡mpicos hay N (3<=n<=50000) atletas, cada uno marcado
con  un  n£mero  de serie £nico en el rango de 1..N. Cada noche, ellos
hacen  cola para comer formando una l¡nea (cola) con los atletas en un
relativo  orden aleatorio. Algunos ordenamientos pueden ser expresados
como un n£mero de N d¡gitos en base N.

Al  comit‚  organizador  no  le gusta el ordenamiendo aleatorio. Ellos
quieren  que  los atletas se ponga en l¡nea de forma tal que el n£mero
que  representa  el  ordenamiento  est‚  minimizado. A los atletas, no
obstante,  no  les  gusta  hacer exactamente lo que le dicen que hagan
todo  el  tiempo. El comit‚ organizador y los atletas han llegado a un
acuerdo:  los  atletas  se  pondr n  en  fila y entonces se reubicar n
ellos  m¡smos  en  cierto  nuevo  orden que minimice la representaci¢n
ordenada.   El  truco  es  que  cada  n£mero  de  serie  en  el  nuevo
ordenamiento  no  puede diferir por m s de 1 de el n£mero de serie que
utiliz¢ para ocupar esa posici¢n.

Si 8 atletas se ponen en l¡nea similar a esta :³8³5³7³3³6³4³2³1³
                                               ÃÄÅÄÅÄÅÄÅÄÅÄÅÄÅÄ´
Entonces el nuevo ordenamiento ser¡a:          ³7³4³8³2³6³5³3³1³

porque:

- ning£na posici¢n en la segunda lista contiene un d¡gito que difiera
  del  d¡gito  de  arriba por m s de 1 (algunas veces la diferencia es
  cero)
_  este  es  el  n£mero  m s peque¤o que puede ser obtenido usando las
  reglas.

Tu tarea es decirle al comit‚ organizador el nuevo ordenamiento de los
atletas tal que puedan asegurarse que los atletas est‚n correctamente.

Entrada

El fichero de entrada DINNER.IN contendr :
- l¡nea 1: una l¡nea con un entero simple: N.
- l¡nea 2.. N+1: cada l¡nea contiene un entero simple que es el n£mero
  de    serie    de    un    atleta    en    la   posici¢n  respectiva
- el atleta m s a la izquierda es dado primero.

Salida

El  fichero  de  salida DINNER.OUT contendr  N l¡neas, cada una con un
entero simple que dice cual atleta pertenece a la respectiva ranura.
La  primera  l¡nea de salida contiene el n£mero de serie del atleta en
la ranura de hacia la izquierda y asi sucesivamente.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ DINNER.IN ³ ³ DINNER.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 8         ³ ³ 7          ³
³ 8         ³ ³ 4          ³
³ 5         ³ ³ 8          ³
³ 7         ³ ³ 2          ³
³ 3         ³ ³ 6          ³
³ 6         ³ ³ 5          ³
³ 4         ³ ³ 3          ³
³ 2         ³ ³ 1          ³
³ 1         ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
const
 max                         = 50000;

var
 fe,fs                       : text;
 n                           : longint;
 mk                          : array[0..max+1] of boolean;

procedure open;
begin
 assign(fe,'dinner.in'); reset(fe);
 assign(fs,'dinner.out'); rewrite(fs);
 readln(fe,n);
end;

procedure work;
var
 i,aux                     : longint;
begin
 fillchar(mk,n,false);
 mk[1]:=false; mk[0]:=true; mk[max+1]:=false;
 for i:=1 to n do
   begin
    readln(fe,aux);
    if mk[aux] then
      writeln(fs,aux+1)
    else
      begin
       if not mk[aux-1] then
         begin
          writeln(fs,aux-1);
          mk[aux-1]:=true;
         end
       else
        writeln(fs,aux);
      end;
    mk[aux]:=true;
   end;
 close(fs);
end;

begin
 open;
 work;
end.