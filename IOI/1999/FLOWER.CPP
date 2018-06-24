/*
 Reinier Mujica Hdez
 IOI 1999 "Flowers"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 110;
    
int V, F, sol = -10000;
int i, j, k;
int dp[MAXN][MAXN];
int val[MAXN][MAXN];
int cut[MAXN][MAXN];

int print( int x, int y ) {
    if ( !cut[x][y] ) {
        printf( "%d ", y );
        return 0;
    }
    else
     print( x - 1, cut[x][y] );
    printf( "%d ", y );
}

int main() {

    freopen( "flower.in", "r", stdin );
    freopen( "flower.out", "w", stdout );

    scanf( "%d %d", &F, &V );
    for ( i = 1; i <= F; i++ )
     for ( j = 1; j <= V; j++ )
      scanf( "%d", &val[i][j] );
      
    /* ...simple DP ~O(N^3)... */
    for ( i = 1; i <= F; i++ )
      for ( j = i; j <= V; j++ ) {

        dp[i][j] = -1000;
        for ( k = i - 1; k < j; k++ )
         if ( dp[i][j] < dp[i - 1][k] ) {
            dp[i][j] = dp[i - 1][k];
            cut[i][j] = k;
         }
        
        dp[i][j] += val[i][j];
      }

    for ( i = F; i <= V; i++ )
      if ( sol < dp[F][i] ) {
          sol = dp[F][i];
          k = i;
      }

    printf( "%d\n", sol );
    print( F, k );
    printf( "\n" );

    fflush( stdout );
    return 0;
}
