/*
 Reinier César Mujica
 4 - 3 - 2009
 Bipartite Matching
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 1505;
	
int N, M, flow;
int source, sink;
int i, j, k;
int cap[MAXN][MAXN];
int last[MAXN];

bool augment() {
	 queue < int > Q;
	 memset( last, -1, sizeof last );
	 
	 for ( Q.push( source ); !Q.empty() && last[sink] < 0; Q.pop() ) {
		int node = Q.front();
		for ( i = 1; i <= sink; i++ )
			if ( cap[node][i] > 0 && last[i] < 0 ) {
				last[i] = node;
				Q.push( i );
			}
	 }

	 if ( last[sink] < 0 ) return false;
	 
	 i = sink;
	 while ( i != source ) {
		cap[last[i]][i]--;
		cap[i][last[i]]++;
		i = last[i];
	 }
	 return true;
}

int main() {

	freopen( "asteroid.in", "r", stdin );
	freopen( "asteroid.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	source = 0; sink = N * 2 + 1;
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d", &j, &k );
		cap[source][j] = 1;
		cap[j][k + N] = 1;
		cap[k + N][sink] = 1;
	}
	
	while ( augment() ) flow++;
	
	printf( "%d\n", flow );
	return 0;
}
