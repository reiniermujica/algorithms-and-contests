/*
 Reinier Cesar Mujica
 16/06/2008
 "Metodo de Gauss "
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) \
 for ( i = (j); i <= (k); i++ )

const int
    MAXN = 5002;
    
typedef double real;

int N, i, j, k, aux;
real V[MAXN];
int C[MAXN][MAXN];

void SWAP( int x, int y ) {
     for ( int i = 1; i <= N + 1; i++ )
        swap( C[x][i], C[y][i] );
}

int main() {

    freopen( "gauss.in", "r", stdin );
    freopen( "gauss.out", "w", stdout );
    
    scanf( "%d", &N );
    
    REP( i, 1, N )
     REP( j, 1, N + 1 )
      scanf( "%d", &C[i][j] );

    REP( i, 1, N - 1 ) {
      REP( j, i, N )
        if ( C[j][i] ) {
          SWAP( i, j );
          break;
        }

      REP( j, i + 1, N )
        if ( C[j][i] ) {
          aux = C[j][i];
          REP( k, i, N + 1 ) {
            C[j][k] = C[i][k] * aux - C[j][k] * C[i][i];
          }
        }
    }

    for ( i = N; i > 0; i-- ) {
       V[i] = C[i][N + 1];
       for ( j = N; j > i; j-- )
         V[i] -= C[i][j] * V[j];
       if ( !C[i][i] ) V[i] = 0;
       else V[i] /= C[i][i];
    }

    REP( i, 1, N )
     printf( "%.2lf\n", V[i] );
  
    fflush( stdout );
    return 0;
}

/*
3
1 1 1 10
2 2 1 16
1 1 2 14
*/
