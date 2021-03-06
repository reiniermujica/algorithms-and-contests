/*
 Reinier Cesar Mujica
 16/06/2008
 "Planeta X"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

const int
    MAXN = 1002;

int N, i, j, k;
int C[MAXN][MAXN];
int V[MAXN], S[MAXN];

void SWAP( int x, int y ) {
     int tmp;
     REP( tmp, 1, N + 1 )
      swap( C[x][tmp], C[y][tmp] );
}

int main() {

    freopen( "X.in", "r", stdin );
    freopen( "X.out", "w", stdout );

    scanf( "%d", &N );
    REP( i, 1, 2 * N - 3 ) {
      scanf( "%d %d", &j, &k );
      C[j][k] = 1;
      C[k][j] = 1;
    }
    REP( i, 1, N ) {
     scanf( "%d", &S[i] );
     C[i][i] = 1;
     C[i][N + 1] = S[i] ^ 1;
    }

    /* Gauss Method */
    REP( i, 1, N - 1 ) {
     REP( j, i, N )
      if ( C[j][i] ) {
        SWAP( i, j );
        break;
      }

     REP( j, i + 1, N ) {
      if ( C[j][i] )
        REP( k, i, N + 1 )
         C[j][k] = ( C[i][k] + C[j][k] ) % 2;
     }
    }

    for ( i = N; i > 0; i-- ) {
      for ( j = N; j > i; j-- )
       V[i] = ( V[i] + V[j]*C[i][j] ) % 2;
       V[i] = ( V[i] + C[i][N + 1] ) % 2;
      if ( V[i] && !C[i][i] ) {
        printf( "0" );
        exit(0);
      }
      V[i] = ( V[i] ^ C[i][i] ) ^ 1;
    }

    REP( i, 1, N )
     if ( V[i] ) printf( "%d ", i );

    printf( "\n" );
    
    fflush( stdout );
    return 0;
}

/*
 118� Planeta X                                             China 2000
----------------------------------------------------------------------

Todos los habitantes del planeta X contruyen sus casas de forma
triangular. A fin de ahorrar tiempo y esfuerzo, ellos usan un m�todo
especial de construci�n. Ellos inician la construcci�n con una pared en
l�nea recta. Despu�s, para la construcci�n  de cada nueva casa ellos
adicionan dos nuevas paredes alrededor de la pared ya existente
resultando una casa cerrada de forma triangular. Por supuesto las dos
nuevas paredes adicionadas tambi�n podr�an ser usadas como paredes de
inicio para nuevas casas. Algunas veces, usando este patr�n de
construcci�n, arriban a situaciones donde algunas casas est�n
completamente encerradas en otras (ver figura). Sin embargo, esto no
es un problema porque los chiquillos pueden vivir en casas incluidas.

Para alumbrar sus casas, los habitantes de X instalan un bombillo en
todas las esquinas del final de la construcci�n (un bombillo en una
esquina es com�n a todas las casas que comparten esa esquina). En cada
esquina, hay un interruptor el cual toc�ndolo cambia el estado del
bombillo (on/off) de la esquina y tambi�n el de todos los bombillos de
las esquinas conectadas. Dos esquinas se consideran conectadas si
est�n situadas al final de la misma pared.

Tarea

Escribir un programa que encuentre una secuencia de interruptores que
al tocarlos prendan todos los bombillos, comenzando con un estado
dado.

Entrada

Nombre de Fichero: X.IN
L�nea 1: N
. Un entero, el n�mero de esquinas de la edificaci�n, enumeradas
  desde 1 hasta el N;
L�nea 2..2*N-2: I  J
. Dos enteros, separados por un espacio, representando una pared
  entre las esquinas I y J;
L�nea 2*N-1: S1 S2 ... Sn
. N enteros (separados por espacios) cuyos valores son 0's � 1's,
  correspondiendo al estado de los bombillos;
. 0 significa apagado y 1 encendido.

Los datos de entrada garantizan la representaci�n de una construcci�n
hecha con el patr�n especificado.

Salida

Nombre de Fichero: X.OUT
L�nea 1: L1 L2 ... Lk
. K enteros, separados por espacio, representando la lista de los
  n�meros de los interruptores tocados.
. Si existen varias soluciones, solamente una es requerida.
. Si no hay posible soluci�n, usted debe escribir en el fichero de
  salida una simple l�nea conteniendo el n�mero 0.

L�mites:
* 3 � N � 1000

+-------------++-------+
� X.IN        �� X.OUT �
+-------------�+-------�
� 6           �� 1 6   �
� 1 3         �+-------+
� 1 4         �
� 1 5         �
� 2 3         �
� 2 4         �
� 3 4         �
� 3 6         �
� 4 5         �
� 4 6         �
� 0 1 1 1 0 0 �
+-------------+
*/
