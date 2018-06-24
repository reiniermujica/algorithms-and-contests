/*
 PROG: pwalk
 LANG: C++
*/

#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 1052,
    MAXL = 18;

struct node {
    int id, cost;
};

int N, M, lg, sol;
int i, j, k, c, next, act;
int LCA[MAXN][MAXL], dist[MAXN][MAXL];
int L[MAXN];
char ch;

vector < node > G[MAXN];
queue < int > Q;

int main() {

    freopen( "pwalk.in", "r", stdin );
    freopen( "pwalk.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    for ( i = 1; i < N; i++ ) {
      scanf( "%d %d %d", &j, &k, &c );
      G[j].push_back( (node) { k, c } );
      G[k].push_back( (node) { j, c } );
    }
    
    Q.push( 1 ); L[1] = 1;
    while ( !Q.empty() ) {
     act = Q.front();
     Q.pop();
     
     sol = G[act].size();
     FOR( i, 0, sol - 1 ) {
        next = G[act][i].id;
        c = G[act][i].cost;
        if ( L[next] ) continue;
        Q.push( next );
        
        L[next] = L[act] + 1;
        LCA[next][0] = act;
        dist[next][0] = c;
        lg = (int)log2( L[next] );
        FOR( j, 1, lg )
          if ( LCA[next][j - 1] ) {
            LCA[next][j] = LCA[LCA[next][j - 1]][j - 1];
            dist[next][j] = dist[next][j - 1] +
                            dist[LCA[next][j - 1]][j - 1];
          }
     }
    }
    
    FOR( c, 1, M ) {
      scanf( "%d %d", &j, &k );
      if ( L[j] < L[k] ) swap( j, k );
      sol = 0;
      lg = (int)log2( L[j] );
      
      for ( i = lg; i >= 0; i-- )
       if ( L[j] - (1 << i) >= L[k] && LCA[j][i] ) {
        sol += dist[j][i];
        j = LCA[j][i];
       }

      if ( j != k ) {
        lg = (int)log2( L[j] );
        for ( i = lg; i >= 0; i-- )
          if ( LCA[j][i] && LCA[j][i] != LCA[k][i] ) {
            sol += dist[j][i] + dist[k][i];
            j = LCA[j][i]; k = LCA[k][i];
          }
        sol += dist[j][0] + dist[k][0];
      }
      
      printf( "%d\n", sol );
    }
    
    fflush( stdout );
    return 0;
}
