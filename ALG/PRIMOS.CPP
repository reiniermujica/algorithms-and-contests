/*
 Reinier César Mujica
 update xx/08/2008
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100002;

int N, sol;
int i, j, k;
bool mk[MAXN];

int main() {
    
	freopen( "primo.in", "r", stdin );
    freopen( "primo.out", "w", stdout );
    
	scanf( "%d", &N );
    for ( i = 2; i*i <= N; i++ ) {
     if ( !mk[i] ) {
        j = i;
        while ( j * i <= N ) {
            mk[j * i] = true;
            j++;
        }
     }
	}
    
    sol = count( mk + 2, mk + N + 1, false );
    
    printf( "%d\n", sol );
    for ( i = 2; i <= N; i++ )
     if ( !mk[i] ) printf( "%d\n", i );

    fflush( stdout );
    return 0;
}
