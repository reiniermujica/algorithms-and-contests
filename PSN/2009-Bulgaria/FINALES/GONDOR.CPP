/*
 Reinier César Mujica
 22 - 4 - 2009
 Dijkstra
*/

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int
	MAXN = 105,
	oo = 1 << 30;

typedef double real;

struct point {
	int x, y;
} T[MAXN];

int N;
int i, j, k, x;
int C[MAXN];
bool mark[MAXN];
real min_dist[MAXN];
real dist[MAXN][MAXN];
real sol;
vector < int > V[MAXN];

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d %d", &T[i].x, &T[i].y );
		scanf( "%d", &C[i] );
		for ( j = 1; j < N; j++ ) {
			scanf( "%d", &k );
			V[i].push_back( k );
		}
	}
	
	/* CALC POINTS DIST */
	for ( i = 1; i <= N; i++ ) {
		for ( j = i + 1; j <= N; j++ ) {
			int d1 = abs( T[i].x - T[j].x );
			int d2 = abs( T[i].y - T[j].y );
			d1 = d1 * d1;
			d2 = d2 * d2;
			real d = sqrt( d1 + d2 );
			dist[i][j] = dist[j][i] = d;
		}	
	}
	
	/* FILL */
	for ( i = 0; i < MAXN; i++ )
		min_dist[i] = oo;
	mark[1] = true; min_dist[1] = 0; x = 1;
	
	for ( i = 1; i < N; i++ ) {
		
		/* updating */
		for ( j = 0; j < V[x].size() && C[x] > 0; j++ ) {
			int next = V[x][j];
			real cost = dist[x][next];
			if ( min_dist[x] < min_dist[next] ) {
				C[x]--;
				min_dist[next] <?= min_dist[x] + cost;
			}
		}
		
		/* searching */
		x = 0;
		for ( j = 1; j <= N; j++ )
			if ( !mark[j] && min_dist[j] < min_dist[x] )
				x = j;
		mark[x] = true;
	}
	
	for ( i = 1; i <= N; i++ )
		printf( "%lf\n", min_dist[i] );
	
	fflush( stdout );
	return 0;
}
