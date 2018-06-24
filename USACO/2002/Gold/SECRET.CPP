/*
 Reinier César Mujica
 11 - 3 - 2009
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 2050,
    oo = 1 << 30;

typedef pair < int, int > par;

struct edge {
	int x, y, cost;
	edge ( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; cost = c;
	}
};

int N, M, sol, cut;
int i, j, k, c;
int lo, hi, x;
int cost[MAXN][MAXN];
int max_edge[MAXN][MAXN];
int dist[MAXN], last[MAXN];
par Q[MAXN];
bool MST[MAXN][MAXN];
bool mark[MAXN];
vector < edge > ls;

int main() {

    freopen( "secret.in", "r", stdin );
    freopen( "secret.out", "w", stdout );
	
	scanf( "%d %d\n", &N, &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d %d", &j, &k, &c );
		cost[j][k] = cost[k][j] = c;
		ls.push_back( edge( j, k, c ) );
	}
	
	/* Prim */
	fill( dist, dist + MAXN, oo );
	dist[1] = 0;
	for ( i = 1; i <= N; i++ ) {
	
		x = 0;
		for ( j = 1; j <= N; j++ )
			if ( !mark[j] && dist[j] < dist[x] )
				x = j;
		
		/* saving edge */
		MST[x][last[x]] = MST[last[x]][x] = true;
		
		sol += dist[x];
		
		mark[x] = true;
		for ( j = 1; j <= N; j++ ) {
			int ncos = cost[x][j];
			if ( cost[x][j] && ncos < dist[j] ) {
				dist[j] = ncos;
				last[j] = x;
			}
		}
	}
	
	/* Bfs */
	Q[++hi] = par( 1, 0 );
	fill( mark, mark + MAXN, 0 );
	mark[1] = true;
	
	while ( lo < hi ) {
		lo++;
		int node = Q[lo].first;
		int father = Q[lo].second;
		for ( i = 1; i <= N; i++ ) {
			if ( MST[node][i] && !mark[i] ) {
				mark[i] = true;
				Q[++hi] = par( i, node );
			}
		}		
		c = cost[node][father];
		for ( i = lo - 1; i; i-- ) {
			max_edge[node][Q[i].first] >?= cost[node][father] >?
										   max_edge[father][Q[i].first];
			max_edge[Q[i].first][node] >?= cost[node][father] >?
										   max_edge[father][Q[i].first];
		}
	}
	
	cut = oo;
	for ( i = 0; i < M; i++ )
		if ( !MST[ls[i].x][ls[i].y] ) {
			if ( ls[i].cost - max_edge[ls[i].x][ls[i].y] < cut )
				cut = ls[i].cost - max_edge[ls[i].x][ls[i].y];
		}
	
	printf( "%d\n", sol + cut );
	
    fflush( stdout );
    return 0;
}
