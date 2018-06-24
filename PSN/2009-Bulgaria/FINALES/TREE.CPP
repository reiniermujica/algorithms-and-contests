/*
 Reinier César Mujica
 15 - 4 - 2009
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 1005,
	oo = 1 << 30;
	
int N;
int i, j, k;
int l, cost;
int T[MAXN];
int dp[MAXN][MAXN];
int root[MAXN][MAXN];

int main() {
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &T[i] );
		T[i] += T[i - 1];
	}
	
	for ( i = 1; i <= N; i++ ) root[i][i] = i;
	
	/* DP */
	for ( i = 2; i <= N; i++ ) {
		for ( j = 1; j <= N - i + 1; j++ ) {
			l = i + j - 1;
			dp[j][l] = oo;
			
			for ( k = root[j][l - 1]; k <= root[j + 1][l]; k++ ) {
				cost = dp[j][k - 1] + dp[k + 1][l];
				cost += (T[l] - T[j - 1]);
				cost -= T[k] - T[k - 1];
				if ( dp[j][l] > cost ) {
					dp[j][l] = cost;
					root[j][l] = k;
				}
			}
		}
	}
	
	printf( "%d\n", dp[1][N] );
	return 0;
}
