#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
    MAXN = 5050;
    
int N, M, a, b, sol, i, j, R[MAXN];
bool mk[MAXN], empate;

vector < int > G[MAXN], L;

int dfs( int v ) {
    mk[v] = true;
    for ( int i = 0; i < G[v].size(); i++ ) {
        int next = G[v][i];
        if ( !mk[next] ) dfs( next );
    }
    L.push_back( v );
}

int main() {

    freopen( "journal.in", "r", stdin );
    freopen( "journal.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    
    for ( i = 0; i < M; i++ ) {
     scanf( "%d %d", &a, &b );
     G[a].push_back( b );
    }

    for ( i = 1; i <= N; i++ )
     if ( !mk[i] ) dfs( i );

    for ( i = L.size() - 1; i >= 0; i-- ) {
     printf( "%d\n", L[i] );
     for ( j = 0; j < G[L[i]].size(); j++ )
      R[G[L[i]][j]] >?= R[L[i]] + 1;
    }

    if ( R[L[0]] != N  - 1 ) empate = true;
    
    printf( "%d\n", empate );
    
    fflush( stdout );
    return 0;
}
