/*
 Reinier César Mujica
 18 - 12 - 2008
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 50010;
	
int N, C, sol;
int i, j;
int T[MAXN / 10];
bool dp[MAXN];

int main() {

	freopen( "hay4sale.in", "r", stdin );
	freopen( "hay4sale.out", "w", stdout );
	
	scanf( "%d %d", &N, &C );
	for ( i = 1; i <= C; i++ )
		scanf( "%d", &T[i] );
	
	dp[0] = true;
	for ( i = 1; i <= C; i++ ) {
		for ( j = N; j >= 0; j-- ) {
			if ( dp[j - T[i]] == true ) {
				dp[j] = true;
				sol >?= j;
			}
		}
	}
	
	printf( "%d\n", sol );
	return 0;
}
