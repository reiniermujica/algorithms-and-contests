/*
 Reinier Cesar Mujica
 09/06/08
 "Cow Plumbing"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100005,
    oo = 1 << 29;

struct cow {
    int L, W;
};

int N, D, L, W;
int i, j;
int T[MAXN];
cow A[MAXN];

int main() {

    freopen( "plumb.in", "r", stdin );
    freopen( "plumb.out", "w", stdout );

    scanf( "%d %d", &D, &N );

    for ( i = 0; i < N; i++ )
     scanf( "%d %d\n", &A[i].L, &A[i].W );

    T[0] = 1 << 29;
    
    for ( i = 0; i < N; i++ ) {
      L = A[i].L; W = A[i].W;
      for ( j = D; j >= 0; j-- )
        if ( T[j] != 0 && j + L <= D ) {
            if ( T[j + L] == 0 )
              T[j + L] = min( T[j], W );
            else
              T[j + L] >?= min( T[j], W );
        }
    }
    
    printf( "%d\n", T[D] );
    
    fflush( stdout );
    return 0;
}
