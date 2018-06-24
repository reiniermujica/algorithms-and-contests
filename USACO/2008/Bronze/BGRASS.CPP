#include <cstdio>
#include <algorithm>

#define REP( i, k, N ) for ( i = k; i <= N; i++ )

using namespace std;

const int
    MAXN = 150;
    
int N, M, sol, i, j, x, y;
char C[MAXN][MAXN];
bool mk[MAXN][MAXN];

int main() {

    freopen( "bgrass.in", "r", stdin );
    freopen( "bgrass.out", "w", stdout );
    
    scanf( "%d %d\n", &N, &M );
    
    REP( i, 1, N ) {
     fill( mk[i], mk[i] + MAXN, false );
     gets( C[i] + 1 );
    }

    REP( i, 1, N )
     REP( j, 1, M ) {
        if ( !mk[i][j] && C[i][j] == '#' ) {
            sol++;
            if ( C[i + 1][j] == '#' ) {
                mk[i + 1][j] = true;
            }
            else
            if ( C[i][j + 1] == '#' ) {
                mk[i][j + 1] = true;
            }
        }
     }
     
    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
