/*
 Reinier César Mujica
 4 - 3 - 2009
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1050,
	oo = 1 << 30;
	
int N, E;
int A, B, K, G;
int i, j, k, c;
int dist[MAXN];
int cost[MAXN][MAXN], bush[MAXN][MAXN];
int ls[MAXN];
bool mark[MAXN];

int main() {
	
	scanf( "%d %d", &N, &E );
	scanf( "%d %d %d %d", &A, &B, &K, &G );
	for ( i = 1; i <= G; i++ ) {
		scanf( "%d", &ls[i] );
	}
	for ( i = 1; i <= E; i++ ) {
		scanf( "%d %d %d", &j, &k, &c );
		cost[j][k] = cost[k][j] = c;
	}

    k = 0;
    for ( i = 2; i <= G; i++ ) {
    	bush[ls[i - 1]][ls[i]] = k + cost[ls[i - 1]][ls[i]];
    	bush[ls[i]][ls[i - 1]] = k + cost[ls[i - 1]][ls[i]];
    	k += cost[ls[i - 1]][ls[i]];
    }
	
	fill( dist, dist + MAXN, oo );
	dist[k = A] = K;

	for ( i = 1; i < N; i++ ) {
		
		mark[k] = true;

		/* updating */
		for ( j = 1; j <= N; j++ ) {
			if ( cost[k][j] != 0 ) {
				c = ( dist[k] + cost[k][j] );
				if ( bush[k][j] != 0 && bush[k][j] - cost[k][j] <= dist[k] )
                    c = max( bush[k][j], dist[k] ) + cost[k][j];
				dist[j] <?= c;
			}
		}
		
		/* find min piv */
		k = 0;
		for ( j = 1; j <= N; j++ ) {
			if ( dist[j] < dist[k] && !mark[j] ) k = j;
		}
	}
	
	printf( "%d\n", dist[B] - K );
	return 0;
}