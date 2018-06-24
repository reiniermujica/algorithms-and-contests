/*
 Reinier César Mujica
 xx/08/2008
 "Tree Cutting"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 10005;

struct EDGE {
	int u, v, next;
	EDGE( int x = 0, int y = 0, int c = 0 ) {
		u = x; v = y; next = c;
	}
} E[2 * MAXN];

int N, cont;
int i, j, k;
int last[2 * MAXN];
int cant[MAXN], M[MAXN];

void dfs( int x ) {
	 cant[x] = 1;
	 for ( int i = last[x]; i; i = E[i].next ) {
		int next = E[i].v;
		if ( !cant[next] ) {
          dfs( next );
		  cant[x] += cant[next];
		  M[x] >?= cant[next];
        }
	 }
}

int main() {

    freopen( "treecut.in", "r", stdin );
    freopen( "treecut.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i < N; i++ ) {
		scanf( "%d %d", &j, &k );
		E[i] = EDGE( j, k, last[j] );
		last[j] = i;
		E[i + N] = EDGE( k, j, last[k] );
		last[k] = i + N;
	}
	
    dfs( 1 );
	for ( i = 1; i <= N; i++ ) {
       if ( M[i] <= N / 2 && N - cant[i] <= N / 2 )
        printf( "%d\n", i );
	}
	
    fflush( stdout );
    return 0;
}
