/*

*/

#include <cstdio>

using namespace std;

const int
	MAXN = 500;
	
int N, sol;
int i, j, k;
int dp[MAXN][MAXN];

int main() {

	freopen( "NUMTRI.IN", "r", stdin );
	freopen( "NUMTRI.OUT", "w", stdout );

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= i; j++ ) {
			scanf( "%d", &k );
			dp[i][j] = ( dp[i - 1][j - 1] >? dp[i - 1][j] ) + k;
			sol >?= ( i == N ) ? dp[i][j] : 0;
		}
	}
	
	printf( "%d\n", sol );
	return 0;
}
