/*
 Reinier César Mujica
 23 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 10005;
    
int N, M;
int i, j;
int T[MAXN];
int dp[MAXN];

int main() {
    
    freopen( "cowrun.in", "r", stdin );
    freopen( "cowrun.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &T[i] );
     
    for ( i = 0; i < N; i++ ) {

        if ( dp[i] > dp[i + 1] ) dp[i + 1] = dp[i];

        int s = dp[i], k = i;
        for ( j = 1; j <= M && k < N; j++ ) {
            s += T[i + j];
            k += 2;
            dp[k] >?= s;
        }
    }
    
    printf( "%d\n", dp[N] );
    return 0;
}
