/*
 Reinier César Mujica
 xx/08/2008
 "Mobiles"
 ABI
*/

#include <cstdio>

const int
    MAXN = 1030;

int N, act;
int i, j, k;
int x, y, c;
int S[MAXN][MAXN];

int lbit( int x ) {
    return x & -x;
}

int add( int x, int y, int c ) {
    for ( int i = x; i <= N; i += lbit( i ) )
     for ( int j = y; j <= N; j += lbit( j ) )
      S[i][j] += c;
}

int suma( int x, int y ) {
    int res = 0;
    for ( int i = x; i; i -= lbit( i ) )
     for ( int j = y; j; j -= lbit( j ) )
        res += S[i][j];
    return res;
}

int sum( int x, int y, int cx, int cy ) {
    return suma( cx, cy ) - suma( x - 1, cy ) -
           suma( cx, y - 1 ) + suma( x - 1, y - 1 );
}

int main() {

    freopen( "mobiles.in", "r", stdin );
    freopen( "mobiles.out", "w", stdout );
    
    while ( scanf( "%d", &act ) && act != 3 ) {

       if ( !act ) scanf( "%d", &N );
       if ( act == 1 ) {
          scanf( "%d %d %d", &x, &y, &c );
          x++; y++;
          add( x, y, c );
       }
       if ( act == 2 ) {
          scanf( "%d %d %d %d", &x, &y, &c, &k );
          x++; y++; c++; k++;
          printf( "%d\n", sum( x, y, c, k ) );
       }
       
    }
    
    fflush( stdout );
    return 0;
}
