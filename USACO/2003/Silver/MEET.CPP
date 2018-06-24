/*
 Reinier César Mujica
 22 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050;
	
int N, M, C, sol;
int i, j, k;
int lo, hi, mid;
int cant[MAXN];

int main() {

	freopen( "meet.in", "r", stdin );
	freopen( "meet.out", "w", stdout );
	
	scanf( "%d %d %d", &M, &N, &C );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d", &k );
		cant[k + 1]++;
	}
		
	for ( i = 1; i <= N; i++ )
		cant[i] += cant[i - 1];
	
	for ( i = 1; i <= N; i++ ) {
		lo = i; hi = N;
		
		while ( lo <= hi ) {
			mid = ( lo + hi ) / 2;
			if ( cant[mid] - cant[i] <= C ) {
				sol >?= ( mid - i );
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
	}

	printf( "%d\n", sol );
	return 0;
}
