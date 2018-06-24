/*
 Reinier César Mujica
 5 - 3 - 2009
 Disjoints Patch Problem
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 80050,
	MAXE = 80050;

struct edge {
	int u, v, next;
	int cap; // flow capacity
	edge( int a = 0, int b = 0, int c = 0, int d = 0 ) {
		u = a; v = b; next = c; cap = d;
	}
} ls[MAXE * 2];
	
int N, E, T;
int i, j, k;
int from[MAXN], last[MAXN];

bool augment( int source, int sink ) {
	 
	 memset( from, 0, sizeof from );
	 queue < int > Q;

	 /* Ford-Fulkerson Alg */
     for ( Q.push( source ); !Q.empty() && !from[sink]; Q.pop() ) {
		k = Q.front();
		for ( j = last[k]; j; j = ls[j].next ) {
			int next = ls[j].v;
			if ( !from[next] && ls[j].cap > 0 ) {
				from[next] = j;
				Q.push( next );
			}
		}
	 }
	 
	 if ( !from[sink] ) return false; // is over augmentings path

	 i = sink;
	 while ( i != source ) {
        k = from[i];
        ls[k].cap--;
	    if ( k > E ) k = k - E;
		else k = k + E;
		ls[k].cap++;
		i = ls[from[i]].u;
	 }

	 return true;
}

int main() {
	
	scanf( "%d", &T );
	while ( T-- ) {
	
		/* fill */
		memset( last, 0, sizeof last );
		
		scanf( "%d %d", &N, &E );
		for ( i = 1; i <= E; i++ ) {
			scanf( "%d %d", &j, &k );
			ls[i] = edge( j, k, last[j], 1 );
			last[j] = i;
			ls[i + E] = edge( k, j, last[k], 1 );
			last[k] = i + E;
		}
		
		if ( augment( 1, 2 ) && augment( 3, 2 ) )
			printf( "YES\n" );
		else printf( "NO\n" );
	}

	fflush( stdout );
	return 0;
}
