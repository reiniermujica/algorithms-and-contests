/*
 Reinier Cesar Mujica
 update xx/08/2008
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
	MAXV = 5002,
	MAXE = 10002,
	oo = 1 << 29;

struct edge {
	int dest, cost;
};

int N, E, sol;
int i, j, k;
int D[MAXV];
bool S[MAXV];
vector < edge > G[MAXV];

int main() {
    
    freopen( "dijkstra.in", "r", stdin );
    freopen( "dijkstra.out", "w", stdout );
    
	scanf( "%d %d", &N, &E );
	for ( i = 0; i < E; i++ ) {
		scanf( "%d %d %d", &j, &k, &sol );
		G[j].push_back( (edge) { k, sol } );
		G[k].push_back( (edge) { j, sol } );
	}

	/* ...Dijkstra N^2 ... */
	fill( D, D + MAXV, oo ); D[k = 1] = 0;
	for ( i = 1; i < N; i++ ) {
      
	  S[k] = true;
      for ( j = 0; j < G[k].size(); j++ ) {
		int next = G[k][j].dest;
		int cost = G[k][j].cost + D[k];
		if ( D[next] > cost )
           D[next] = cost;
	  }
	  
      k = 0;
      for ( j = 1; j <= N; j++ )
          if ( !S[j] && D[j] < D[k] ) k = j;
      if ( k == 0 ) {
		printf( "NO SOLUTION\n" );
		return 0;
	  }
	}
    
	printf( "%d\n", D[N] );
	
	fflush( stdout );
	return 0;
}
