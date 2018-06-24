/*
 Reinier César Mujica
 13 - 10 - 2008
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 1010;
	
int N, M, K, sol;
int i, j, k, s;
int cow[MAXN];

int main() {
	
	freopen( "disease.in", "r", stdin );
	freopen( "disease.out", "w", stdout );
	
	scanf( "%d %d %d", &N, &M, &K );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &k );
		for ( j = 1; j <= k; j++ ) {
            scanf( "%d", &s );
        	cow[i] |= 1 << ( s - 1 );
        }
	}
	
	for ( i = 0; i < ( 1 << M ); i++ ) {
        if ( __builtin_popcount( i ) > K ) continue;
		s = 0;
	    for ( j = 1; j <= N; j++ )
         s += ( ( cow[j] & ~i ) == 0 );
        sol >?= s;
    }

    printf( "%d\n", sol );

    return 0;
}
