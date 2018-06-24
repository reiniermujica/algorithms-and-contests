/*
 Reinier Cesar Mujica
 17/06/2008
 "Ruleta"
*/

#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

#define REP( i, j, k ) \
    for ( i = (j); i <= (k); i++ )

int N;
int i, j, k;
int P1, P2;

deque < int > p1, p2;

void reset( deque < int > &a ) {
     a.clear();
     int i;
     REP( i, 1, 4 )
      a.push_back( i );
}

void update( deque < int > &a, int &b ) {
     if ( a.size() == 1 ) { // reset
       b -= a.front();
       reset( a );
     }
     else {
       b -= a.front() + a.back();
       a.pop_front();
       a.pop_back();
       if ( a.empty() ) reset( a );
     }
}

void update2( deque < int > &a, int &b ) {
     if ( a.size() == 1 ) {
      b += a.front();
      a.push_back( a.front() );
     }
     else {
      b += a.front() + a.back();
      a.push_back( a.front() + a.back() );
     }
     if ( a.front() + a.back() > 100 ) reset( a );
}

int main() {

    freopen( "RULETA.DAT", "r", stdin );
    freopen( "RULETA.SOl", "w", stdout );

    scanf( "%d", &N );
    reset( p1 ); reset( p2 );
    
    REP( i, 1, N ) {
      scanf( "%d", &k );
      if ( !k ) {
       update( p1, P1 );
       update( p2, P2 );
      }
      else
      if ( k % 2 == 0 ) {
        update2( p1, P1 );
        update( p2, P2 );
      }
      else {
       update2( p2, P2 );
       update( p1, P1 );
      }
    }
    
    printf( "%d %d\n", P1, P2 );
    
    fflush( stdout );
    return 0;
}
