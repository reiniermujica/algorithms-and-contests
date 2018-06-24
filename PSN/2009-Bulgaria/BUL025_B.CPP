/*
 Reinier César Mujica
 19 - 3 - 2009
 Metodo de Gauss
 fail to chance test 7
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 25;
    
int N = 20, sol;
int i, j, k;
int equa[MAXN][MAXN];
int val[MAXN];
int T[MAXN];

void swap_equa( int x, int y ) {
     for ( int i = 1; i <= N + 1; i++ )
        swap( equa[x][i], equa[y][i] );
}

int main() {

    freopen( "bowls.in", "r", stdin );
    freopen( "bowls.out", "w", stdout );
    
    for ( i = 1; i <= 20; i++ ) {
        scanf( "%d", &equa[i][21] );
        if ( i > 1 ) equa[i][i - 1] = 1;
        if ( i < 20 ) equa[i][i + 1] = 1;
        equa[i][i] = 1;
    }
    
    /* Gauss Elimination */
    for ( i = 1; i < N; i++ ) {
        for ( j = i + 1; j <= N; j++ ) {
            if ( equa[j][i] ) {
                swap_equa( i, j );
                break;
            }
        }
        
        for ( j = i + 1; j <= N; j++ ) {
            if ( equa[j][i] ) {
                for ( k = i; k <= N + 1; k++ )
                    equa[j][k] = ( equa[j][k] + equa[i][k] ) % 2;
            }
        }
    }
    
    /* clear equations */
    for ( i = N; i > 0; i-- ) {
        val[i] = equa[i][N + 1];
        for ( j = N; j > i; j-- )
            val[i] = ( val[i] + equa[i][j] * val[j] ) % 2;
        if ( !equa[i][N + 1] && !equa[i][i] ) val[i] = 0;
        else val[i] = ( val[i] ^ equa[i][i] ) ^ 1;
    }

    sol = count( val + 1, val + N + 1, 1 );
    printf( "%d\n", sol );
    for ( i = 1; i <= N; i++ )
        if ( val[i] ) printf( "%d ", i );
        
    printf( "\n" );
       
    fflush( stdout );
    return 0;
}
