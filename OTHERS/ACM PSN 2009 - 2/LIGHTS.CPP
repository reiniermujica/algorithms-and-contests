/*
 Reinier César Mujica
 25 - 06 - 2009
 Gauss
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int
    MAXN = 15,
    MAXM = 150;
    
int N, M;
int i, j, k, cant;
int T[MAXM][MAXM];
int V[MAXM];
char C[MAXN][MAXN];
char cad[MAXN];

int main() {

    while ( true ) {
        gets( cad );
        if ( strstr( cad, "end" ) ) break;
        
        /* read */
        for ( i = 1; i <= 10; i++ )
            gets( C[i] + 1 );

        memset( T, 0, sizeof T );
        memset( V, 0, sizeof V );
        cant = 0;
        
        /* build equations */
        for ( i = 1; i <= 10; i++ ) {
            for ( j = 1; j <= 10; j++ ) {
                cant++;
                T[cant][cant] = 1;
                T[cant][101] = ( C[i][j] == 'O' ) ? 1 : 0;
                if ( i > 1 ) T[cant][cant - 10] = 1;
                if ( i < 10 ) T[cant][cant + 10] = 1;
                if ( j - 1 > 0 ) T[cant][cant - 1] = 1;
                if ( j + 1 <= 10 ) T[cant][cant + 1] = 1;
            }
        }
    
        /* gaussian */
        for ( i = 1; i < cant; i++ ) {
            if ( !T[i][i] ) {
                for ( j = i + 1; j <= cant; j++ )
                    if ( T[j][i] ) {
                        for ( k = 1; k <= 101; k++ )
                            swap( T[i][k], T[j][k] );
                        break;
                    }
            }
            for ( j = i + 1; j <= cant; j++ ) {
                if ( T[j][i] ) // very important this conditions
                    for ( k = i; k <= 101; k++ )
                        T[j][k] = ( T[j][k] + T[i][k] ) % 2;
            }
        }
        
        /* clear var */
        for ( i = cant; i > 0; i-- ) {
            V[i] = T[i][101];
            for ( j = cant; j > i; j-- )
                V[i] = ( V[i] + ( T[i][j] * V[j] ) ) % 2;
            V[i] = ( V[i] ^ T[i][i] ) ^ 1;
        }
        
        k = 0;
        for ( i = 1; i <= cant; i++ )
           k += V[i];
        
        printf( "%s %d\n", cad, k );
    }
    
    fflush( stdout );
    return 0;
}
