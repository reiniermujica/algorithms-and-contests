/*
 Reinier Cesar Mujica
 17/06/2008
 "Stol"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 402;
    
int N, M, sol;
int i, j, lo, hi;
int dp[MAXN][MAXN];
int last[MAXN], next[MAXN];
char cad[MAXN];

int main() {

    scanf( "%d %d\n", &N, &M );
    
    for ( i = 1; i <= N; i++ ) {
        gets( cad + 1 );
        for ( j = 1; j <= M; j++ ) {
            if ( cad[j] == '.' )
             dp[i][j] = dp[i-1][j] + 1;
            else
             dp[i][j] = 0;
        }
    }

    for ( i = 1; i <= N; i++ ) {

       fill( last, last + MAXN, 0 );
       fill( next, next + MAXN, 0 );

       for ( j = 2; j <= M; j++ ) {
        if ( dp[i][j] == 0 ) continue;

        lo = j - 1; 
        while ( dp[i][j] <= dp[i][lo] ) {
            lo = last[lo];
            if ( lo == 0 ) break;
        }
        last[j] = lo;
       }

       for ( j = M; j > 0; j-- ) {
        if ( dp[i][j] == 0 ) continue;

        hi = j + 1;
        while ( dp[i][j] <= dp[i][hi] ) {
            hi = next[hi];
            if ( hi == 0 ) break;
        }
        if ( hi != 0 ) next[j] = hi;
        else next[j] = j + 1;
       }

       for ( j = 1; j <= M; j++ )
        sol >?=  ( ( next[j] - last[j] - 1 ) * 2 ) +
                   ( dp[i][j] * 2);
    }

    printf( "%d\n", sol - 1 );
    
    fflush( stdout );
    return 0;
}
