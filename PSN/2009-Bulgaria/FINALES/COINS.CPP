/*
 Reinier César Mujica
 21 - 4 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 1000005,
    MAXQ = 55;
    
int N, L, K, M;
int i, k;
int dp[MAXN];
int Q[MAXQ];

int main() {

    scanf( "%d %d %d", &K, &L, &M );
    for ( i = 1; i <= M; i++ ) {
        scanf( "%d", &Q[i] );
        k >?= Q[i];
    }
    
    for ( i = 1; i <= k; i++ ) {
        int fi = dp[i - 1];
        int se = ( i - K >= 0 ) ? dp[i - K] : 1;
        int tr = ( i - L >= 0 ) ? dp[i - L] : 1;
        if ( fi && se && tr ) dp[i] = 0;
        else dp[i] = 1;
    }

    for ( i = 1; i <= M; i++ ) {
        if ( dp[Q[i]] ) printf( "A" );
        else printf( "B" );
    }
    
    printf( "\n" );
    return 0;
}
