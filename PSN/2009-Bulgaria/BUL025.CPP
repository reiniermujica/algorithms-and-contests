/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 25;
    
int N = 20, sol = 1 << 30;
int i, j, k;
int T[MAXN], S[MAXN], temp[MAXN], ss[MAXN];

int main() {

    freopen( "bowls.in", "r", stdin );
    freopen( "bowls.out", "w", stdout );
    
    for ( i = 1; i <= 20; i++ )
        scanf( "%d", &T[i] );
    
    for ( i = 0; i < ( 1 << 20 ); i++ ) {
        if ( __builtin_popcount( i ) >= sol ) continue;

        for ( j = 1; j <= 20; j++ )
            temp[j] = T[j];
            
        k = 0;
        for ( j = 1; j <= 20; j++ ) {
            if ( i & ( 1 << ( j - 1 ) ) ) {
                ss[++k] = j;
                temp[j] = !temp[j];
                temp[j - 1] = !temp[j - 1];
                temp[j + 1] = !temp[j + 1];
            }
        }
        
        bool ok = true;
        for ( j = 1; j <= 20; j++ ) {
            if ( temp[j] == 1 ) {
                ok = false;
                break;
            }
        }
        
        if ( ok ) {
            sol = k;
            for ( j = 1; j <= 20; j++ )
                S[j] = ss[j];
        }
    }
    
    printf( "%d\n", sol );
    for ( i = 1; i <= sol; i++ )
        printf( "%d ", S[i] );
    printf( "\n" );
       
    fflush( stdout );
    return 0;
}
