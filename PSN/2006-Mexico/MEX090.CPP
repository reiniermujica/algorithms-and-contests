/*
 Reinier César Mujica
 23 - 12 - 2008
 studying for CNC for avoid electric GTM students
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 20,
	MAXM = 20 * 20;
	
int N = 10, M, sol;
int T[MAXM * 2][MAXM * 2];
int i, j, k;
int V[MAXM];
char cad[MAXN], line[MAXN];

int main() {

	freopen( "LIGHTS.IN", "r", stdin );
	freopen( "LIGHTS.OUT", "w", stdout );
	
	scanf( "%s\n", &cad );
	while ( !strstr( cad, "end" ) ) {
		
		for ( i = 0; i < MAXM; i++ )
			fill( T[i], T[i] + MAXM, 0 );
			
		M = 0;
		for ( i = 1; i <= N; i++ ) {
			gets( line + 1 );
			for ( j = 1; j <= N; j++ ) {
				M++;
				T[M][101] = ( line[j] == 'O' ) ? 1 : 0;
				T[M][M] = 1;
				if ( i > 1 ) T[M][M - N] = 1;
				if ( j > 1 ) T[M][M - 1] = 1;
				if ( i < N ) T[M][M + N] = 1;
				if ( j < N ) T[M][M + 1] = 1;
			}
		}
		
		/* Gauss Method */
		for ( i = 1; i < M; i++ ) {
			for ( j = i; j <= M; j++ )
				if ( T[j][i] ) {
					for ( k = 1; k <= M + 1; k++ )
						swap( T[j][k], T[i][k] );
					break;
				}
			
			for ( j = i + 1; j <= M; j++ ) {
                if ( T[j][i] ) {
                    for ( k = i; k <= M + 1; k++ )
                        T[j][k] = ( T[j][k] + T[i][k] ) % 2;
                }
            }
		}

        for ( i = M; i > 0; i-- ) {
            V[i] = T[i][M + 1];
            for ( j = M; j > i; j-- )
                V[i] = ( V[i] + T[i][j]*V[j] ) % 2;

            V[i] = ( V[i] ^ T[i][i] ) ^ 1;
        }

        sol = 0;
        for ( i = 1; i <= M; i++ )
            if ( V[i] ) sol++;

        printf( "%s %d\n", cad, sol );
        scanf( "%s\n", &cad );
	}
	
	fflush( stdout );
	return 0;
}

/*
90þ Apagar las Luces.                                      M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Usted esta ahora  frente  a  una importantisima tarea, que consiste en
ahorrar  energia  apagando luces.  Un  amigo  suyo  tiene el siguiente
problema en el trabajo. Hay una grilla de tama¤o 10 X 10 la cual tiene
un  bombillo en cada cuadricula.  Cada  bombillo  tiene  dos  posibles
estados, apagado y encendido.Nosotros definimos cambiar el estado como
pasar de un estado al otro. Por  desgracia  estas  luces  no funcionan
como se supone que lo hagan, ya  que  cuando  se le cambia el estado a
una tambien cambian  de  estado  las luces adyacentes, (arriba, abajo,
derecha, izquierda).  Por  supuesto que  las luces de los extremos les
cambian  el  estado  a  menos luces ya  que tienen  menos  adyacentes.

Para que quede mas claro como  funciona esto, abajo estan dos ejemplos
en  los cuales aparece una figura  antes y despues de que se le cambie
el estado al boton del medio.

###      #O#
###  ->  OOO
###      #O#

###      #O#
OOO  ->  ###
###      #O#

Tus amigos adoran ahorrar energia  y  te  han pedido que les  hagas un
programa  que  los  ayude  a saber si es posible o no apagar todas las
luces  y  en  caso  de  que sea posible decirles la minima cantidad de
pasos.

Entrada: (LIGTHS.IN)

La  entrada  consiste  de  varios casos de prueba. Cada caso de prueba
esta encabezado por una palabra que le da un nombre al mismo.  Despues
siguen  10  l¡neas  cada  una  con 10 caracteres '#' o 'O', donde  '#'
significa apagado y 'O' encendido.  La  entrada termina con la palabra
'end'.

Salida: (LIGTHS.OUT)

Para cada caso de prueba imprime una l¡nea de el nombre de dicho caso,
seguido  por  un  caracter  espacio  y  un entero que indica la minima
cantidad de pasos para apagar todas las luces. Si no es posible apagar
todas  las  luces o se requieren mas de 100 pasos, entonces escriba el
nombre del caso de prueba seguido por un espacio en blanco y un -1.

Ejemplo de Entrada:

all_off
##########
##########
##########
##########
##########
##########
##########
##########
##########
##########
all_on
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
OOOOOOOOOO
simple
#O########
OOO#######
#O########
####OO####
###O##O###
####OO####
##########
########O#
#######OOO
########O#
end

Ejemplo de Salida:

all_off 0
all_on 44
simple 4

*/
