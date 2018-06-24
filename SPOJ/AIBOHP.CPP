/*
 Reinier César Mujica
 3 - 4 - 2009
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int
	MAXN = 6150;
	
int T, N;
int i, j, k;
int dp[2][MAXN];
char cad[MAXN];
bool ok;

int main() {
	
	for ( scanf( "%d\n", &T ); T; T-- ) {
		gets( cad + 1 ); N = strlen( cad + 1 );
		ok = true;
		memset( dp, 0, sizeof dp );
		for ( i = 1; i <= N; i++ ) {
			for ( j = 1; j <= N; j++ ) {
				if ( cad[i] == cad[N - j + 1] )
					dp[ok][j] = dp[!ok][j - 1] + 1;
				else
					dp[ok][j] = dp[!ok][j] >? dp[ok][j - 1];
			}
			ok = !ok;
		}
		printf( "%d\n", N - dp[!ok][N] );
	}
	
	return 0;
}
