#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) for ( i = j; i <= k; i++ )

const int
    MAXN = 102,
    MAXM = 10002,
    oo = 1 << 29;
    
int N, M, L[MAXM];
int T[MAXN][MAXN];
int i, j, k, sol, last;

int main() {

    freopen( "danger.in", "r", stdin );
    freopen( "danger.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );

    REP( i, 1, M )
     scanf( "%d", &L[i] );
     
    REP( i, 1, N )
     REP( j, 1, N ) {
      scanf( "%d", &T[i][j] );
     }
     
    /* Floyd */
    REP( i, 1, N )
     REP( j, 1, N )
      if ( i != j )
      REP( k, 1, N )
       T[j][k] <?= T[j][i] + T[i][k];
       
    last = 1;
    REP( i, 2, M ) {
      sol += T[last][L[i]];
      last = L[i];
    }

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
