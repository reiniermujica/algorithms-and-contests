/*
 Reinier Cesar Mujica
 11/06/2008
 "Relays"
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXN = 802;

typedef pair < int, int > par;

struct cow {
    int u, cost;
};

int N, M, K, sol;
int i, j, k, t;
int cant[MAXN];
vector < cow > G[MAXN];
priority_queue < par, vector< par >, greater< par > > Q;

int main() {

    freopen( "relay.in", "r", stdin );
    freopen( "relay.out", "w", stdout );

    scanf( "%d %d %d", &K, &N, &M );
    
    for ( i = 1; i <= M; i++ ) {
       scanf( "%d %d %d", &j, &k, &t );
       G[j].push_back( (cow) { k, t } );
       G[k].push_back( (cow) { j, t } );
    }
    
    Q.push( make_pair( 0, 1 ) );
    t = 0;
    
    while ( !Q.empty() ) {
      int node = Q.top().second;
      int cost = Q.top().first;
      Q.pop();

      if ( node == N ) {
        sol += cost;
        t++;
        if ( t == K ) break;
        continue;
      }
      cant[node]++;
      if ( cant[node] > K ) continue;
      
      for ( i = 0; i < G[node].size(); i++ ) {
        int next = G[node][i].u;
        int ncos = G[node][i].cost + cost;
        if ( cant[next] < K )
         Q.push( make_pair( ncos, next ) );
      }
    }
    
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
