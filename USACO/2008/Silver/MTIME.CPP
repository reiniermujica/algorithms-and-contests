/*
 Reinier César Mujica
 24 - 11 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050;

struct time {
	int x, y;
	bool operator < ( const time &other ) const {
		 if ( y != other.y ) return y < other.y;
		 return x > other.x;
	}
} ls[MAXN];
	
int N, M, i;

int main() {
	
	freopen( "mtime.in", "r", stdin );
	freopen( "mtime.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d %d", &ls[i].x, &ls[i].y );
	
	sort( ls + 1, ls + N + 1 ); M = ls[N].y - ls[N].x;
	for ( i = N - 1; i > 0; i-- ) {
		M <?= ls[i].y;
		M -= ls[i].x;
	}

	printf( "%d\n", ( M > 0 ) ? M : -1 );
	return 0;
}
