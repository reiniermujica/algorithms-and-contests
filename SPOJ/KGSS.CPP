/*
 Reinier César Mujica
 9 - 3 - 2009
 Segment Tree
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
	MAXN = 100050;
	
int N, M, sol;
int i, j, k;
char ch;
par tree[10 * MAXN];

int update( int node, int lo, int hi, int x, int amount ) {
	if ( hi < x || lo > x ) return 0;
	if ( lo == hi ) {
		tree[node].first = amount;
		return 0;
	}
	int mid = ( lo + hi ) / 2;
	update( node * 2, lo, mid, x, amount );
	update( node * 2 + 1, mid + 1, hi, x, amount );
	par l = tree[node * 2], r = tree[node * 2 + 1];
	if ( l.first > r.first ) {
		tree[node].first = l.first;
		tree[node].second = l.second >? r.first;
	}
	else {
		tree[node].first = r.first;
		tree[node].second = r.second >? l.first;
	}
		
	return 0;
}

int query( int node, int lo, int hi, int x, int y ) {
	if ( lo > y || hi < x ) return 0;
	
	if ( lo >= x && hi <= y ) {
        sol >?= tree[node].first + tree[node].second;
        return tree[node].first;
    }
	
	int mid = ( lo + hi ) / 2;
	int l = query( node * 2, lo, mid, x, y );
	int r = query( node * 2 + 1, mid + 1, hi, x, y );
	sol >?= l + r;
			
	return l >? r;
}

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &k );
		update( 1, 1, MAXN, i, k );
	}
	
	scanf( "%d\n", &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%c %d %d\n", &ch, &j, &k );
		if ( ch == 'U' )
			update( 1, 1, MAXN, j, k );
		else {
			sol = 0;
			query( 1, 1, MAXN, j, k );
			printf( "%d\n", sol );
		}
	}
	
	fflush( stdout );
	return 0;
}
