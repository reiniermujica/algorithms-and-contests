/*
 Reinier Cesar Mujica
 2/06/08
 "Béisbol en Königsberg"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, j, k ) \
    for ( i = j; i <= k; i++ )

const int
	MAXN = 10002;

int T, N, M, dp[MAXN], x, y, i;
bool ok;

int main() {

    freopen( "a.in", "r", stdin );
    freopen( "a.out", "w", stdout );

    scanf( "%d", &T );
    while ( T-- ) {
      scanf( "%d %d", &N, &M );
      
      fill( dp, dp + MAXN, 0 );
      REP( i, 1, M ) {
        scanf( "%d %d", &x, &y );
        dp[x]++; dp[y]++;
      }

      ok = true;
      REP( i, 1, N )
       if ( dp[i] % 2 == 1 ) {
         ok = false;
         break;
       }
       
      printf( "%d\n", ok );
    }
    
    fflush( stdout );
    return 0;
}
