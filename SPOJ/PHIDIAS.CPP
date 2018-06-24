/*
 Reinier Cesar Mujica
 10/06/2008
 "Phidias"
*/

#include <cstdio>

const int
    MAXN = 602;

int N, W, H, T;
int i, j, k;
int dp[MAXN][MAXN];

int main() {

    scanf( "%d", &T );
    while ( T-- ) {

     scanf( "%d %d", &W, &H );
     scanf( "%d", &N );
     
     for ( i = 1; i <= W; i++ )
      for ( j = 1; j <= H; j++ )
       dp[i][j] = i * j;
      
     for ( i = 1; i <= N; i++ ) {
       scanf( "%d %d", &j, &k );
       dp[j][k] = 0;
     }

     for ( i = 1; i <= W; i++ )
      for ( j = 1; j <= H; j++ ) {
       for ( k = 1; k <= ( i / 2 ); k++ )
        dp[i][j] <?= dp[k][j] + dp[i - k][j];

       for ( k = 1; k <= ( j / 2 ); k++ )
        dp[i][j] <?= dp[i][k] + dp[i][j - k];
      }
     
     printf( "%d\n", dp[W][H] );
    }
    
    fflush( stdout );
    return 0;
}
