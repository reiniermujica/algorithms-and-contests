/*
 Reinier César Mujica
 16/08/2008
 "Sumsets"
*/

#include <cstdio>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1000002,
    MOD = 1000000000;

int N, i, j;
int dp[MAXN];

int main() {

    freopen( "SUMSET.in", "r", stdin );
    freopen( "SUMSET.out", "w", stdout );

	scanf( "%d", &N );
	
	dp[0] = 1;
	for ( i = 1; i <= N; i *= 2 ) {
		for ( j = i; j <= N; j++ ) {
			dp[j] = ( dp[j] + dp[j - i] ) % MOD;
		}
	}
	
	printf( "%d\n", dp[N] );
	
    fflush( stdout );
    return 0;
}
