/*
 Reinier César Mujica
 20 - 3 - 2009
 Dynamic Programing
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 2005,
    MAXM = 1005,
    MMOD = 100000000;

int N, M, sol;
int i, j, k;
int dp[2][MAXM];
bool ok = true;

int mod( int a ) {
    if ( a % M ) return a % M;
    else return M;
}

int main() {
    
    freopen( "fristeam.in", "r", stdin );
    freopen( "fristeam.out", "w", stdout );
    
    dp[ok][0] = 1;
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++, ok = !ok ) {
        scanf( "%d", &k );

        k = mod( k );
        for ( j = 0; j <= M; j++ )
            dp[!ok][j] = dp[ok][j];
        
        for ( j = 0; j <= M; j++ ) {
            if ( dp[ok][j] ) {
                int next = mod( j + k );
                int sum = dp[ok][j];
                dp[!ok][next] = ( sum + dp[!ok][next] ) % MMOD;
            }
        }
    }

    sol = dp[ok][M];
    printf( "%d\n", sol );
    
    return 0;
}
