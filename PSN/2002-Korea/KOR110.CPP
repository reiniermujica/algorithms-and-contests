/*
 Reinier César Mujica
 28 - 12 - 2008
 I'm the daddy of the maxflow...
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 250,
	MAXD = 150,
	MAXI = MAXN + MAXD;
	
int N, K, D, max_flow;
int i, j, k, cc;
int source = 0, sink;
int cap[MAXI][MAXI], flow[MAXI][MAXI];
int cant[MAXI], last[MAXI];

bool augment( int src, int snk ) {
	 fill( last, last + MAXI, -1 );
	 cant[src] = 1 << 30;
	 
	 bool ok = false;
	 queue < int > Q;
	 
	 /* Ford-Fulkerson Alg */
	 for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		i = Q.front();
		for ( j = 1; j <= snk; j++ ) {
			if ( flow[i][j] < cap[i][j] && last[j] < 0 ) {
				last[j] = i;
				cant[j] = min( cant[i], cap[i][j] - flow[i][j] );
				Q.push( j );
                if ( j == snk ) {
                    ok = true;
                    break;
                }
			}
		}
        if ( ok ) break;
     }
	 
	 if ( last[snk] < 0 ) return false;
	 
	 i = snk; k = cant[snk];
	 while ( last[i] != -1 ) {
    	flow[last[i]][i] += k;
		flow[i][last[i]] -= k;
		i = last[i];
	 }

     max_flow += k;
	 return true;
}

int main() {

	freopen( "party.in", "r", stdin );
	freopen( "party.out", "w", stdout );
	
	scanf( "%d %d %d", &N, &K, &D );
	sink = N + D + 1;
	for ( i = 1; i <= D; i++ ) {
		scanf( "%d", &k );
		cap[N + i][sink] = k;
	}
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &k );
		for ( j = 1; j <= k; j++ ) {
			scanf( "%d", &cc );
			cap[i][N + cc] = 1;
		}
	}
	for ( i = 1; i <= N; i++ )
		cap[source][i] = K;
	
	/* augmenting patch */
	while ( augment( source, sink ) );
	
	printf( "%d\n", max_flow );
	return 0;
}
