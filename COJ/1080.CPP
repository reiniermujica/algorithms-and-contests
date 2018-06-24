/*
 Reinier César Mujica
 28 - 4 - 2009
 Closest pair of points
 Sweep Line O(N * lg(N))
*/

#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

#define sqr( x ) ( x ) * ( x )
#define MAXN 10005

using namespace std;

typedef long long int64;

struct point { 
    double x, y;
    point ( double a = 0, double b = 0 ) {
        x = a; y = b;
    }
} ls[MAXN];

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

int N, T;
int i, last;
double cx, cy, sol;

double dist( point a, point b ) {
       return sqrt( sqr( a.x - b.x ) + sqr( a.y - b.y ) );
}

int main() {

    scanf( "%d", &T );
    while ( T != 0 ) {
    
        /* init */
        multiset < point, cmp_y > S;
        multiset < point, cmp_y > :: iterator lo, hi;
        sol = 1e10; // 10000000000
        last = 0;
        
        N = T;
        for ( i = 0; i < N; i++ ) {
            scanf( "%lf %lf", &cx, &cy );
            ls[i] = point( cx, cy );
        }

        sort( ls, ls + N, cmp_x() );

        /* Sweep Line */
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
	
	if ( sol < 10000 ) 
	        printf( "%.4lf\n", sol );
	else printf( "INFINITY\n" );
	
	scanf( "%d", &T );
    }

    fflush( stdout );
    return 0;
}
