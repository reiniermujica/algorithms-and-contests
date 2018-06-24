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

vector< par > G[MAXN];
priority_queue< par, vector< par >, greater< par > > Q;

int main(){
 
    freopen( "dijkstra.in", "r", stdin );
    freopen( "dijkstra.out", "w", stdout );
    
	scanf( "%d %d", &N, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &j, &k, &sol );
        G[j].push_back( make_pair( k, sol ) );
		G[k].push_back( make_pair( j, sol ) );
    }
	
	fill( D, D + MAXN, oo ); D[1] = 0;
    Q.push( make_pair( 0, 1 ) );
    
	/*...Dijkstra E lg V ...*/
    while ( !Q.empty() ) {
        int node = Q.top().second;
        int cost = Q.top().first;
        Q.pop();
        
		for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i].first;
            int ncos = G[node][i].second + cost;
            if ( D[next] > ncos ) {
				D[next] = ncos;
				Q.push( make_pair( ncos, next ) );
            }
        }
    }
	
    printf( "%d\n", D[N] );
    
	fflush(stdout);
	return 0;
}
