/*
 Reinier Cesar Mujica
 06/06/08
 "Big Mean"
*/

#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int
    MAXN = 100002,
    MAXL = 205,
    logM = 17;

int N, Q, i, j, k;
int M[MAXN][logM];
char T[MAXN][MAXL];

int b_max( int x, int y ) {
    int s1 = strlen( T[x] + 1);
    int s2 = strlen( T[y] + 1);
    if ( s1 < s2 ) return y;
    if ( s1 > s2 ) return x;

    for ( int i = 1; i <= s1; i++ ) {
      if ( T[x][i] != T[y][i] ) {
       return ( T[x][i] > T[y][i] ) ? x : y;
      }
    }

    return x;
}

int main() {

    freopen( "big.in", "r", stdin );
    freopen( "big.out", "w", stdout );

    scanf( "%d %d\n", &N, &Q );
    
    for ( i = 1; i <= N; i++ ) {
      gets( T[i] + 1 );
      M[i][0] = i;
    }

    for ( i = 1; i <= (int)log2( N ); i++ ) {
      k = 1 << i; // 2 ^ i
      for ( j = 1; j <= N - k + 1; j++ ) {
        M[j][i] = b_max( M[j][i - 1], M[j + k / 2][i - 1] );
      }
    }
    
    for ( i = 0; i < Q; i++ ) {
      scanf( "%d %d", &j, &k );
      N = (int)log2( k - j );
      printf( "%s\n",T[b_max( M[j][N], M[k - (1 << N) + 1][N])] + 1 );
    }
    
    fflush( stdout );
    return 0;
}

/*128� Big Mean.                                             M�xico 2006
----------------------------------------------------------------------

En la  preselecci�n todos  los estudiantes  quieren participar  en las
olimpiadas,  pero  no  todos  pueden,  a  partir  de  este  a�o pueden
participar casi todos los estudiantes porque hay muchos eventos,  para
estos  eventos  los profesores  seleccionan  a los  estudiantes  de la
siguiente forma: entre  el estudiante K,K+1,K+2,...,Y  va a ir  el que
mayor promedio tenga entre todos ellos, el promedio de cada estudiante
es un n�mero que estar� entre 10^0 y 10^200.

Tarea.
Ayude a los profesores a determinar que estudiante ir� al evento X.

Entrada

En la primera l�nea del  fichero de entrada BIG.IN habr�n  dos n�meros
3<=N<=100000, 1<=M<=100000  que ser�n  el n�mero  de estudiantes  y la
cantidad de eventos que hay  en esa asignatura respectivamente. En  la
l�nea 2 y  hasta la N+1  habr� un n�mero  por l�nea que  representa el
promedio del  i-�simo estudiante.  En la  l�nea N+2  y hasta  la l�nea
N+M+1 habr�n dos n�meros enteros 1<=K<=N y K<Y<=N.

Salida.

En el fichero de  salida BIG.OUT habr�n M n�meros,  el i-�simo  n�mero
representa el promedio del estudiante que va al i-�simo evento.

Ejemplo de entrada. (BIG.IN)
4 3
1
9
5
10
1 2
1 3
2 4

Ejemplo de salida. (BIG.OUT)
9
9
10

NOTA:  No se  le permite  usar B�fer,  en caso  contrario su  programa
obtendr� 0 puntos.
*/
