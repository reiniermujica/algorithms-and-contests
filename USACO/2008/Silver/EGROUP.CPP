/*
 Reinier César Mujica
 25 - 3 - 2009
 This can be optimized
 but the idea is great
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 30005;
    
int N, sol = 1 << 30;
int i, j, k;
int dp[MAXN][4];

int main() {
    
    freopen( "egroup.in", "r", stdin );
    freopen( "egroup.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &dp[i][0] );
        
    /* dp for increasing sec */
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= 3; j++ ) {
            if ( j == 1 ) k = dp[i - 1][1];
            if ( j == 2 ) k = dp[i - 1][1] <? dp[i - 1][2];
            if ( j == 3 ) k = dp[i - 1][1] <? dp[i - 1][2] <?
                              dp[i - 1][3];
            dp[i][j] = ( k + ( dp[i][0] != j ) );
        }
    }
    sol <?= dp[N][1] <? dp[N][2] <? dp[N][3];
    
    /* dp for decreasing sec */
    for ( i = N; i > 0; i-- ) {
        for ( j = 1; j <= 3; j++ ) {
            if ( j == 1 ) k = dp[i + 1][1];
            if ( j == 2 ) k = dp[i + 1][1] <? dp[i + 1][2];
            if ( j == 3 ) k = dp[i + 1][1] <? dp[i + 1][2] <?
                              dp[i + 1][3];
            dp[i][j] = ( k + ( dp[i][0] != j ) );
        }
    }
    sol <?= dp[1][1] <? dp[1][2] <? dp[1][3];
    
    printf( "%d\n", sol );
    return 0;
}
