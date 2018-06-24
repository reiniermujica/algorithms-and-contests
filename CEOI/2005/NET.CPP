/*
 Reinier César Mujica
 3/08/2008
 "Net"
 Bridges ( V + E )
*/

#include <cstdio>
#include <vector>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 100002;

struct EDGE {
    int x, y, next;
    EDGE( int a = 0, int b = 0, int c = 0 ) {
        x = a; y = b; next = c;
    }
} ls[2 * MAXN];

int N, M, Ca, Cb, dc_time;
int i, j, k, last[2 * MAXN];
int dfsnum[MAXN], low[MAXN];
bool mA[MAXN], mB[MAXN];
vector < EDGE > S;

int op( int x ) {
    return ( x > M ) ? x - M : x + M;
}

int dfs( int x, int &a, int &b ) {
    dfsnum[x] = low[x] = ++dc_time;
    
    int cA = mA[x], cB = mB[x], j, k, s;
    for ( int i = last[x]; i; i = ls[i].next ) {
        int next = ls[i].y;
        if ( next == -1 ) continue;
        
        if ( !dfsnum[next] ) {
          ls[s = op( i )].y = -1; // delete
          dfs( next, j, k );
          low[x] <?= low[next];
          ls[s].y = x;           // restore
          cA += j; cB += k;
          
          if ( dfsnum[next] == low[next] )
            if ( !j || j == Ca || !k || k == Cb )
             S.push_back( EDGE( x, next, 0 ) );
        }
        else
          low[x] <?= low[next];
    }
    a = cA; b = cB;
}

int main() {

    freopen( "net.in", "r", stdin );
    freopen( "net.out", "w", stdout );

    scanf( "%d %d %d %d", &N, &M, &Ca, &Cb );
    FOR( i, 1, Ca ) {
      scanf( "%d", &j );
      mA[j] = true;
    }
    FOR( i, 1, Cb ) {
      scanf( "%d", &j );
      mB[j] = true;
    }

    FOR( i, 1, M ) {
      scanf( "%d %d", &j, &k );
      ls[i] = EDGE( j, k, last[j] );
      last[j] = i;
      ls[i + M] = EDGE( k, j, last[k] );
      last[k] = i + M;
    }
    
    dfs( 1, j, k );
    
    printf( "%d\n", j = S.size() );
    FOR( i, 0, j - 1 )
     printf( "%d %d\n", S[i].x, S[i].y );

    fflush( stdout );
    return 0;
}
