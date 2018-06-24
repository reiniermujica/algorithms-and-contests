/*
 Reinier César Mujica
 28/08/2008
 "Palindrome"
*/

#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

const int
    MAXN = 5005;

int N;
int i, j;
char A[MAXN], B[MAXN];
int last[MAXN], next[MAXN];

int main() {

    freopen( "palin.in", "r", stdin );
    freopen( "palin.out", "w", stdout );

	scanf( "%d\n", &N );
	gets( A + 1 );
	for ( i = 1; i <= N; i++ )
	 B[i] = A[N - i + 1];
	
	/* ...dp...*/
	for ( i = 1; i <= N; i++ ) {
		memcpy( last, next , sizeof next );
		
		for ( j = 1; j <= N; j++ ) {
			if ( A[i] == B[j] )
			 next[j] = last[j - 1] + 1;
			else
			 next[j] = max( last[j], next[j - 1] );
		}
	}
	
	printf( "%d\n", N - next[N] );
	
    fflush( stdout );
    return 0;
}
