/*
 Reinier César Mujica
 3/08/2008
 Rev( file sol | your sol )
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )
const int
    MAXN = 1002,
    oo = 1 << 29;

typedef pair < int , int > par;
int N, M, sol;
int i, j, k;
vector < par > A, B;

int main(int argc, char *argv[] ) {

    FILE * fe = fopen( argv[1], "r" );
    FILE * fs = fopen( argv[2], "r" );
    fscanf( fe, "%d", &N );
    fscanf( fs, "%d", &M );
    if ( N != M ) {
        printf( "Wrong Number..\n" );
        return 0;
    }

    FOR( i, 1, N ) {
        fscanf( fe, "%d %d", &j, &k );
        if ( j > k ) swap( j, k );
        A.push_back( par(j, k ) );
    }
    FOR( i, 1, N ) {
        fscanf( fs, "%d %d", &j, &k );
        if ( j > k ) swap( j, k );
        B.push_back( par(j, k ) );
    }
    sort( A.begin(), A.end() );
    sort( B.begin(), B.end() );

    FOR( i, 0, N - 1 ) {
        if ( A[i] != B[i] ) {
        printf( "Wrong..\n");
        return 0;
       }
    }
        printf( "Ok!!!\n" );
    
    fflush( stdout );
    return 0;
}
