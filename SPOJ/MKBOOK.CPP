/*
 Reinier César Mujica
 22 - 11 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050,
	MAXD = 12;
	
int N, M, T;
int i, k;
int cant[MAXN][MAXD];
int temp[MAXD];

int main() {

	for ( i = 1; i < MAXN; i++ ) {
		memcpy( cant[i], cant[i - 1], sizeof( cant[i - 1] ) );
		k = i;
		while ( k > 0 ) {
			cant[i][k % 10]++;
			k /= 10;
		}
	}
	
	for ( T = 1; ; T++ ) {
		
		scanf( "%d", &N );
		if ( N == 0 ) break;
		scanf( "%d", &M );
        if ( N > M ) swap( N, M );
		for ( i = 0; i < 10; i++ )
			temp[i] = cant[M][i] - cant[N - 1][i];
			
		printf( "Case %d: ", T );
		for ( i = 0; i < 9; i++ )
			printf( "%d:%d ", i, temp[i] );
		printf( "%d:%d\n", 9, temp[9] );
	}
	
	fflush( stdout );
	return 0;
}
