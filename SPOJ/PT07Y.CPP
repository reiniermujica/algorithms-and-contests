/*
 Reinier César Mujica
 23 - 3 - 2009
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
    MAXN = 10005;
    
int N, M;
int i, j, k;
bool mark[MAXN], ok = true;
vector < int > G[MAXN];

void dfs( int node, int father ) {
     mark[node] = true;
     for ( int i = 0; i < G[node].size() && ok; i++ ) {
        int next = G[node][i];
        if ( next == father ) continue;
        if ( mark[next] ) ok = false;
        else dfs( next, node );
     }
}

int main() {

    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= M; i++ ) {
        scanf( "%d %d", &j, &k );
        G[j].push_back( k );
        G[k].push_back( j );
    }
    
    for ( i = 1; i <= N; i++ )
        if ( !mark[i] ) dfs( i, -1 );
    
    if ( ok ) printf( "YES\n" );
    else printf( "NO\n" );
    
    return 0;
}
