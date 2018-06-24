/*
 Reinier César Mujica
 25 - 5 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 1000050;

int N;
int i, j, k;
bool win[MAXN];

int max_dig( int x ) {
    int ret = 0;
    while ( x > 0 ) {
        ret >?= x % 10;
        x /= 10;
    }
    return ret;
}

int min_dig( int x ) {
    int ret = 1 << 30;
    while ( x > 0 ) {
        if ( x % 10 )
            ret <?= x % 10;
        x /= 10;
    }
    return ret;
}

int main() {

    freopen( "cdgame.in", "r", stdin );
    freopen( "cdgame.out", "w", stdout );

    /* PREPROCESSING */
    for ( i = 1; i < MAXN; i++ ) {
        j = max_dig( i );
        k = min_dig( i );
        win[i] = !win[i - j] || !win[i - k];
    }

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &k );
        printf( "%s\n", win[k] ? "YES" : "NO" );
    }

    fflush( stdout );
    return 0;
}
