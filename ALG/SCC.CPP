/*
 Reinier César Mujica
 21/4/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int
    MAXN = 100005;
    
int N, M, act, sol, low[MAXN], dfsnum[MAXN];
bool del[MAXN];

vector < int > G[MAXN];
stack < int > S;

int dfs( int node ) {
    S.push( node );
    
    low[node] = dfsnum[node] = ++act;

    for ( int i = 0; i < G[node].size(); i++ ) {
     int next = G[node][i];
     if ( !low[next] ) {
        dfs( next );
        low[node] <?= low[next];
     }
     else
      if ( !del[next] )
       low[node] <?= low[next];
    }
    
    if ( low[node] == dfsnum[node] ) { //is root of comp
      printf( "%d : ", ++sol );
      while ( !del[node] ) {
       printf( "%d ", S.top() );
       del[S.top()] = true;
       S.pop();
      }
      printf( "\n" );
    }
}

int main() {
    int i, x, y;
    
    freopen( "SCC.in", "r", stdin );
    freopen( "SCC.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    
    for ( i = 0; i < M; i++ ) {
      scanf( "%d %d", &x, &y );
      G[x].push_back( y );
    }

    for ( i = 1; i <= N; i++ )
     if ( !dfsnum[i] ) dfs(i);

    fflush(  stdout );
    return 0;
}
