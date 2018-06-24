/*
 Reinier César Mujica
 1 - 1 - 2009
 O(lg(N)) N = exponent
*/

#include <cstdio>

using namespace std;

int N, M = 2, sol = 1;

int main() {

	freopen( "power.in", "r", stdin );
	freopen( "power.out", "w", stdout );
	
	scanf( "%d", &N );
	while ( N > 0 ) {
		if ( N & 1 )
			sol *= M;
		M *= M;
		N /= 2;
	}

	printf( "%d\n", sol );
	return 0;
}
