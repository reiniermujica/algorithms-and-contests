/*
 Reinier César Mujica
 22/4/08 PSN - 2008
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
    N = 10,
    LIMITE = 1<<13; // for the range 1..1000
    
int T[N], i;

int getdig( int x ) {
    int s = 1;
    if ( x == 0 ) return 0;
    while ( x > 0 ) {
        s *= x % 10;
        x /= 10;
    }
    return s;
}

int main() {

    freopen( "numb.in", "r", stdin );
    freopen( "numb.out", "w", stdout );

    for ( i = 0; i < N; i++ )
     scanf( "%d", &T[i] );

    for ( i = 0; i < 10; i++ ) {
     queue < int > Q;
     bool ok = false;
     int lim = 0;
     Q.push( T[i] );
     while ( !Q.empty() ) {
        lim++;
        int act = Q.front();
        Q.pop();
        int dig = getdig( act );
        int d1 = act - dig;
        int d2 = act + dig;
        if ( d1 == T[i] || d2 == T[i] ) {
            ok = true;
            break;
        }
        if ( lim >= LIMITE ) break;
        Q.push( d1 ); Q.push( d2 );
      }
     printf( "%d", ok );
    }

    printf( "\n" );

    return 0;
}
