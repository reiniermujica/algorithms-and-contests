/*
 ID: reywork2
 PROG: numtri
 LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 1001;
    
int N, sol;
int i, j, x;
int last[MAXN], next[MAXN];

int main() {

    freopen( "numtri.in", "r", stdin );
    freopen( "numtri.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
         memcpy( last, next, sizeof next );
         for ( j = 1; j <= i; j++ ) {
            scanf( "%d", &x );
            next[j] = max( last[j], last[j - 1] ) + x;
            sol >?= ( i == N ) ? next[j] : 0;
         }
    }

    printf( "%d\n", sol );

    fflush( stdout );
    return 0;
}
