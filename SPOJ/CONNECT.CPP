/*
 Reinier César Mujica
 11 - 11 - 2008
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int
	MAXN = 150,
	MAXK = 101;
	
typedef pair < int, int > par;

struct edge {
	int v, cost, next;
	edge( int a = 0, int b = 0, int c = 0 ) {
		v = a; cost = b; next = c;
	}
} ls[MAXN * MAXN];

int T, N, M, Q;
int i, j, k;
int x, y, l;
int last[MAXN], cant[MAXN];
vector < int > kth[MAXN][MAXN];

int kth_route( int x ) {
	int node, cost, ncost, next;

    priority_queue < par, vector < par >, greater < par > > Q;
    fill( cant, cant + MAXN, 0 );
    
	for ( Q.push( par( 0, x ) ); !Q.empty(); Q.pop() ) {
		node = Q.top().second;
		cost = Q.top().first;
		cant[node]++;
       
		kth[x][node].push_back( cost );
		if ( kth[x][node].size() > MAXK ) continue;
		
		for ( int i = last[node]; i; i = ls[i].next ) {
			next = ls[i].v;
			ncost = ls[i].cost + cost;
			if ( kth[x][next].size() > MAXK ) continue;
			Q.push( par( ncost, next ) );
		}
	}
}

int main() {

   	scanf( "%d", &T );
	while ( T-- ) {
		
        scanf( "%d %d", &N, &M );

        /* fill */
        fill( last, last + MAXN, 0 );
        for ( i = 0; i <= N; i++ )
         for ( j = 0; j <= N; j++ )
          kth[i][j].clear();
  
		for ( i = 1; i <= M; i++ ) {
			scanf( "%d %d %d", &x, &y, &l );
			ls[i] = edge( y, l, last[x] );
			last[x] = i;
		}
		
		for ( i = 1; i <= N; i++ )
         kth_route( i );

     	scanf( "%d",  &Q );
		while ( Q-- ) {
			scanf( "%d %d %d", &x, &y, &k );
            if ( x != y ) {
               k--;
               if ( kth[x][y].size() <= k ) printf( "-1\n" );
               else printf( "%d\n", kth[x][y][k] );
            }
            else
            if ( kth[x][y].size() <= k ) printf( "-1\n" );
            else printf( "%d\n", kth[x][y][k] );
		}
        printf( "\n" );
	}
	
	fflush( stdout );
	return 0;
}
