/*
 Reinier César Mujica
 04/07/2008
 "Divisor Summation"
*/

#include <cstdio>

const int
    MAXN = 500001;

int N, T, i, j;
int dp[MAXN];

int main() {

    scanf( "%d", &T );
    
    for ( i = 2; i < MAXN; i++ ) {
     dp[i]++;
     for ( j = i + i; j < MAXN; j += i )
       dp[j] += i;
    }
    
    while ( T-- ) {
     scanf( "%d", &N );
     printf( "%d\n", dp[N] );
    }

    fflush( stdout );
    return 0;
}
