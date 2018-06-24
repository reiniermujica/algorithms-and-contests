/*
 Reinier Cesar Mujica
 18/06/2008
 "Incendio"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

const int
    MAXN = 60,
    MAXM = 550,
    oo = 1 << 29;

int N, M, sol;
int i, j, k;
int T[MAXN][MAXM], dp[MAXN][MAXM];
int C[MAXN][MAXM];
int S[MAXN];

int main() {

    freopen( "INCENDIO.DAT", "r", stdin );
    freopen( "INCENDIO.SOL", "w", stdout );

    scanf( "%d %d", &N, &M );
    REP( i, 1, N )
     scanf( "%d", &S[i] );

    REP( i, 1, N )
     REP( j, 1, M )
      scanf( "%d", &T[i][j] );
      
    REP( i, 1, M )
     dp[1][i] = T[1][i];
     
    REP( i, 2, N ) {
     REP( j, S[i], M )
      REP( k, S[i - 1], j - 1 )
       if ( j - k >= S[i] && dp[i - 1][k] )
        if ( dp[i][j] < dp[i - 1][k] + T[i][j - k] ) {
         dp[i][j] = dp[i - 1][k] + T[i][j - k];
         C[i][j] = k;
        }
    }

    REP( i, S[N], M )
     if ( sol < dp[N][i] ) {
        sol = dp[N][i];
        k = i;
     }
     
    printf( "%d\n", sol );
    j = N;
    while ( k ) {
     S[j] = k - C[j][k];
     k = C[j][k];
     j--;
    }
    
    REP( i, 1, N )
     printf( "%d\n", S[i] );

    fflush( stdout );
    return 0;
}
