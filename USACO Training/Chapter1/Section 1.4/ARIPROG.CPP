/*
 ID: reywork2
 PROG: ariprog
 LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXM = 130000;

int N, M, cant, L;
int i, j, k;
bool mk[MAXM], found = false;
int lis[MAXM];

bool ok( int a, int b ) {
     int i = 0;
     while ( mk[a + i*b] && i < N ) i++;
     return ( i == N ) ? true : false;
}

int main() {

	freopen( "ariprog.in", "r", stdin );
	freopen( "ariprog.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 0; i <= M; i++ )
	 for ( j = i; j <= M; j++ ) {
		k = i*i + j*j;
		if ( !mk[k] ) {
            lis[++cant] = k;
    	    mk[k] = true;
        }
	 }
	
	L = M * M * 2 + 5;
	sort( lis + 1, lis + cant + 1 );

	for ( i = 1; i * ( N - 1 ) <= L; i++ )
	 for ( j = 1; j <= cant && lis[j] + (i * ( N - 1 )) <= L; j++ ) {

	    if ( ok( lis[j], i ) ) {
            printf( "%d %d\n", lis[j], i );
            found = true;
        }
	 }

	if ( !found ) printf( "NONE\n" );

	fflush( stdout );
	return 0;
}
