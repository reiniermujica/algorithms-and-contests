#include <cstdio>
#include <queue>
#include <algorithm>

#define REP( i, k, N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    MAXN = 100005,
    oo = 1 << 29;

struct node {
    int left, right;
};

int N, M, i, left, right, k, x, y;
int D[MAXN];
node G[MAXN];
queue < int > Q;

int main() {

    freopen( "coldwat.in", "r", stdin );
    freopen( "coldwat.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );

    REP( i, 1, M ) {
      scanf( "%d %d %d", &x, &y, &k );
      G[x].left = y;
      G[x].right = k;
    }
    
    fill( D, D + MAXN, oo );
    D[1] = 1;

    Q.push( 1 );
    
    while ( !Q.empty() ) {
      x = Q.front();
      Q.pop();
      
      left = G[x].left;
      right = G[x].right;
      if ( left )
      if ( D[left] > D[x] + 1 ) {
        D[left] = D[x] + 1;
        Q.push( left );
      }
      if ( right )
      if ( D[right] > D[x] + 1 ) {
        D[right] = D[x] + 1;
        Q.push( right );
      }
    }

    REP( i, 1, N )
     printf( "%d\n", D[i] );
     
    fflush( stdout );
    return 0;
}
