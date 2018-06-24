/*
 Reinier César Mujica
 30/05/08
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int
    MAXN = 55;

int N, i, j;
char cad[MAXN], best[MAXN], tmp[MAXN];

int cut( int x, int y ) {
    int lo, hi, i;

    lo = 1; hi = x;;
    while ( lo <= hi ) {
        tmp[lo] = cad[hi];
        tmp[hi] = cad[lo];
        lo++; hi--;
    }

    lo = x + 1; hi = y;
    while ( lo <= hi ) {
        tmp[lo] = cad[hi];
        tmp[hi] = cad[lo];
        lo++; hi--;
    }
    
    lo = y + 1; hi = N;
    while ( lo <= hi ) {
        tmp[lo] = cad[hi];
        tmp[hi] = cad[lo];
        lo++; hi--;
    }
}

int cmp() {
    for ( int i = 1; i <= N; i++ ) {
      if ( tmp[i] != best[i] ) {
        if ( tmp[i] < best[i] ) {
         for ( int j = 1; j <= N; j++ )
          best[j] = tmp[j];
          return 1;
        }
       return 1;
      }
    }
}

int main() {

    gets( cad + 1 );
    N = strlen( cad + 1 );
    for ( i = 1; i <= N; i++ ) best[i] = '{';

    for ( i = 1; i < N ; i++ )
     for ( j = i + 1; j < N; j++ ) {
      cut( i, j );
      cmp();
     }
    
    puts( best + 1 );
    
    fflush( stdout );
    return 0;
}
