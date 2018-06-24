/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 55,
    mov[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
    
int N, M, sol;
int i, j, k;
int T[MAXN][MAXN];

int main() {
    
    freopen( "plumb.in", "r", stdin );
    freopen( "plumb.out", "w", stdout );
    
    scanf( "%d %d", &N, &M );
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
            scanf( "%d", &T[i][j] );

    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= M; j++ )
            for ( k = 0; k < 8; k++ ) {
                int cx = i + mov[k][0];
                int cy = j + mov[k][1];
                if ( T[i][j] == T[cx][cy] ) {
                    sol >?= T[i][j];
                }
            }
        
        
    printf( "%d\n", sol );
    return 0;
}
