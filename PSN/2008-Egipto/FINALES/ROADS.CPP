/*
 Reinier César Mujica
 xx/08/2008
 "Construcción de Carreteras"
*/

#include <cstdio>
#include <stack>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1005;

struct EDGE {
	int u, v, next;
	EDGE( int _u = 0, int _v = 0, int _next = 0 ) {
		u = _u; v = _v; next = _next;
	}
} ls[2 * MAXN];

int N, M, sol, bcc;
int i, j, k, dc_time;
int dfsnum[MAXN], low[MAXN];
int BCC[MAXN], last[MAXN];
int cant[MAXN];
stack < int > S;

void dfs( int x, int father ) {
	 dfsnum[x] = low[x] = ++dc_time;
	 S.push( x );
	 
	 for ( int i = last[x]; i; i = ls[i].next ) {
		if ( ls[i].v == father ) continue;
		
		int node = ls[i].v;
		if ( !low[node] ) {
			dfs( node, x );
			low[x] <?= low[node];
		}
		else
		 low[x] <?= low[node];
	 }
	 
	 if ( dfsnum[x] == low[x] ) {
		bcc++;
		while ( !BCC[x] ) {
			BCC[ S.top() ] = bcc;
			S.pop();
		}
	 }
}

int main() {

    freopen( "roads.in", "r", stdin );
    freopen( "roads.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	FOR( i, 1, M ) {
		scanf( "%d %d", &j, &k );
		ls[i] = EDGE( j, k, last[j] );
		last[j] = i;
		ls[i + M] = EDGE( k, j, last[k] );
		last[k] = i + M;
	}
	
	dfs( 1, -1 ); // find all biconected components
	
	FOR( i, 1, N ) { // find biconected components whit only one children
		if ( cant[BCC[i]] > 1 ) continue;
		for ( j = last[i]; j; j = ls[j].next ) {
			int next = ls[j].v;
			if ( BCC[i] != BCC[next] ) cant[BCC[i]]++;
		}
	}

	FOR( i, 1, bcc ) 
	 if ( cant[i] == 1 ) sol++;
	 
	printf( "%d\n", ( sol + 1 ) / 2 );

    fflush( stdout );
    return 0;
}
