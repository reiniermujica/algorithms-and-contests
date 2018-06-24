/*
 Reinier César Mujica
 xx/08/2008
 "Flowers"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int
    MAXN = 100002;

struct cow {
    int T, D;
    bool operator < ( const cow &o ) const {
        return ( T * o.D ) < ( o.T * D );
    }
} C[MAXN];

int N, i, total;
int64 sol;

int main() {

    freopen( "flowers.in", "r", stdin );
    freopen( "flowers.out", "w", stdout );

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &C[i].T, &C[i].D );
        total += C[i].D;
    }

    sort( C, C + N );
    for ( i = 0; i < N; i++ ) {
        sol += ( C[i].T * 2 ) * ( total - C[i].D );
        total -= C[i].D;
    }
    
    printf( "%I64d\n", sol );
    
    fflush( stdout );
    return 0;
}
