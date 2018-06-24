/*
 Reinier César Mujica
 26/05/08
 "Los Tazones de Agua"
*/

#include <cstdio>

#define REP( i, k, N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    MAXN = 30;

int sol = 1 << 29, i, j, limit, cont;
int T[MAXN], D[MAXN];

int main() {

    freopen( "bowls.in", "r", stdin );
    freopen( "bowls.out", "w", stdout );

    REP( i, 1, 20 )
     scanf( "%d", &T[i] );
    
    limit = (1 << 20) - 1;
    REP( i, 0, limit ) {
     if ( __builtin_popcount( i ) >= sol ) continue;
     REP( j, 1, 20 ) D[j] = T[j];
     cont = 0;

     REP( j, 0, 19 )
      if ( i & ( 1 << j ) ) {
        cont++;
        D[j] ^= 1; D[j + 1] ^= 1; D[j + 2] ^= 1;
      }
     if ( cont >= sol ) continue;
     
     bool ok = true;
     REP( j, 1, 20 )
      if ( D[j] ) {
        ok = false;
        break;
      }

     if ( ok )  sol <?= cont;
    }
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
