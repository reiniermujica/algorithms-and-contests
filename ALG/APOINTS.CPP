/*
 Reinier César Mujica
 28/3/08 
 update 6/01/2010
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
	MAXV = 10002;

int N, E, dc_time;
int low[MAXV];
int i, j, k;
bool mark[MAXV];
vector< int > G[MAXV], S;

int dfs( int x ) {
    low[x] = ++dc_time; 
	int min_k = low[x], next, i;
	
    for ( i =  0; i < G[x].size(); i++ ) {
		if ( !low[G[x][i]] ) {
			next = dfs( G[x][i] );
			if ( next >= low[x] && !mark[x] ) {
			  S.push_back( x );
			  mark[x] = true;
			}
  		  min_k <?= next;
		} 
		else
		  min_k <?= low[G[x][i]];
	}
    
	return min_k;
}

int main() {
    
	freopen( "apoints.in", "r", stdin );
    freopen( "apoints.out", "w", stdout );
    
	scanf( "%d %d", &N, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &j, &k );
        G[j].push_back( k );
        G[k].push_back( j );    
    }
	
    dfs( 1 );
    
	printf( "%d\n", S.size() );
	for ( i = 0; i < S.size(); i++ ) 
		printf( "%d\n", S[i] );
	 
    fflush(stdout);
    return 0;    
}
