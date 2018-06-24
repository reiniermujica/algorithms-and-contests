/*
 Reinier César Mujica
 xx/08/2008
 "Coaster"
 Dynamic Path using Dijkstra Alg
 O( M * lg( N ) )
 */

#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1002;

struct EDGE {
	int dest, fun, cost;
	EDGE ( int _x = 0, int _y = 0, int _c = 0 ) {
		dest = _x; fun = _y; cost = _c;
	}
};

int N, M, cant, sol;
int i, j, k;
int cost, funny, next;
int dp[MAXN][MAXN]; //max funny at node i whit cost j

struct cmp {
    bool operator()( const EDGE &a, const EDGE &b ) {
     return a.fun > b.fun;
	}
};

vector < EDGE > G[MAXN];
set < EDGE, cmp > S;


int main() {

    freopen( "coaster.in", "r", stdin );
    freopen( "coaster.out", "w", stdout );

    scanf( "%d %d %d", &N, &M, &cant );
    FOR( i, 1, M ) {
		scanf( "%d %d %d %d", &j, &k, &funny, &cost );
		G[j].push_back( EDGE( j + k, funny, cost ) );
    }
    
	S.insert( EDGE( 0, 0, 0 ) );
	while ( !S.empty() ) {
		EDGE T = *S.begin();
		S.erase( S.begin() );

		j = T.dest;
		for ( i = 0; i < G[j].size(); i++ ) {
			next = G[j][i].dest;
			funny = G[j][i].fun + T.fun;
			cost = G[j][i].cost + T.cost;
			
			if ( cost > cant || ( cost == cant && next != N )) continue;
			if ( dp[next][cost] < funny ) {
				if ( S.find( EDGE( next, dp[next][cost], cost ) ) != S.end() )
                 S.erase( S.find( EDGE( next, dp[next][cost], cost ) ) );
				dp[next][cost] = funny;
				S.insert( EDGE( next, dp[next][cost], cost ) );
			}
		}
	}

	FOR( i, 0, cant )
	 sol >?= ( dp[N][i] ) ? dp[N][i] : 0;
    
	printf( "%d\n", ( sol ) ? sol : -1 );
	
    fflush( stdout );
    return 0;
}
