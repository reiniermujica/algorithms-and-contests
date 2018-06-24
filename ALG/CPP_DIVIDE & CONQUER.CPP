/*
 Reinier César Mujica
 21/08/2008
 "Closest Pair of Points"
 O(n log n)
 Update 24 - 3 - 2009
    -Change to double
    -Tested whit large cases
*/

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define sqr( x ) ( x ) * ( x )

struct point {
    double x, y;
    point ( double a = 0, double b = 0 ) {
        x = a; y = b;
    }
    bool operator < ( const point &other ) const {
        if ( x != other.x ) return x < other.x;
        return y < other.y;
    }
};

int N;
int i, j, k;
double cx, cy, min_dist = 1e10; // a one whit 10 left zeros
vector < point > ls;

double dist( point a, point b ) {
       return sqrt( sqr( a.x - b.x ) + sqr( a.y - b.y ) );
}

void find_closest( int lo, int hi ) {
     if ( lo >= hi ) return ;
     
     int mid = ( lo + hi ) / 2;
     find_closest( lo, mid );
     find_closest( mid + 1, hi );

     while ( ls[mid].x - ls[lo].x >= min_dist ) lo++;
     while ( ls[hi].x - ls[mid].x >= min_dist ) hi--;
     
     for ( int i = lo; i < hi; i++ )
      for ( int j = i + 1; j <= hi; j++ )
       min_dist <?= dist( ls[i], ls[j] );
}

int main() {

    freopen( "cpp.in", "r", stdin );
    freopen( "cpp.out", "w", stdout );

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      scanf( "%lf %lf", &cx, &cy );
      ls.push_back( point( cx, cy ) );
    }
    
    sort( ls.begin(), ls.end() );
    find_closest( 0, N - 1 );
 
    printf( "%.3lf\n", min_dist );
    return 0;
}
