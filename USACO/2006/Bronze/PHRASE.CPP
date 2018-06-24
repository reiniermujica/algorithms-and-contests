/*
 Reinier César Mujica
 4/5/08 PSN - 2008
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int
    MAXN = 1002,
    MAXM = 10002;
    
int N, M, sol, i, j, s, act, len, now;
int W[4 * MAXM][256]; // trie
char cad[MAXN];

int main() {

    freopen( "phrase.in", "r", stdin );
    freopen( "phrase.out", "w", stdout );
    
    scanf( "%d %d\n", &M, &N );
    
    for ( i = 0; i < M; i++ ) {
        gets( cad );
        s = strlen( cad );
        act = 1; len = 0;

        while ( s - len && W[act][cad[len]] ) {
         act = W[act][cad[len]];
         len++;
        }
        if ( !(s - len) ) continue;

        while ( s - len ) {
         W[act][cad[len]] = ++now;
         len++; act = now;
        }
    }
    
    for ( i = 0; i < N; i++ ) {
        gets( cad );
        s = strlen( cad );
        act = 1; len = 0;
        
        while ( s - len  && W[act][cad[len]] ) {
         act = W[act][cad[len]];
         len++;
        }

        if ( len == s ) sol++;
    }

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
