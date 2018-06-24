/*
 Reinier César Mujica
 9 - 3 - 2009
 Segment Tree Funny
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 100050;
	
int N, sol;
int i, j, k;
int x, y, c;
int tree[4 * MAXN];

int query( int node, int lo, int hi, int x ) {
	if ( lo > x || hi < x ) return 0;
	if ( lo == hi ) return tree[node];
	int mid = ( lo + hi ) / 2;
	if ( x <= mid ) return tree[node] +
					query( node * 2, lo, mid, x );
	else
	if ( x <= hi ) return tree[node] +
		   query( node * 2 + 1, mid + 1, hi, x );
}

int update( int node, int lo, int hi, int x, int y, int amount ) {
	if ( lo > y || hi < x ) return 0;
	if ( lo >= x && hi <= y ) {
		tree[node] += amount;
		return 0;
	}
	int mid = ( lo + hi ) / 2;
	update( node * 2, lo, mid, x, y, amount );
	update( node * 2 + 1, mid + 1, hi, x, y, amount );
}

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d\n", &x, &y );

		j = query( 1, 1, MAXN, x );
		k = query( 1, 1, MAXN, y );
		printf( "%d\n", j + k );

		update( 1, 1, MAXN, x + 1, y - 1, 1 );
		update( 1, 1, MAXN, x, x, -j );
		update( 1, 1, MAXN, y, y, -k );
	}
	
	fflush( stdout );
	return 0;
}
