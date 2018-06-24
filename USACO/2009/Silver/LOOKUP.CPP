/*
 Reinier César Mujica
 20 - 3 - 2009
 Linked list
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 100005;
    
int N, sol;
int i, j, k;
int T[MAXN], last[MAXN];

int main() {
    
    freopen( "lookup.in", "r", stdin );
    freopen( "lookup.out", "w", stdout );
    
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &T[i] );
    
    for ( i = N - 1; i; i-- ) {
        k = i + 1;
        while ( true ) {
            if ( k == 0 ) {
                last[i] = 0;
                break;
            }
            if ( T[i] > T[k] )
                k = last[k];
            else {
                if ( T[i] == T[k] )
                    last[i] = last[k];
                else last[i] = k;
                break;
            }
        }
    }
    
    for ( i = 1; i <= N; i++ )
        printf( "%d\n", last[i] );
    
    fflush( stdout );
    return 0;
}
