/*
 Reinier César Mujica
 28 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 3050;
	
int N, sol, f, l;
int i, j, k;
int S[MAXN];

int main() {

	freopen( "pasture.in", "r", stdin );
	freopen( "pasture.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d", &S[i] );
		
	sol = 1 << 30;
	for ( i = 1; i <= N; i++ ) {
		k = 0;
		for ( j = i; j <= N; j++ ) {
			k += S[j];
			if ( abs( k ) < sol  ) {
				sol = abs( k );
				f = i;
				l = j;
			}
			if ( abs( k ) == sol && ( j - i ) > ( l - f ) ) {
                f = i;
                l = j;
            }
		}
	}
	
	printf( "%d %d %d\n", f, l, sol );
	return 0;
}
