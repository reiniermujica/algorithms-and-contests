/*
 Reinier César Mujica
 17 - 11 - 2008
*/

#include <cstdio>

using namespace std;

int T, N, M;

int rev( int x ) {
	int res = 0;
	while ( x ) {
		res = ( res * 10 ) + ( x % 10 );
		x /= 10;
	}
	return res;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &N, &M );
		printf( "%d\n", rev( rev( N ) + rev( M ) ) );	
	}

	fflush( stdout );
	return 0;
}
