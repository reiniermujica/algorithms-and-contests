/*

*/

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int
    MAXN = 5005;
    
int N, M, P, sol;
int i, j, k;
int a, b, c;
bool mark[MAXN];
vector < int > path;
vector < int > G[MAXN];

void palamierda() {
     printf( "%d\n", sol );
     for ( int i = 0; i < path.size(); i++ )
        printf( "%d\n", path[i] );
     exit( 0 );
}

int dfs( int x, int dist ) {
    path.push_back( x );
    mark[x] = true;
    if ( x == P ) {
        sol = dist;
        palamierda();
    }
    
    for ( int i = 0; i < G[x].size(); i++ ) {
        int next = G[x][i];
        if ( !mark[next] ) {
            dfs( next, dist + 1 );
        }
    }
    path.pop_back();
}

int main() {

    freopen( "tcave.in", "r", stdin );
    freopen( "tcave.out", "w", stdout );
    
    scanf( "%d %d %d", &N, &M, &P );
    for ( i = 0; i < M; i++ ) {
        scanf( "%d %d %d", &a, &b, &c );
        G[a].push_back( b );
        G[a].push_back( c );
    }

    dfs( 1, 1 );

    return 0;
}
