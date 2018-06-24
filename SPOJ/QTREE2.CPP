/*
 Reinier César Mujica
 7 - 11 - 2008
 day in the mother birthday
*/

#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 40051,
	MAXL = 20;
	
struct edge { 
	int des, cost, next;
	edge( int a = 0, int b = 0, int c = 0 ) {
		des = a; cost = b; next = c;
	}
} ls[2 * MAXN];

int T, N, sol;
int i, j, k;
int x, y, c, lg;
int L[MAXN], last[MAXN];
int LCA[MAXN][MAXL];
int dist[MAXN][MAXL];
char cad[10];

queue < int > Q;

int comp( char *x ) {
    if ( strstr( x, "DIST" ) ) return 1;
    if ( strstr( x, "KTH" ) ) return 2;
    if ( strstr( x, "DONE" ) ) return 3;
}

int lowest_ca( int x, int y ) {
	int i, lg;
	if ( L[x] < L[y] ) swap( x, y );
	lg = (int)log2( L[x] );
	for ( i = lg; i >= 0; i-- )
		if ( L[x] - ( 1 << i ) >= L[y] && LCA[x][i] != -1 )
			x = LCA[x][i];
	if ( x != y ) {
		lg = (int)log2( L[x] );
		for ( i = lg; i >= 0; i-- )
			if ( LCA[x][i] != -1 && LCA[x][i] != LCA[y][i] ) {
				x = LCA[x][i];
				y = LCA[y][i];
			}
		x = LCA[x][0];
	}
	return x;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		
		/* fill */
		for ( i = 0; i < MAXN; i++ ) {
		 fill( LCA[i], LCA[i] + MAXL, -1 );
		 fill( dist[i], dist[i] + MAXL, 0 );
		 L[i] = 0;
         last[i] = 0;
		}
		
		/* read */
		scanf( "%d", &N );
		for ( i = 1; i < N; i++ ) {
			scanf( "%d %d %d", &j, &k, &sol );
			ls[i] = edge( k, sol, last[j] );
			last[j] = i;
			ls[i + N] = edge( j, sol, last[k] );
			last[k] = i + N;
		}
		
		/* BFS */
		L[1] = 1;
		for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
			int act = Q.front();
			for ( i = last[act]; i; i = ls[i].next ) {
				int next = ls[i].des;
				if ( !L[next] ) {
					L[next] = L[act] + 1;
					Q.push( next );
					
					/* computing LCA */
					lg = (int)log2( L[next] );
					LCA[next][0] = act;
					dist[next][0] = ls[i].cost;
					for ( j = 1; j <= lg; j++ )
						if ( LCA[act][j - 1] != -1 ) {
							LCA[next][j] = LCA[LCA[next][j - 1]][j - 1];
							dist[next][j] = dist[next][j - 1] +
                                            dist[LCA[next][j - 1]][j - 1];
						}
				}
			}
		}
		
		/* Queries */
        while ( 1 ) {
              scanf( "%s", &cad );
              c = comp( cad );
              if ( c == 1 ) { // distance between nodes
                 scanf( "%d %d\n", &x, &y );
				 sol = 0;
                 if ( L[x] < L[y] ) swap( x, y );
				 lg = (int)log2( L[x] );
				 for ( i = lg; i >= 0; i-- )
					if ( L[x] - (1 << i) >= L[y] && LCA[x][i] != -1 ) {
						sol += dist[x][i];
						x = LCA[x][i];
					}
				 if ( x != y ) {
					lg = (int)log2( L[x] );
					for ( i = lg; i >= 0; i-- )
						if ( LCA[x][i] != - 1 && LCA[x][i] != LCA[y][i] ) {
							sol += dist[x][i] + dist[y][i];
							x = LCA[x][i];
							y = LCA[y][i];
						}
					sol += dist[x][0] + dist[y][0];
				 }
				 printf( "%d\n", sol );
              }
              if ( c == 2 ) {
                 scanf( "%d %d %d\n", &x, &y, &k );
            	 /* after 30m thinking about this part, I decide to try all possible cases and I expected got AC */
				 int cx = x, cy = y, top;
				 int lc = lowest_ca( x, y );
				 if ( lc == x || lc == y ) { // is OK do not touch it boy!!! (after 15m)
					if ( lc	== x ) top = L[x] + k - 1;
					else top = L[x] - k + 1;
					if ( L[cx] < L[cy] ) swap( cx, cy );
					lg = (int)log2( L[cx] );
					for ( i = lg; i >= 0; i-- )
						if ( L[cx] - (1 << i) >= top && LCA[cx][i] )
							cx = LCA[cx][i];
					printf( "%d\n", cx );
				 }
				 else {
					cx = L[x] - L[lc] + 1;       // is ok after 30m
					if ( cx <= k ) {
						top = L[lc] + ( k - cx );
						lg = (int)log2( L[y] );
						for ( i = lg; i >= 0; i-- )
							if ( L[y] - (1 << i) >= top && LCA[y][i] )
								y = LCA[y][i];
						printf( "%d\n", y );
					}
					else {
						top = L[x] - k + 1;
						lg = (int)log2( L[x] );
						for ( i = lg; i >= 0; i-- )
							if ( L[x] - (1 << i) >= top && LCA[x][i] )
								x = LCA[x][i];
						printf( "%d\n", x );
					}
                 }
              }
              if ( c == 3 ) break;
        }
        printf( "\n" );
	}
	
	fflush( stdout );
	return 0;
}
