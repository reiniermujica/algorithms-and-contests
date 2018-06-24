/*
 Reinier César Mujica
 30 - 12 - 2008
 Burning whit Santa Claus...
*/

#include <cstdio>
#include <cmath>

using namespace std;

const int
	MAXN = 250010,
	MAXL = 19;
	
typedef double real;

int N, M;
int i, j, k, lg;
real T[MAXN][MAXL];

int main() {
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%lf", &T[i][0] );

	/* RMQ */
	lg = (int)log2( N );
	for ( i = 1; i <= lg; i++ ) {
		k = 1 << i;
		for ( j = 1; j <= N; j++ )
			T[j][i] =  T[j][i - 1] <? T[j + ( k / 2 )][i - 1];
	}
	
	/* answer queries */
	scanf( "%d", &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d", &j, &k );
		j++; k = ( j > k ) ? j : k;
		lg = (int)log2( k - j );
		printf( "%lf\n", T[j][lg] <? T[k - ( 1 << lg ) + 1][lg] );
	}

	fflush( stdout );
	return 0;
}
