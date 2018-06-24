/*
 Reinier César Mujica
 11 - 3 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 100100,
	oo = 1 << 30;

typedef pair < int, int > par;
	
struct edge {
	int dest, cost, next;
	edge( int a = 0, int b = 0, int c = 0 ) {
		dest = a; cost = b; next = c;
	}
} ls[MAXN * 2];

int T, N, M, sol;
int A, B;
int i, j, k, c;
int D[MAXN];
int last[MAXN];

int main() {

	for ( scanf( "%d", &T ); T; T-- ) {
	
		fill( last, last + MAXN, 0 );
		fill( D, D + MAXN, oo );
        priority_queue < par, vector < par >, greater < par > > Q;
		
		scanf( "%d %d %d %d", &N, &M, &A, &B );
		for ( i = 1; i <= M; i++ ) {
			scanf( "%d %d %d", &j, &k, &c );
			ls[i] = edge( k, c, last[j] );
			last[j] = i;
			ls[i + M] = edge( j, c, last[k] );
			last[k] = i + M;
		}
		
		D[A] = 0;
		for ( Q.push( par( 0, A ) ); !Q.empty(); Q.pop() ) {
			int node = Q.top().second;
			int cost = Q.top().first;	
			for ( i = last[node]; i; i = ls[i].next ) {
				int next = ls[i].dest;
				int ncos = ls[i].cost + cost;
				if ( D[next] > ncos ) {
					D[next] = ncos;
					Q.push( par( ncos, next ) );
				}
            }
		}
		if ( D[B] == oo ) printf( "NONE\n" );
        else printf( "%d\n", D[B] );
	}
	
	fflush( stdout );
	return 0;
}
