/*
 Reinier César Mujica
 17 - 3 - 2009
 Big Integer Sumation
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 1010;

int N, K;
int i, j;
int dp[MAXN][MAXN];
int len[MAXN];

int suma( int save, int a, int b ) {
    int carry, i;
    if ( len[a] < len[b] )
        swap( a, b );

    carry = 0;
    for ( i = 1; i <= len[a]; i++ ) {
        dp[save][i] = ( dp[a][i] + dp[b][i] + carry );
        carry = dp[save][i] / 10;
        dp[save][i] %= 10;
    }
    
    len[save] = len[a];
    while ( carry > 0 ) {
        dp[save][++len[save]] = carry % 10;
        carry /= 10;
    }
}

int main() {
    
    freopen( "ddayz.in", "r", stdin );
    freopen( "ddayz.out", "w", stdout );
    
    scanf( "%d %d", &N, &K );
    
    len[0] = dp[0][1] = 1;
    for ( i = 1; i <= K; i++ )
        for ( j = i; j <= N; j++ )
            suma( j, j, j - i );
    
    for ( i = len[N]; i; i-- )
        printf( "%d", dp[N][i] );
    printf( "\n" );
    
    fflush( stdout );
    return 0;
}
