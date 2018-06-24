/*
 Reinier César Mujica
 20 - 11 - 2008
*/

#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int64;

int64 N, top, sol;
int64 i, lo, k;

int main() {

	freopen( "hsums.in", "r", stdin );
	freopen( "hsums.out", "w", stdout );

	scanf( "%lld", &N );
	for ( i = 1; i <= N; i++ ) {
        if ( ( i + ( i + 1 ) ) > N ) { sol++; break; }
        top = N - i;
        lo = ( i * ( i + 1 ) ) >> 1;
        lo += top;
        lo = lo << 1;
        k = (int)sqrt( lo );
        if ( ( k * ( k + 1 ) ) == lo ) sol++;
    }
	
	printf( "%lld\n", sol );
	return 0;
}
