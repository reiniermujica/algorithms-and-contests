/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050;
	
int N, M;
int sol, sol2;
int i, j, k;
int T[MAXN];

int main() {

	freopen( "auction.in", "r", stdin );
	freopen( "auction.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= M; i++ )
		scanf( "%d", &T[i] );
	
	sort( T + 1, T + M + 1 );
	for ( i = 1; i <= M; i++ ) {
		j = min( N, M - ( i - 1 ) );
		k = T[i] * j;
		if ( sol < k ) {
			sol = k;
			sol2 = T[i];
		}
	}
	
	printf( "%d %d\n", sol2, sol );
	
	fflush( stdout );
	return 0;
}
