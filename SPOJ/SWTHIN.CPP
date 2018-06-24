/*
 Reinier César Mujica
 4/5/08
 SPOJ #1709 Swamp Things
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 1050;
    
struct point {
    int x, y;
};

bool cmp( const point &a, const point &b ) {
     if ( a.x != b.x ) return a.x < b.x;
     return a.y < b.y;
};

int mcd( int n1, int n2 ) {
    if ( n2 == 0 ) return n1;
    return mcd( n2, n1 % n2 );
}

int N, sol, cont, i, j, k, x, y, best, cases;
point T[MAXN], L[MAXN];

int main() {

    while ( 1 ) {

     cases++;
     
     N = 0;
     scanf( "%d", &N );
     if ( N == 0 ) break;

     for ( i = 1; i <= N; i++ )
      scanf( "%d %d", &T[i].x, &T[i].y );

     sol = 0;
     
     for ( i = 1; i <= N; i++ ) {

       cont = 0;
       for ( j = 1; j <= N; j++ ) {
         if ( i == j ) continue;
         x = T[i].x - T[j].x;
         y = T[i].y - T[j].y;
         k = mcd( abs( x ), abs( y ) );
         if ( k ) {
           x /= k;
           y /= k;
         }

         cont++;
         L[cont].x = x;
         L[cont].y = y;
       }

       sort( L + 1, L + cont + 1, cmp );

       best = 1;
       for ( j = 2; j <= cont; j++ ) {
         if ( L[j].x == L[j-1].x &&
              L[j].y == L[j-1].y )
             best++;
         else {
          sol >?= best + 1;
          best = 1;
         }
       }
       
       sol >?= best + 1;
       
     }
     
     if ( sol < 4 ) sol = 0;
     printf( "Photo %d: %d points eliminated\n", cases, sol );
     
    }

    fflush( stdout );
    return 0;
}
