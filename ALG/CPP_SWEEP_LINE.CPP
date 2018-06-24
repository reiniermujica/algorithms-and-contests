/*
 Reinier César Mujica
 24 - 3 - 2009
 Closest pair of points
 Sweep Line  O(N * lg(N))
*/

#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

#define sqr( x ) ( x ) * ( x )

using namespace std;

struct point { 
    double x, y; 
    point ( double a = 0, double b = 0 ) {
        x = a; y = b;
    }
};

struct cmp_x {
       bool operator ()( const point &a, const point &b ) {
            return a.x < b.x;
       }
};

struct cmp_y {
       bool operator ()( const point &a, const point &b ) {
            return a.y < b.y;
       }
};

int N, last, i;
double cx, cy, sol = 1e10; // 10000000000
vector < point > ls;
multiset < point, cmp_y > S;
multiset < point, cmp_y > :: iterator lo, hi;

double dist( point a, point b ) {
       return sqrt( sqr( a.x - b.x ) + sqr( a.y - b.y ) );
}

int main() {

    freopen( "cpp.in", "r", stdin );
    freopen( "cpp.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%lf %lf", &cx, &cy );
        ls.push_back( point( cx, cy ) );
    }
    
    sort( ls.begin(), ls.end(), cmp_x() );
    
    /* sweep point by X */
    for ( i = 0; i < N; i++ ) {
        while ( last < i && ls[i].x - ls[last].x >= sol ) {
            S.erase( S.find( ls[last] ) );
            last++;
        }
    
        lo = S.lower_bound( point( ls[i].x, ls[i].y - sol ) );
        hi = S.upper_bound( point( ls[i].x, ls[i].y + sol ) );
        
        for ( ; lo != hi; lo++ )
            sol <?= dist( ls[i], *lo );

        S.insert( ls[i] );
    }
    
    printf( "%.3lf\n", sol );
    return 0;
}