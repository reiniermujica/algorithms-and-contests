/*
 Reinier César Mujica
 xx/08/2008
 "Bad Cowtractors"
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1005;

struct EDGE {
	int u, v, cost;
	EDGE( int a = 0, int b = 0, int c = 0 ) {
		u = a; v = b; cost = c;
	}
	bool operator < ( const EDGE &other ) const {
		return cost > other.cost;
	}
};

int N, M, sol;
int i, j, k;
int x, y, c;
int P[MAXN];
vector < EDGE > E;

int find_set( int x ) {
	if ( x != P[x] )
	 P[x] = find_set( P[x] );
	return P[x];
}

int main() {

    freopen( "cowtract.in", "r", stdin );
    freopen( "cowtract.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	FOR( i, 1, M ) {
		scanf( "%d %d %d", &x, &y, &c );
		E.push_back( EDGE( x, y, c ) );
	}
	
	sort( E.begin(), E.end() );
	FOR( i, 1, N ) P[i] = i;
	
	FOR( i, 0, M - 1 ) {
		x = E[i].u; y = E[i].v; c = E[i].cost;
		j = find_set( x );
		k = find_set( y );
		if ( j != k ) {
			sol += c;
			P[j] = k;
		}
	}
	
	k = 0;
	FOR( i, 1, N )
     if ( P[i] == i ) k++;
	
	printf( "%d\n", ( k == 1 ) ? sol : -1 );
    
	fflush( stdout );
    return 0;
}
