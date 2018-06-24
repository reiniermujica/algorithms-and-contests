/*
 Reinier Cesar Mujica
 4/06/08
 "PC"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 1002;

int N, IC, sol;
int i, j, k;
int dp[MAXN], C[MAXN][MAXN];

int main() {

    freopen( "pc.in", "r", stdin );
    freopen( "pc.out", "w", stdout );

    scanf( "%d%d", &IC, &N );
    
    for ( i = 1; i <= N; i++ )
     for ( j = i; j <= N; j++ )
      scanf( "%d", &C[i][j] );
      
    for ( i = 1; i <= N; i++ ) {
        dp[i] = 1 << 29;
        for ( j = 1; j <= i; j++ )
         dp[i] <?= dp[j - 1] + C[j][i] + IC;
    }
    
    printf( "%d\n", dp[N] );
    
    fflush( stdout );
    return 0;
}
