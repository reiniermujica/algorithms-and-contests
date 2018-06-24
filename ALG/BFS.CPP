/*
 Reinier Cesar Mujica
 update xx/08/2008
*/

#include <cstdio>
#include <queue>
#include <vector> 
#include <algorithm>

using namespace std;

const int
	MAXN = 10002,
	oo = 1 << 29;

typedef pair< int, int > par;

int N, E, sol;
int i, j, k;
int D[MAXN];

vector < par > G;
queue < int > Q;

int main() {

	freopen( "BFS.IN", "r", stdin );
	freopen( "BFS.OUT", "w", stdout );
	
	scanf( "%d %d", &N, &E );
	for ( i = 0; i < E; i++  ) {
		scanf( "%d %d %d", &j, &k, &sol );
		G[j].push_back( par( k, sol ) );
		G[k].push_back( par( j, sol ) );
	}
	
	fill( D, D + MAXN, oo ); D[1] = 0;

	/*... BFS (V + E) ...*/
	for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
		sol = Q.front();
		for ( i = 0; i < G[sol].size(); i++ ) {
			int next = G[sol][i].first;
			int cost = G[sol][i].second + D[sol];
			if ( D[next] > cost ) {
				D[next] = cost;
				Q.push( next );	
			}
		}
	}
	
	printf( "%d\n", D[N] );
	
	fflush( stdout );
    return 0;
}
