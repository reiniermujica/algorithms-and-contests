/*
 Reinier César Mujica
 23 - 6 - 2009
 dp + binary search
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define IO freopen

const int
    MAXN = 65000;
    
int T, N, M, Q, P, sol;
int i, k, s;
int lo, hi, mid;
int ls1[MAXN], ls2[MAXN];
int dp[MAXN];
int pos[MAXN];

int main() {
    
    IO( "prince.in", "r", stdin );
    IO( "prince.out", "w", stdout );
    
    for ( scanf( "%d", &T ); T; T-- ) {

        /* initialize */
        memset( pos, 0, sizeof pos );
        memset( dp, 63, sizeof dp );        
        sol = M = dp[0] = 0;
        
        /* read */
        scanf( "%d %d %d", &N, &Q, &P );
        Q++; P++;
        for ( i = 1; i <= Q; i++ )
            scanf( "%d", &ls1[i] );
        for ( i = 1; i <= P; i++ ) {
            scanf( "%d", &ls2[i] );
            pos[ls2[i]] = i;
        }

        /* dp */
        for ( i = 1; i <= Q; i++ ) {
            k = pos[ls1[i]];            
            if ( !k ) continue;
            
            lo = 0; hi = M; s = 0;
            while ( lo <= hi ) {
                mid = ( lo + hi ) / 2;
                if ( dp[mid] < k ) {
                    lo = mid + 1;
                    s >?= mid;
                }
                else
                    hi = mid - 1;
            }
         
            if ( dp[s + 1] > k ) {
                dp[s + 1] = k;
                M >?= s + 1;
            }
        }
       
        printf( "%d\n", M );
    }
    
    fflush( stdout );
    return 0;
}
