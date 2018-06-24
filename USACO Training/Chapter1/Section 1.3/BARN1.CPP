/*
ID: reywork2
PROG: barn1
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 25000;
    
int N, M, S, T[MAXN], L[MAXN], i, j, k, sol;

int main() {
    freopen( "barn1.in", "r", stdin );
    freopen( "barn1.out", "w", stdout );
    scanf( "%d%d%d", &M, &N, &S );
    for ( i = 1; i <= S; i++ ) {
       scanf( "%d", &T[i] ); 
    }
    sort( T + 1, T + S + 1 );

    for ( i = 1; i < S; i++ )
     L[i] = T[i+1] - T[i] - 1;
    
    sort( L + 1, L + S );
    sol=0;
    for ( i = S - 1; i>=(S - M ) + 1; i-- ) {
     if ( i < 0 ) break;   
     sol+=L[i];   
    }
    printf( "%d\n", T[S] - T[1] - sol + 1 );
    fflush( stdout );
    return 0;    
}
