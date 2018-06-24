/*
  Reinier César Mujica
  23 - 12 - 2008
  esta solucion no es optima
  pero no se puede desperdiciar
  por 4 jd
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 20,
	MAXM = MAXN * MAXN;

int N, M, sol;
int i, j, k;
int C[MAXM][MAXM];
int V[MAXN];
char ch;

int main() {

	freopen( "cruz.in", "r", stdin );
	freopen( "cruz.out", "w", stdout );
	
	scanf( "%d\n", &N );
	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= N; j++ ) {
			scanf( "%c", &ch );
            M++;
			if ( ch == 'C' )
				C[M][N * N + 1] = 1;
            C[M][M] = 1;
			if ( i > 1 ) C[M][M - N] = 1;
			if ( i < N ) C[M][M + N] = 1;
			if ( j > 1 ) C[M][M - 1] = 1;
			if ( j < N ) C[M][M + 1] = 1;
        }
		scanf( "%c\n", &ch );
	}
	
	/* Gauss Method */
	for ( i = 1; i < M; i++ ) {
		for ( j = i; j <= M; j++ )
			if ( C[j][i] ) {
				for ( k = 1; k <= M + 1; k++ )
					swap( C[i][k], C[j][k] );
				break;
			}
		for ( j = i + 1; j <= M; j++ )
			if ( C[j][i] ) {
				for ( k = i; k <= M + 1; k++ )
					C[j][k] = ( C[j][k] + C[i][k] ) % 2;
			}
	}
	
	for ( i = M; i > 0; i-- ) {
        V[i] = C[i][M + 1];
		for ( j = M; j > i; j-- )
			V[i] = ( V[i] + C[i][j]*V[j] ) % 2;
		V[i] = ( V[i] ^ C[i][i] ) ^ 1;
		sol += V[i];
	}

	printf( "%d\n", sol );
	for ( i = 1; i <= N; i++ )
		for ( j = 1; j <= N; j++ )
			printf( ( j != N ) ? "%d" : "%d\n" , V[( i - 1 ) * N + j] );
		
	fflush( stdout );
	return 0;
}	

/*
44þ Cara y Cruz                                           Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dada  una  matriz  de monedas de NxN (donde N ó 10), que tiene algunas
monedas  con la cara hacia arriba y otras con la cruz hacia arriba. Un
jugador  debe  virar monedas de modo que logre una configuraci¢n de la
matriz  en  la  que todas las monedas tengan la cruz hacia arriba. Sin
embargo,  cuando un jugador vira una moneda en particular, cada moneda
adyacente  a  esta  (por  la izquierda, la derecha, arriba y abajo, si
existe)  tambi‚n  ser n  viradas. El problema consiste en que dada una
configuraci¢n  inicial,  lograr  la matriz de cruces virando el n£mero
m¡nimo de monedas. Observe que por virar entendemos virar una moneda y
sus vecinas.

Datos de Entrada

La  primera  l¡nea  del fichero de entrada contendr  el entero N. Cada
una  de  la  N  l¡neas  siguientes  contienen  N  caracteres C o X que
significan cara o cruz respectivamente.

Datos de Salida

La  primer  l¡nea del fichero de salida debe contener el n£mero m¡nimo
de virajes. Las pr¢ximas N l¡neas contiene una matriz de N enteros por
l¡nea. Estos enteros tiene como valore O ¢ 1. El valor 1 significa que
la  moneda  correspondiente  a es posici¢n ha sido virada al menos una
vez.  ‚l valor 0 significa que la moneda correspondiente no fue virada
nunca.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ Ejemplo de Entrada ³ ³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3                  ³ ³ 5                 ³
³ CXX                ³ ³ 100               ³
³ CXX                ³ ³ 010               ³
³ XXX                ³ ³ 111               ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

*/
