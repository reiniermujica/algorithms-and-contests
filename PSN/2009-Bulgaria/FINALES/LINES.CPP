/*
 Reinier César Mujica
 21 - 4 - 2009
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct lines {
    int xy, lo, hi;
    lines( int a = 0, int b = 0, int c = 0 ) {
        xy = a; lo = b; hi = c;
    }
    bool operator < ( const lines &other ) const {
        if ( xy != other.xy ) return xy < other.xy;
        if ( lo != other.lo ) return lo < other.lo;
        return hi < other.hi;
    }
};

int N, sol;
int i, j, k;
int x1, x2, y1, y2;
vector < lines > H, V;
vector < lines > _H, _V;

int main() {
    
    scanf( "%d\n", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
        if ( x1 > x2 ) swap( x1, x2 );
        if ( y1 > y2 ) swap( y1, y2 );
        if ( x1 == x2 ) 
            V.push_back( lines( x1, y1, y2 ) );
        else
            H.push_back( lines( y1, x1, x2 ) );
    }
    
    sort( H.begin(), H.end() );
    sort( V.begin(), V.end() );
    
    /* deleting fucking horizontal lines */
    for ( i = 0; i < H.size(); i++ ) {
        if ( _H.size() && _H.back().xy == H[i].xy
          && _H.back().hi >= H[i].lo )
            _H.back().hi >?= H[i].hi;          
        else
            _H.push_back( H[i] );
    }

    /* deleting fucking vertical lines */
    for ( i = 0; i < V.size(); i++ ) {
        if ( _V.size() && _V.back().xy == V[i].xy 
          && _V.back().hi >= V[i].lo )
            _V.back().hi >?= V[i].hi;          
        else
            _V.push_back( V[i] );
    }
    
    H.swap( _H );
    V.swap( _V );

    for ( i = 0; i < H.size(); i++ ) {
        for ( j = i + 1; j < H.size(); j++ ) {
            if ( H[i].xy == H[j].xy ) continue;
            if ( H[i].hi <= H[j].lo ) continue;
            if ( H[j].hi <= H[i].lo ) continue;
            
            int cant = 0;
            for ( k = 0; k < V.size(); k++ ) {
               int left = max( H[i].lo, H[j].lo );
               int right = min( H[i].hi, H[j].hi );
               if ( V[k].xy < left || V[k].xy > right ) continue;
               if ( V[k].hi < H[j].xy || V[k].lo > H[i].xy ) continue;
               cant++;
            }
            sol += ( cant * ( cant - 1 ) ) / 2;
        }
    }
    
    printf( "%d\n", sol );
    return 0;
}
