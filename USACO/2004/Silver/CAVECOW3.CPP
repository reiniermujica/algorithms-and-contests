/*
 Reinier César Mujica
 xx/08/2008
 "Cave Cows 3"
 Is slow for tescase 8
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 50005,
    oo = 1 << 30;

typedef long long int64;

struct point {
       int64 x, y;
};

int64 N, top = 2, sol;
int64 i, j, k;
int64 S[MAXN];
point T[MAXN];

int64 dist( point a, point b ) {
    return abs( a.x - b.x ) +
           abs( a.y - b.y );
}

int64 cross( const point &x, const point &y, const point &c ) {
    return ( x.x - c.x ) * ( y.y - c.y ) -
           ( x.y - c.y ) * ( y.x - c.x );
}

bool cmp( const point &a, const point &b ) {
     return cross( a, b, T[0] ) > 0;
}

int main() {

    freopen( "cavecow3.in", "r", stdin );
    freopen( "cavecow3.out", "w", stdout );
    
    T[0].x = T[0].y = oo;
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%I64d %I64d", &T[i].x, &T[i].y );
        if ( T[0].x > T[i].x || ( T[0].x == T[i].x && T[0].y > T[i].y ) ) {
            T[0] = T[i];
            k = i;
        }
    }

    swap( T[k], T[N] ); N--;
    sort( T + 1, T + N + 1, cmp );
    for ( i = 0; i < 3; i++ ) S[i] = i;
    
    /* Convex Hull O(N) */
    for ( i = 3; i <= N; i++ ) {
      while ( cross( T[S[top]], T[S[top - 1]], T[i] ) > 0 ) top--;
      S[++top] = i;
    }

//    printf( "HULL SIZE = %d\n", top + 1) ;
    /* N ^ 2 */
    for ( i = 0; i < top; i++ )
     for ( j = i + 1; j <= top; j++ )
      sol >?= dist( T[S[i]], T[S[j]] );
    
    printf( "%I64d\n", sol );
    
    fflush( stdout );
    return 0;
}
