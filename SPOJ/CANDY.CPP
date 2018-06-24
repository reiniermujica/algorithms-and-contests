/*
 Reinier César Mujica
 19 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 10050;
    
int N, sol;
int i, j, k;
int T[MAXN];

int main() {
    
    scanf( "%d", &N );
    while ( N != -1 ) {
        j = sol = k = 0;
        for ( i = 1; i <= N; i++ ) {
            scanf( "%d", &T[i] );
            k += T[i];
        }
        if ( k % N ) printf( "-1\n" );
        else {
            k /= N;
            for ( i = 1; i <= N; i++ )
                if ( T[i] > k )
                    sol += T[i] - k;
            printf( "%d\n", sol );
        }
        scanf( "%d", &N );
    }
    
    return 0;
}
