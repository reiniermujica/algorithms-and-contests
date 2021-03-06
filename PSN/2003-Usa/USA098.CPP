/*
Reinier C�sar Mujica
11/4/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 101;

int N, SA, SB, A[MAXN], B[MAXN], i, cont;
bool mark[MAXN];
vector < int > G[MAXN];

int dfs( int v ) {
	mark[v]=true; cont++;
	for ( int c = 0; c < G[v].size(); c++ ) {
		int next = G[v][c];
		if ( !mark[next] ) dfs( next );
	}
}

int main() {
	int x;
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	/*..read..*/
	for ( i = 0; ; i++ ) {
		scanf( "%d", &x );
		if ( x == -1 ) break;
		N++;
		while ( x != -2 ) {
			G[i].push_back( x );
			scanf( "%d", &x );
		}
	}
	
	/*..search for the articulation points..*/
	for ( i = 1; i < N; i++ ) {
		fill( mark, mark + MAXN, false );
		mark[i]=true;
		cont=0;
		dfs( 0 );   
		if ( !mark[N] ) { //is articulation point
			A[++SA]=i;
			fill( mark, mark + MAXN, false );
			dfs( i );
			if ( cont == N+1 ) B[++SB]=i;  //is division point
		}
	}
	printf( "%d ", SA );
	for ( i = 1; i <= SA; i++ ) printf( "%d ", A[i] );
	printf( "\n" );
	printf( "%d ", SB );
	for ( i = 1; i <= SB; i++ ) printf( "%d ", B[i] );
	printf( "\n" );
	fflush( stdout );
	return 0;
}

/*
98� Carrera Callejera.                                        USA 2003
----------------------------------------------------------------------

En la Figura 1 se da un ejemplo de una trayectoria para una  carrera
callejera. Tu ves algunos puntos, rotulados del 0 hasta N  (aqu� N =
9), y algunas flechas conectando dichos puntos. El  punto  0  es  el
inicio de  la  carrera; y  el  punto  N  es  el  final. Las  flechas
representan calles de un  solo  sentido.  Los  participantes  de  la
carrera se mueven de un punto a otro por  las  calles,  s�lo  en  la
direcci�n en que se�ala la flecha. En  cada  punto  el  participante
puede  selecci�nar   cualquier   flecha   de   salida,  (Figura   1:
Trayectoria callejera con 10 puntos).

			1       4       7
			./ \    ./ \    ./ \
			/    .\ /    .\ /    .\
		0       3       6       9
			\    ./ \    ./ \    ./
			.\ /     \ /.____. /
			2       5       8

		Figura 1: trayectoria con 10 puntos.

Una trayectoria bien formada tiene las siguientes propiedades:
1. Cada punto en la trayectoria puede ser alcanzado desde el inicio.
2. El final puede ser alcanzado desde cada punto de la trayectoria.
3. El final no tiene flechas de salida.

Un participante no tiene que visitar cada punto  de  la  trayectoria
para llegar al final. Sin embargo habr� que  pasar forzosamente  por
algunos puntos (estos puntos son ineludibles). En el ejemplo,  estos
puntos  son 0, 3, 6 y 9.  Dada  una  trayectoria  bien  definida, el
programa tiene que determinar el conjunto de puntos ineludibles  que
todos los participantes tendr�n que vistar,  excluyendo  el inicio y
el final (Subtarea A). Sup�n que la carrera  tiene  que  llevarse  a
cabo en dos d�as consecutivos.  Para ese  prop�sito  la  trayectoria
tiene que ser dividida en dos trayectorias, una para cada d�a. En el
primer d�a, el punto de inicio es el 0, y el  final en  alg�n "punto
de divisi�n". En el segundo d�a el inicio es el punto de  divisi�n y
el final es en el punto N.  Dada  una  trayectoria  bien formada, tu
programa  deber�  determinar  el  conjunto  de  puntos  de  divisi�n
(Subtarea B). Un punto S es un punto de divisi�n para la trayectoria
bien definida C, si S es diferente del inicio y del final de C, y la
trayectoria puede ser partida en dos trayectorias bien formadas  que
no tengan flechas en com�n, y que tengan a S como el punto com�n. En
el ejemplo, solo el punto 3 es un punto de divisi�n.

Entrada

El archivo RACE.IN describe una trayectoria bien  definida  de  al
menos 5 puntos y a lo m�s 100 flechas. En  este  archivo hay   N + 1
l�neas. Las primeras N l�neas contienen los puntos  finales  de  las
flechas que parten de los puntos del 0 al N-1 respectivamente.  Cada
una de estas l�neas  termina  con  el  n�mero -2.  La  �ltima  l�nea
contiene el n�mero -1.

Salida

Tu programa deber� escribir dos  l�neas  en  el  archivo  de  salida
RACE.OUT. La primera l�nea  deber� contener  el  n�mero de  puntos
ineludibles en la trayectoria de entrada, seguido de  los r�tulos de
estos puntos, en  cualquier  orden (Subtarea A).  La  segunda  l�nea
deber� contener el n�mero de puntos de divisi�n de la trayectoria de
entrada, seguido por los r�tulos de todos estos puntos, en cualquier
orden (Subtarea B).

Ejemplo de Entrada y Salida

La Figura 2 da posibles archivos de entrada y salida para el ejemplo
de la Figura 1.

+-----------+ +------------+
� RACE.IN   � � RACE.OUT   �
+-----------� +------------�
� 1 2 -2    � � 2 3 6      �
� 3 -2      � � 1 3        �
� 3 -2      � +------------+
� 5 4 -2    �
� 6 4 -2    �
� 6 -2      �
� 7 8 -2    �
� 9 -2      �
� 5 9 -2    �
� -1        �
+-----------+
*/
