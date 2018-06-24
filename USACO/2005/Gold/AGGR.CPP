/*
 Reinier César Mujica
 5 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 100050,
	MAXX = 1000000000;
	
int N, M, Q, sol;
int i, j, k;
int lo, hi, mid;
int T[MAXN];

bool ok( int dist ) {
	 int i, last = 0, k = M;
	 for ( i = 1; i <= N && k; i++ ) {
		if ( T[i] - last >= dist || i == 1 ) {
			k--;
			last = T[i];
		}
	 }
	 return k == 0;
}

int main() {

    freopen( "aggr.in", "r", stdin );
    freopen( "aggr.out", "w", stdout );
    
/*	scanf( "%d", &Q );
	while ( Q-- ) { */
		scanf( "%d %d", &N, &M );
		for ( i = 1; i <= N; i++ )
			scanf( "%d", &T[i] );
		
		sort( T + 1, T + N + 1 );
		
		lo = 0; hi = MAXX; sol = 0;
		while ( lo <= hi ) {
			mid = ( lo + hi ) >> 1;
			if ( ok( mid ) ) {
				sol >?= mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
	
		printf( "%d\n", sol );
//	}

	fflush( stdout );
	return 0;
}
