/*
 Reinier César Mujica
 24 - 3 - 2009
 FIFTY YEARS IS TO MUCH
*/

#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int
    MAXN = 100001,
    MAXL = 17;

typedef pair < int, int > par;

struct edge {
    int dest, cost, next;
    edge( int a = 0, int b = 0, int c = 0 ) {
        dest = a; cost = b; next = c;
    }
} ls[MAXN * 2];

int N, Q, max_level;
int i, j, k;
int x, y, lg;
int LCA[MAXN][MAXL];
int min_q[MAXN][MAXL];
int max_q[MAXN][MAXL];
int L[MAXN], P[MAXN];
queue < int > S;

int main() {
    
    freopen( "lubenica.in", "r", stdin );
    freopen( "lubenica.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i < N; i++ ) {
        scanf( "%d %d %d", &x, &y, &k );
        ls[i] = edge( y, k, P[x] );
        P[x] = i;
        ls[i + N] = edge( x, k, P[y] );
        P[y] = i + N;
    }
    
    /* Bfs */
    for ( S.push( 1 ), L[1] = 1; !S.empty(); S.pop() ) {
        int node = S.front();
        max_level >?= L[node];
        for ( i = P[node]; i; i = ls[i].next ) {
            int next = ls[i].dest;
            int cost = ls[i].cost;
            if ( !L[next] ) {
                LCA[next][0] = node;
                min_q[next][0] = cost;
                max_q[next][0] = cost;
                L[next] = L[node] + 1;
                S.push( next );
            }
        }
    }

    /* initialization */
    for ( j = 1; 1 << j <= max_level; j++ )
        for ( i = 1; i <= N; i++ )
            LCA[i][j] = -1;
               
    /* computing LCA */
    for ( j = 1; 1 << j <= max_level; j++ ) {
        for ( i = 1; i <= N; i++ )
            if ( LCA[i][j - 1] != -1 ) {
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
                min_q[i][j] = min_q[LCA[i][j - 1]][j - 1] <?
                              min_q[i][j - 1];
                max_q[i][j] = max_q[LCA[i][j - 1]][j - 1] >?
                              max_q[i][j - 1];
            }
    }
    
    /* answer questions */
    scanf( "%d", &Q );
    while ( Q-- ) {
        int s1 = 1 << 30, s2 = 0;

        scanf( "%d %d", &x, &y );
        if ( L[x] < L[y] ) swap( x, y );

        lg = (int)log2( L[x] );
        for ( i = lg; i >= 0; i-- )
            if ( L[x] - ( 1 << i ) >= L[y] && LCA[x][i] != -1 ) {
                s1 <?= min_q[x][i];
                s2 >?= max_q[x][i];
                x = LCA[x][i];
            }

        if ( x != y ) {
            lg = (int)log2( L[x] );
            for ( i = lg; i >= 0; i-- )
                if ( LCA[x][i] != LCA[y][i] && LCA[x][i] != -1 ) {
                    s1 <?= ( min_q[x][i] <? min_q[y][i] );
                    s2 >?= ( max_q[x][i] >? max_q[y][i] );
                    x = LCA[x][i]; y = LCA[y][i];
                }
            s1 <?= ( min_q[x][0] <? min_q[y][0] );
            s2 >?= ( max_q[x][0] >? max_q[y][0] ); 
        }
        
        printf( "%d %d\n", s1, s2 );
    }
    
    fflush( stdout );
    return 0;
}
