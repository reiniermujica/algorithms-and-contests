/*
 Reinier Cesar Mujica
 10/06/2008
 "Puentes"
*/

#include <iostream>

using namespace std;

const int
    MAXV = 1002,
    MAXE = 10002;

struct edge {
    int u, next;
};

int N, M, sol, dc_time;
int i, j, k;
int dfsnum[MAXV], low[MAXV], last[MAXV];
edge E[2 * MAXE];

int pos( int x ) {
    return ( x > M ) ? x - M : x + M;
}

int dfs( int v ) {
    dfsnum[v] = low[v] = ++dc_time;
    int link = last[v];
    while ( link ) {
      int next = E[link].u;
      if ( next )
      if ( !dfsnum[next] ) {
        int p = pos( link );
        int save = E[p].u;
        E[p].u = 0;
        dfs( next );
        if ( low[next] == dfsnum[next]  ) { // is a bridge
           printf( "%d %d\n", v, next );
        }
        low[v] <?= low[next];
        E[p].u = save;
      }
      else
       low[v] <?= low[next];
      link = E[link].next;
    }
}

int main() {

    freopen( "d.in", "r", stdin );
    freopen( "d.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    
    for ( i = 1; i <= M; i++ ) {
      scanf( "%d %d", &j, &k );
      E[i] = ( (edge) { k, last[j] } );
      last[j] = i;
      E[i + M] = ( (edge) { j, last[k] } );
      last[k] = i + M;
    }
    
    for ( i = 1; i <= N; i++ )
      if ( !dfsnum[i] ) dfs( i );

    fflush( stdout );
    return 0;
}
