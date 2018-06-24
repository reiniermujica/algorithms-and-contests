/*
 Reinier César Mujica
 17 - 11 - 2008
 The Good Translations of Mario Cruz ()
 cause I got 10 points
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 60550,
	MAXM = 150,
    oo = 1 << 30;

struct hay {
	int x, y;
	hay ( int a = 0, int b = 0 ) {
		x = a; y = b;
	}
} T[MAXM];

int N, M, sol = oo;
int i, j, k;
int dp[MAXN];

int main() {

    freopen( "buyhay.in", "r", stdin );
    freopen( "buyhay.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d", &j, &k );
		T[i] = hay( j, k );
	}
	
	fill( dp, dp + MAXN, oo ); dp[0] = 0;
	for ( i = 0; i <= M; i++ )
		if ( dp[i] != oo ) {
			for ( j = 1; j <= N; j++ )
				if ( dp[i] + T[j].y < dp[i + T[j].x] )
					dp[i + T[j].x] = dp[i] + T[j].y;
		}
	
	for ( i = M; i < MAXN; i++ )
	 sol <?= dp[i];
	
	printf( "%d\n", sol );
	
    fflush( stdout );
    return 0;
}
