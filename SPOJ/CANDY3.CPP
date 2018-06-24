/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

long long N, T, i, k;
long long t;

int main() {
    
    for ( scanf( "%lld", &T ); T; T-- ) {
        
        scanf( "%lld", &N );
        for ( i = 0, t = 0; i < N; i++ ) {
            scanf( "%lld", &k );
            t += k; t %= N;
        }
        
        if ( t % N ) printf( "NO\n" );
        else printf( "YES\n" );
    }
    
    return 0;
}