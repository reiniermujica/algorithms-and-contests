/*
 Reinier César Mujica
 31 - 3 - 2009
*/

#include <cstdio>

using namespace std;

typedef long long int64;

int64 C, N, M;
int64 i, j, k;
int64 a1, b1, d1;
int64 a2, b2, d2;
int64 *T;

int64 f1( int64 c ) {
      return ( a1 * c ) / d1 + b1;
}

int64 f2( int64 c ) {
      return ( a2 * c ) / d2 + b2;
}

int main() {

    freopen( "baying.in", "r", stdin );
    freopen( "baying.out", "w", stdout );
    
    scanf( "%d %d",  &C, &N );
    scanf( "%d %d %d", &a1, &b1, &d1 );
    scanf( "%d %d %d", &a2, &b2, &d2 );
    
    int64 s1 = f1( C );
    int64 s2 = f2( C );
    int64 l1 = 1, l2 = 1;
    T = new int64[N + 1];
    T[M = 1] = C;
    while ( M < N ) {
        int64 top = T[M];
        if ( s1 < s2 ) {
            if ( s1 != top ) T[++M] = s1;
            s1 = f1( T[++l1] );
        }
        else {
            if ( s2 != top ) T[++M] = s2;
            s2 = f2( T[++l2] );
        }
    }

    printf( "%lld\n", T[N] );
    return 0;
}
