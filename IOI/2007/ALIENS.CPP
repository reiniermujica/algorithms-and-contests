/*
 Reinier César Mujica
 16/4/08 PSN - 2008
 Binary Search 
*/

#include <cstdio>
#include "aliens.h"

using namespace std;

typedef long long int64;

int N, m, x, y;
int64 sx, sy;     
                
bool check( int64 cx, int64 cy ) {
     if ( cx > 0 && cx <= N && cy > 0 && cy <= N )
       return ( examine( cx, cy ) );
     return 0;
}

int find_righ( int64 x, int64 y ) {
    int64 lo, hi, p = 1;
    while ( check( x + p, y ) )
     p *= 2;
    lo = p / 2; hi = p;
    while ( lo < hi ) {
     int mid = (lo + hi + 1) / 2;
     if ( check( x + mid, y ) )
      lo = mid;
     else
      hi = mid-1;
    } 
    return lo;
}

int find_left( int64 x, int64 y ) {
    int64 lo, hi, p = 1;
    while ( check( x - p, y ) )
     p *= 2;
    lo = p / 2; hi = p;
    while ( lo < hi ) {
     int mid = (lo + hi + 1) / 2;
     if ( check( x - mid, y ) )
      lo = mid;
     else
      hi = mid-1;
    } 
    return lo;
}

int find_down( int64 x, int64 y ) {
    int64 lo, hi, p = 1;
    while( check( x, y - p ) )
     p *= 2;
    lo = p / 2; hi = p;
    while ( lo < hi ) {
     int mid = (lo + hi + 1) / 2;
     if ( check( x, y - mid ) )
      lo = mid;
     else
      hi = mid-1;
    } 
    return lo;
}

int main() {
    init( N, x, y ); // init the library

    /* find borders  */
    int sr = find_righ( x, y );
    int sl = find_left( x, y );
    int sd = find_down( x, y );
    
    m = ( x + sr ) - ( x - sl ) + 1;
    
    x -= sl;
    y -= sd;
    // move to the leftmost
    while ( check( x - 2*m, y ) ) x -= 2*m; 
    //move to the most down
    while ( check( x, y - 2*m ) ) y -= 2*m;
    
    if ( check( x - m , y - m ) ) {
     x -= m;
     y -= m;   
    }

    x += (m * 2) + ( m / 2);
    y += (m * 2) + ( m / 2);

    solution(x, y );

    fflush( stdout );
    return 0;    
}
