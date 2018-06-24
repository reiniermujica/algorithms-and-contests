/*
 Reinier Cesar Mujica
 03/07/2008
 "Out of Hay"
 Kruscal whit Disjoint_Set Data Structure
 E * lg(E) + E * ackerman
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 2002,
    MAXM = 10002;

struct EDGE {
    int x, y, cost;
    EDGE( int cx = 0, int cy = 0, int cz = 0 ) {
        x = cx; y = cy; cost = cz;
    }
    bool operator < ( const EDGE &other ) const {
        return cost < other.cost;
    }
} T[MAXM];

int N, M, sol;
int i, j, k, c;
int P[MAXN], rank[MAXN];

int create_set( int x ) {
    P[x] = x;
    rank[x] = 0;
}

int find_set( int x ) {
    if ( x != P[x] ) P[x] = find_set( P[x] );
    return P[x];
}

int merge_set( int x, int y ) {

    int Px = find_set( x );
    int Py = find_set( y );

    if ( rank[x] > rank[y] ) P[Py] = Px;
    else P[Px] = Py;
    
    if ( rank[Px] == rank[Py] ) rank[Px]++;
}

int main() {

    freopen( "outofhay.in", "r", stdin );
    freopen( "outofhay.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    
    FOR( i, 0, M - 1 ) {
      scanf( "%d %d %d", &j, &k, &c );
      T[i] = EDGE( j, k, c );
    }

    sort( T, T + M );
    
    FOR( i, 1, N ) create_set( i );
    
    FOR( i, 0, M - 1 ) {
      j = T[i].x; k = T[i].y;
      if ( find_set( j ) != find_set( k ) ) {
       merge_set( j, k );
       sol >?= T[i].cost;
      }
    }

    printf( "%d\n", sol );
     
    fflush( stdout );
    return 0;
}
