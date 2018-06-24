/*
 Reinier César Mujica
 6 - 5 - 2008
 "Horizonte de la Ciudad"
 Sweep Line O(N * lg(N))
*/

#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

typedef long long int64;

const int
    MAXN = 40005;
    
struct event {
    int64 start, heigh, value;
    event( int64 a = 0, int64 b = 0, int64 c = 0 ) {
        start = a; heigh = b; value = c;
    }
    bool operator < ( const event &other ) const {
        if ( start != other.start ) return start < other.start;
        return value < other.value;
    }
} ls[MAXN * 2];

int N, E;
int i, x, y, k;
int64 last, sol;
multiset < int, greater < int > > S;

int main() {

    freopen( "horizon.in", "r", stdin );
    freopen( "horizon.out", "w", stdout );

    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d %d %d", &x, &y, &k );
      ls[i] = event( x, k, 0 );
      ls[i + N] = event( y, k, 1 );
    }
    
    E = 2 * N;
    sort( ls + 1, ls + E + 1 );

    /* Sweep Line */
    last = 0; S.insert( 0 );
    for ( i = 1; i <= E; i++ ) {
        sol += ( ls[i].start - last ) * ( *S.begin() );
        last = ls[i].start;
        if ( ls[i].value )
            S.erase( S.find( ls[i].heigh ) );
        else
            S.insert( ls[i].heigh );
    }
    
    printf( "%lld\n", sol );
    return 0;
}
