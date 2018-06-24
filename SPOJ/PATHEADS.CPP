/*
 Reinier César Mujica
 19 - 12 - 2008
 like DIVSUM
*/

#include <cstdio>

using namespace std;

const int
    MAXN = 1000010;
    
int N;
int i, j, k;
int cant[MAXN], dp[MAXN], T[100001];

int main() {

    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &T[i] );
        cant[T[i]]++;
    }

    for ( i = 1; i < MAXN; i++ ) {
        if ( cant[i] == 0 ) continue;
        for ( j = i; j < MAXN; j += i )
            dp[j] += cant[i];
    }

    for ( i = 1; i <= N; i++ )
        printf( "%d\n", dp[T[i]] - 1 );

    fflush( stdout );
    return 0;
}