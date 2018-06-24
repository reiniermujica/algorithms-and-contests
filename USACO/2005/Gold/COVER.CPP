/*
 Reinier César Mujica
 25 - 3 - 2009
 Bipartite Matching
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 55,
    MAXM = 1250;
    
int N, M, flow;
int H, V;
int i, j;
int cap[MAXM][MAXM];
int T_H[MAXN][MAXN];
int T_V[MAXN][MAXN];
int last[MAXM];
bool mark[MAXM];
char cad[MAXN][MAXN];

bool augment( int node ) {
     if ( mark[node] ) return false;
     
     mark[node] = true;
     for ( int i = 1; i <= V; i++ ) {
        if ( cap[node][i] && ( !last[i] || augment( last[i] ) ) ) {
            last[i] = node;
            return true;
        }
     }
     
     return false;
}

int main() {

    freopen( "cover.in", "r", stdin );
    freopen( "cover.out", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    for ( i = 1; i <= N; i++ )
        gets( cad[i] + 1 );

    /* build graph */
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            if ( cad[i][j] != '*' ) continue;
            if ( cad[i][j - 1] == '*' )
                T_H[i][j] = T_H[i][j - 1];
            else
                T_H[i][j] = ++H;
        }
    }

    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            if ( cad[i][j] != '*' ) continue;
            if ( cad[i - 1][j] == '*' )
                T_V[i][j] = T_V[i - 1][j];
            else
                T_V[i][j] = ++V;
            cap[T_H[i][j]][T_V[i][j]] = 1;
        }
    }

    /* Bipartite matching */
    for ( i = 1; i <= H; i++ ) {
        fill( mark, mark + MAXM, false );
        if ( augment( i ) ) flow++;
    }
    
    printf( "%d\n", flow );
    return 0;
}
