/*
 Reinier César Mujica
 23 - 3 - 2009
 Longest path in a tree.
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXN = 10005,
    oo = 1 << 30;
    
int N, sol;
int i, j, k;
int dist[MAXN];
vector < int > G[MAXN];

void dfs( int node ) { 
     for ( int i = 0; i < G[node].size(); i++ ) {
        int next = G[node][i];
        if ( dist[next] == 0 ) {
            dist[next] = dist[node] + 1;
            dfs( next );
        }
     }
}

int main() {

    scanf( "%d", &N );
    for ( i = 1; i < N; i++ ) {
        scanf( "%d %d", &j, &k );
        G[j].push_back( k );
        G[k].push_back( j );
    }
    
    dfs( 1 );
    for ( i = 1; i <= N; i++ )
        if ( dist[i] > sol ) {
            sol = dist[i];
            j = i;
        }
    
    memset( dist, 0, sizeof dist );
    dfs( j ); sol = 0;
    for ( i = 1; i <= N; i++ )
        sol >?= dist[i];
        
    printf( "%d\n", sol );
    return 0;
}
