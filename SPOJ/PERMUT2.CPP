/*
 Reinier César Mujica
 04/07/2008
 "Ambiguous Permutations"
*/

#include <cstdio>

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 100002;

int N, i, cases;
int T[MAXN];
bool ok;

int main() {

    scanf( "%d", &N );

    while ( N ) {
      FOR( i, 1, N )
       scanf( "%d", &T[i] );
      ok = true;
      FOR( i, 1, N ) {
        if ( T[T[i]] != i ) {
          ok = false;
          break;
        }
      }
      if ( ok ) printf( "ambiguous\n" );
      else printf( "not ambiguous\n" );
      scanf( "%d", &N );
    }
    
    fflush( stdout );
    return 0;
}
