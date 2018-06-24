/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 105;
    
int N, M, sol, s1, s2;
int i, j, k;
int T[MAXN][MAXN];

int main() {
    
    freopen( "goodgrs.in", "r", stdin );
    freopen( "goodgrs.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++ ) {
        for ( j = 1; j <= M; j++ ) {
            scanf( "%d", &T[i][j] );
        }
    }
    
    for ( i = 1; i <= N - 2; i++ )
        for ( j = 1; j <= M - 2; j++ ) {
            int sum = 0;
            for ( k = 0; k < 3; k++ ) {
                sum += ( T[i + k][j] + T[i + k][j + 1] + T[i + k][j + 2] );
            }
            if ( sum > sol ) {
                sol = sum;
                s1 = i; s2 = j;
            }
        }
    
    printf( "%d\n", sol );
    printf( "%d %d\n", s1, s2 );
    
    fflush( stdout );
    return 0;
}
