/*
 Reinier Cesar Mujica
 4/06/08
 "Fish" IOI 2008 Day 0
*/

#include <cstdio>

using namespace std;

typedef long long int64;

const int
    MAXN = 100002;

struct town {
    int64 dist, fish;
};

int64 N, sol, i, j;
int64 lo, hi, mid;
town T[MAXN];

int dist( int x, int y ) {
    return T[x].dist - T[y].dist;
}

int isok( int64 x ) {
    int64 res = T[1].fish - x;

    for ( i = 2; i <= N; i++ ) {
      j = T[i].dist - T[i - 1].dist;
      if ( res > 0 && res - j <= 0 )
       res = 0;
      else
       res -= j;
      res += T[i].fish - x;
    }
    return res >= 0;
}

int main() {

    freopen( "fish.in", "r", stdin );
    freopen( "fish.out", "w", stdout );

    scanf( "%d", &N );
    
    for ( i = 1; i <= N; i++ ) {
     scanf( "%lld %lld", &T[i].dist, &T[i].fish );
     hi >?= T[i].fish;
    }
     
    lo = 1;
    while ( lo < hi ) {
      mid = ( lo + hi + 1 ) / 2;
      if ( isok( mid ) ) lo = mid;
      else hi = mid - 1;
    }
    
    printf( "%lld\n", lo );

    fflush( stdout );
    return 0;
}
