/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

typedef long long int64;

const int
    MAXN = 100050,
    MMOD = 5000011;
    
int N, K;
int i;
int dp[MAXN][2];

int main() {

    freopen( "bullcow.in", "r", stdin );
    freopen( "bullcow.out", "w", stdout );
    
    scanf( "%d %d", &N, &K );
    dp[0][0] = 1;
    for ( i = 1; i <= N; i++ ) {
        dp[i][0] = ( dp[i - 1][0] + dp[i - 1][1] ) % MMOD;
        if ( i - K - 1 > 0 )
            dp[i][1] = ( dp[i - K - 1][0] + dp[i - K - 1][1] ) % MMOD;
        else dp[i][1] = 1;
    }
    
    printf( "%d\n", ( dp[N][0] + dp[N][1] ) % MMOD );
    return 0;
}
