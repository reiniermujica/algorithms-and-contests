/*
 Reinier Cesar Mujica
 29/05/08
 Lis
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100005;

struct pok {
    int x, y, p;
};

struct cmp_Y {
    bool operator () ( const pok &a, const pok &b ) {
        return ( a.y != b.y ) ? a.y > b.y : a.x == b.x;
    }
};

bool cmp( const pok &a, const pok &b ) {
     return ( a.x != b.x ) ? a.x < b.x : a.y > b.y;
}

int N, i, j, k, last[MAXN];
pok T[MAXN], dp[MAXN];

void show( int x ) {
     if ( !x ) return;
     show( last[x] );
     printf( "%d %d\n", T[x].x, T[x].y );
}

int main() {

    freopen( "poklon.in", "r", stdin );
    freopen( "poklon.out", "w", stdout );

    scanf( "%d", &N );
    
    for ( i = 1; i <= N; i++ )
     scanf( "%d %d", &T[i].x, &T[i].y );

    sort( T + 1, T + N + 1, cmp );
    
    T[1].p = 1; dp[1] = T[1]; k = 1;
    
    for ( i = 2; i <= N; i++ ) {
      T[i].p = i;
      if ( ( T[i].x != dp[k].x && T[i].y <= dp[k].y )
         ||( T[i].x == dp[k].x && T[i].y < dp[k].y )) {
       dp[++k] = T[i];
       last[i] = dp[k - 1].p;
      }
      else {
        j = upper_bound( dp + 1, dp + k + 1, T[i], cmp_Y() ) - dp;
        dp[j] = T[i];
        last[T[i].p] = dp[j - 1].p;
      }
    }
    
    printf( "%d\n", k );
    
    show( dp[k].p );
    
    fflush( stdout );
    return 0;
}
