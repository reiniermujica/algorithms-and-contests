/*
 Reinier César Mujica
 xx/08/2008
 "Lying Livestock"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 102;

struct edge {
    int u, v, cow;
} T[MAXN * MAXN];

int N, M, sol;
int i, j;
int mark[MAXN];
bool path[MAXN][MAXN], cycle;

void dfs( int x ) {
     mark[x] = 1;
     int i;
     for ( i = 1; i <= N; i++ ) {
        if ( path[x][i] ) {
         if ( mark[i] == 1 ) cycle = true;
         if ( !mark[i] ) dfs( i );
        }
     }
     mark[x] = 2;
}

int main() {

    freopen( "liecow.in", "r", stdin );
    freopen( "liecow.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    FOR( i, 1, M )
      scanf( "%d %d %d", &T[i].cow, &T[i].u, &T[i].v );

    FOR( i, 1, N ) {
     memset( path, 0, sizeof path );
     memset( mark, 0, sizeof mark );
     
     FOR( j, 1, M ) {
        if ( T[j].cow == i )
          path[T[j].v][T[j].u] = true;
        else
          path[T[j].u][T[j].v] = true;
     }

     cycle = false;
     FOR( j, 1, N )
      if ( !mark[j] ) dfs( j );

     sol += ( !cycle );
    }
      
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
