#include <cstdio>

using namespace std;

const int
    MAXN = 18;
    
int N, C, sol, i, j, k, limit;
int T[MAXN];

int main() {

    freopen( "cowflix.in", "r", stdin );
    freopen( "cowflix.out", "w", stdout );
    
    scanf( "%d %d", &C, &N );
    
    for ( i = 1; i <= N; i++ )
     scanf( "%d", &T[i] );
     
    limit = 1 << N;
    
    for ( i = 0; i < limit; i++ ) {
     k = 0;
     for ( j = 0; j < N; j++ )
      if ( i & ( 1 << j ) ) k += T[j + 1];
     if ( k <= C ) sol >?= k;
    }

    printf( "%d\n", sol );
    
    fflush( stdout );
    return 0;
}
