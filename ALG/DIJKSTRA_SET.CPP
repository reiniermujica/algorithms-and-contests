/*
 Reinier César Mujica
 9/4/08  PSN - 2008
 update xx/08/2008
*/

#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 10002,
    oo   = 1 << 29;
    
typedef pair< int, int > par;

int N, M, sol;
int i, j, k;
int D[MAXN];

vector< par > G[MAXN];
set < par > Q;

int main() {
  
    freopen( "dijkstra.in", "r", stdin );
    freopen( "dijkstra.out", "w", stdout );
  
	scanf( "%d %d", &N, &M );
    for ( i = 0; i < M; i++ ) {
        scanf( "%d %d %d", &j, &k, &sol );
        G[j].push_back( make_pair( k, sol ) );
        G[k].push_back( make_pair( j, sol ) );
    }
    
	fill( D, D + MAXN, oo ); D[1] = 0;
    Q.insert( make_pair( 0, 1 ) );
	
	/*..Dijkstra E lg V..*/
    while ( !Q.empty() ) {
        int node = ( *Q.begin() ).second;
        int cost = ( *Q.begin() ).first;
        Q.erase( Q.begin() );

        for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i].first;
            int ncos = G[node][i].second + cost;
            
			if ( D[next] != oo ) {
                if ( D[next] > ncos ) {
                   Q.erase( Q.find( make_pair( D[next], next ) ) );
                   D[next] = ncos;
                   Q.insert( make_pair( ncos, next ) );
                }
            }
            else
            {
              D[next] = ncos;
              Q.insert( make_pair( ncos, next ) );
            }
        }
    }
	
    printf( "%d\n", D[N] );
	
    fflush( stdout );
    return 0;
}
