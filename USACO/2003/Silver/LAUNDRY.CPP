/*
 Reinier César Mujica
 22 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 1050;

int N, sol;
int i, j;
int T[MAXN], B[MAXN];

int main() {

    freopen( "laundry.in", "r", stdin );
    freopen( "laundry.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d %d", &T[i], &B[i] );

    for ( i = 1; i <= N; i++ ) {
        if ( T[i] == B[i] ) continue;

        for ( j = 1; j <= N; j++ )
            if ( B[j] == T[i] ) break;

        if ( j > i ) {
            while ( j != i ) {
                swap( B[j], B[j - 1] );
                j--;
                sol++;
            }
        }
        else {
            while ( j != i ) {
                swap( B[j], B[j + 1] );
                j++;
                sol++;
            }
        }
    }

    printf( "%d\n", sol );
    return 0;
}
