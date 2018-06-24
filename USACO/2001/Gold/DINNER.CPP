/*
 Reinier Cesar Mujica
 09/06/2008
 "Dinner Time"
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 50002;

int N, i, x;
bool mk[MAXN], mk2[MAXN];

int main() {

    freopen( "dinner.in", "r", stdin );
    freopen( "dinner.out", "w", stdout );
    
    scanf( "%d", &N );
    mk[0] = true; mk[MAXN] = true;
    mk2[0] = true; mk2[MAXN] = true;
    
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &x );
        if ( mk[x] ) {
            printf( "%d\n", x + 1 );
            mk[x + 1] = true;
        }
        else
        if ( !mk2[x - 1] && !mk[x] ) {
            printf( "%d\n", x - 1 );
            mk[x - 1] = true;
        }
        else {
            printf( "%d\n", x );
            mk[x] = true;
        }
        mk2[x] = true;
    }

    fflush( stdout );
    return 0;
}
