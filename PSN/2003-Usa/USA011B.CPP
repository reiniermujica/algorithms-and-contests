/*
 Reinier César Mujica
 4 - 1 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1100,
	MAXW = 250,
	oo = 1 << 30;
	
int N, M, sol;
int i, j, k;
int dp[MAXN], cam[MAXN], S[MAXW];
int len[MAXW];
char cad[MAXN];
char W[MAXW][MAXW];

bool match( int x, int y ) {
	 int i, j = 1, k = len[y], c = x + k - 1;
	 if ( N - x + 1 < k ) return false;
	 
	 for ( i = x; i <= c; i++, j++ )
		if ( cad[i] != W[y][j] ) return false;
	
	 return true;
}

int main() {

	freopen( "SECRET.in", "r", stdin );
	freopen( "SECRET.out", "w", stdout );
	
	scanf( "%d\n", &N );
	gets( cad + 1 );
	scanf( "%d\n", &M );
	for ( i = 1; i <= M; i++ ) {
		gets( W[i] + 1 );
		len[i] = strlen( W[i] + 1 );
	}

	fill( dp, dp + MAXN, oo ); dp[0] = 0;
	
	for ( i = 1; i <= M; i++ ) {
		for ( j = N; j > 0; j-- ) {
			if ( dp[j - 1] != oo && match( j, i ) ) {
				if ( dp[j + len[i] - 1] > dp[j - 1] + 1 ) {
					dp[j + len[i] - 1] = dp[j - 1] + 1;
					cam[j + len[i] - 1] = i;				
				}
			}
		}
	}
	
	printf( "%d\n", dp[N] );
	j = N; sol = 0;
	while ( j > 0 ) {
        S[++sol] = cam[j];
        j -= len[cam[j]];
    }

    for ( i = sol; i > 0; i-- )
        printf( "%s\n", W[S[i]] + 1 );
        
	fflush( stdout );
	return 0;
}