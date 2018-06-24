/*
 Reinier César Mujica
 19 - 11 - 2010
 SCC
*/

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

const int
	MAXN = 10005;
	
int N, M;
int i, j, k;
int V[MAXN], SCC[MAXN], scc;
int scc_val[MAXN], best[MAXN];
int dfs_num[MAXN], dc_time;
vector < int > G[MAXN];
vector < int > G2[MAXN];
stack < int > S;

int dfs_scc( int node ) {
	S.push( node );
	dfs_num[node] = ++dc_time;
	int low = dc_time;
	
	for ( int i = 0; i < G[node].size(); i++ ) {
		int next = G[node][i];
		if ( !dfs_num[next] )
			low <?= dfs_scc( next );
		else 
        if ( !SCC[next] ) 
          low <?= dfs_num[next];
	}
	
	if ( low == dfs_num[node] ) { //is a root of scc
		scc++;
		while ( !SCC[node] ) {
			SCC[S.top()] = scc;
			scc_val[scc] += V[S.top()];
			S.pop();
		}
	}
	return low;
}

void dfs_val( int x ) {
	 best[x] += scc_val[x];
	 
	 for ( int i = 0; i < G2[x].size(); i++ ) {
		int next = G2[x][i];
		if ( best[next] < best[x] + scc_val[next] ) {
			best[next] = best[x];
			dfs_val( next );
		}
	 }
}

int main() {

	freopen( "tesoros.in", "r", stdin );
	freopen( "tesoros.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 0; i < N; i++ )
		scanf( "%d", &V[i] );
	for ( i = 0; i < M; i++ ) {
		scanf( "%d %d", &j, &k );
		G[j].push_back( k );		
	}
	
	dfs_scc( 0 ); //find all scc
	
    for ( i = 0; i < N; i++ ) 
        for ( j = 0; j < G[i].size(); j++ ) {
			k = G[i][j];
			if ( SCC[i] != SCC[k] )
				G2[SCC[i]].push_back( SCC[k] );
		}
    
    dfs_val( SCC[0] ); //find max value
    
   	printf( "%d\n", best[SCC[N - 1]] );
	return 0;
}
