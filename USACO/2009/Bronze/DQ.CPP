/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 350;
    
int N, M, sol;
int i, j, k;
int dp[MAXN];

int main() {
    
    freopen( "DQ.in", "r", stdin );
    freopen( "DQ.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    
    dp[0] = 1;
    for ( i = 1; i <= M; i++ ) {
        scanf( "%d", &k );
        for ( j = k; j <= N; j++ )
            dp[j] += dp[j - k];
    }
    
    printf( "%d\n", dp[N] );
    return 0;

}
