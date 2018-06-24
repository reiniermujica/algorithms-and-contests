/*
 Reinier César Mujica
 17 - 12 - 2008
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 150,
	oo = 1 << 30;
	
int N;
int i, j, k;
int T[MAXN];
int dp[MAXN][MAXN];

int main() {

	while ( scanf( "%d", &N ) != EOF ) {

		for ( i = 1; i <= N; i++ ) {
			scanf( "%d", &T[i] );
			T[i] += T[i - 1];
        }
			
		for ( i = 0; i <= N; i++ )
	  	 for ( j = i + 1; j <= N; j++ )
    	   dp[i][j] = oo;

		for ( i = 2; i <= N; i++ ) { // size
			for ( j = 1; j <= N - i + 1; j++ ) {
				int hi = ( j + i ) - 1;
				for ( k = j; k < hi; k++ ) {
                    int c1 = ( T[k] - T[j - 1] ) % 100;
                    int c2 = ( T[hi] - T[k] ) % 100;
					int cost = ( c1 * c2 ) + dp[j][k] + dp[k + 1][hi];
					if ( dp[j][hi] > cost )
						dp[j][hi] = cost;
				}
            }
        }
        
        printf( "%d\n", dp[1][N] );
	}
	
	fflush( stdout );
	return 0;
}
