/*
 Reinier César Mujica
 17 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1005;
	
int N, sol;
int i, j, k;
int val1, val2;
int T[MAXN][3];
int dp[MAXN][3];

int main() {
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d %d", &T[i][1], &T[i][2] );
	
	/* dp base case */
	dp[1][1] = T[1][2];
	dp[1][2] = T[1][1];
	
	/* dp */
	for ( i = 2; i <= N; i++ ) {
		
		val1 = dp[i - 1][1] + abs( T[i][1] - T[i - 1][1] ) + T[i][2];
		val2 = dp[i - 1][2] + abs( T[i][1] - T[i - 1][2] ) + T[i][2];
		dp[i][1] = val1 >? val2;
		
		val1 = dp[i - 1][1] + abs( T[i][2] - T[i - 1][1] ) + T[i][1];
		val2 = dp[i - 1][2] + abs( T[i][2] - T[i - 1][2] ) + T[i][1];
		dp[i][2] = val1 >? val2;
	}
	

	printf( "%d\n", dp[N][1] >? dp[N][2] );
	return 0;
}
