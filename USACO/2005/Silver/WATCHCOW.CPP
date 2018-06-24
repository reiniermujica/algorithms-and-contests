/*
 Reinier César Mujica
 16 - 10 - 2008
 el jd 11 stack overflow
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 10050,
	MAXM = 50050;
	
struct edge {
	int y, next;
	edge( int a = 0, int b = 0 ) {
		y = a; next = b;
	}
} ls[MAXM * 2];

int N, M;
int i, j, k;
int last[MAXN];
bool mark[MAXM * 2];

void dfs( int x ) {
	 
	 for ( int i = last[x]; i; i = ls[i].next ) {
		int next = ls[i].y;
		if ( mark[i] ) continue;
		mark[i] = true;
		dfs( next );
	 }

     printf( "%d\n", x );
}

int main() {

	freopen( "watchcow.in", "r", stdin );
	freopen( "watchcow.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d", &j, &k );
		ls[i] = edge( k, last[j] );
		last[j] = i;
		ls[i + M] = edge( j, last[k] );
		last[k] = i + M;
	}
		
	dfs( 1 );
	
	return 0;
}
