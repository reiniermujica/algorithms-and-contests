/*
 Reinier César Mujica
 19/05/08 
 SPOJ #178 Road Net
*/

#include <cstdio>

#define REP( i, k, N ) \
    for ( i = k; i <= N; i++ )

const int
    MAXN = 201;
    
int N, i, j, k, cases, T[MAXN][MAXN];
bool ok;

int main() {

    scanf( "%d", &cases );

    while ( cases-- ) {

     scanf( "%d", &N );
     
     REP( i, 1, N )
      REP( j, 1, N )
       scanf( "%d", &T[i][j] );

     REP( i, 1, N )
      REP( j, i+1, N )
       if ( i != j ) {
        ok = true;
        REP( k, 1, N ) {
         if ( k != i && k != j )
          if ( T[i][j] == ( T[i][k] + T[k][j] ) ) {
           ok = false;
           break;
          }
        }
        if ( ok ) printf( "%d %d\n", i, j );
       }
    }

    fflush( stdout );
    return 0;
}
