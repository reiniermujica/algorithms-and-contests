/*
 Reinier César Mujica
 18 - 3 - 2009
 Good Knaspack
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 55,
    MAXD = 15;
    
int N, D, M;
int i, j, k;
int cost[MAXN][MAXD];
int dp[500001];

int main() {

    freopen( "stock.in", "r", stdin );
    freopen( "stock.out", "w", stdout );
    
    scanf( "%d %d %d", &N, &D, &M );
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= D; j++ )
            scanf( "%d", &cost[i][j] );

    for ( i = 1; i <= D; i++ ) {
        
        /* filling */
        for ( j = 0; j <= M; j++ )
            dp[j] = j; 
    
        /* Knaspack */
        for ( j = 1; j <= N; j++ ) {
            int W = cost[j][i];
            int C = cost[j][i + 1];
            for ( k = W; k <= M; k++ ) {
                if ( dp[k - W] + C > dp[k] )
                    dp[k] = dp[k - W] + C;
            }
        }
    
        M = dp[M];
    }
    
    printf( "%d\n", M );
    return 0;
}
