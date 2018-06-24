/*
 Reinier César Mujica
 15 - 6 - 2009
*/

#include <cstdio>
#include <queue>
#include <map>
#include <string>
#include <algorithm> 

using namespace std;

typedef pair < int, int > par;

const int
    MAXN = 10050;

struct edge {
    int des, cost, next;
    edge( int a = 0, int b = 0, int c = 0 ) {
		des = a; cost = b; next = c;
    }
} ls[MAXN * 20];

int T, N, C, E, Q;
int i, j, k;
int nr, cost;
int dist[MAXN];
int P[MAXN];
char cad[15], cad1[15];
map < string, int > M;

int dijkstra( int x, int y ) {
	int i;
	memset( dist, -1, sizeof dist );
	dist[x] = 0;
	priority_queue < par, vector < par >, greater < par > > S;
	
	for ( S.push( par( 0, x ) ); !S.empty(); S.pop() ) {
		int node = S.top().second;
        int cost = S.top().first;

        if ( cost > dist[node] ) continue;
        if ( node == y ) return dist[y];

		for ( i = P[node]; i; i = ls[ i].next ) {
			int next = ls[i].des;
			int ncos = ls[i].cost + cost;
			if ( dist[next] == -1 || dist[next] > ncos ) {
				dist[next] = ncos;
				S.push( par( ncos, next ) );
			}			
		}
	}
	
	return dist[y];
}

int main() {

	for ( scanf( "%d", &T ); T; T-- ) {
		
		/* initialize */
   		C = E = 0;
   		M.clear();
        memset( P, 0, sizeof P );

		/* read */		
		scanf( "%d", &N );
		for ( i = 0; i < N; i++ ) {
			scanf( "%s", cad );
			M[cad] = ++C;
			scanf( "%d", &k );
			for ( j = 0; j < k; j++ ) {
				scanf( "%d %d", &nr, &cost );
				ls[++E] = edge( nr, cost, P[C] );
				P[C] = E;
			}
		}
		
		/* answering queries */
		for ( scanf( "%d", &Q ); Q; Q-- ) {
			scanf( "%s %s", cad, cad1 );
			j = M[cad]; k = M[cad1];
			printf( "%d\n", dijkstra( j, k ) );
		}
	}
	
    fflush( stdout );
    return 0;
}
