/*
ID: reywork2
PROG: sort3
LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1001;
	
int N, sol;
int i, j, k;
int T[MAXN], c[4];

int main() {

	freopen( "sort3.in", "r", stdin );
	freopen( "sort3.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) {
		scanf( "%d", &T[i] );
		c[T[i]]++;
	}

	/* trying all one positions */
	for ( i = 1; i <= c[1]; i++ ) {
		if ( T[i] == 2 ) {
			for ( j = c[1] + 1; j <= N; j++ )
			 if ( T[j] == 1 ) {
				swap( T[i], T[j] ); sol++;
				break;
			 }
		}
		else
		if ( T[i] == 3 ) {
			for ( j = c[1] + c[2] + 1; j <= N; j++ )
			 if ( T[j] == 1 ) {
				swap( T[i], T[j] ); sol++;
				break;
			 }
			if ( T[i] == 1 ) continue;
			for ( j = c[1] + 1; j <= N; j++ )
			 if ( T[j] == 1 ) {
				swap( T[i], T[j] ); sol++;
				break;
			 }
		}
	}
	
	/* trying all two positions */	
	for ( i = c[1] + 1; i <= c[1] + c[2]; i++ )
		if ( T[i] == 3 ) {
			for ( j = c[1] + c[2] + 1; j <= N; j++ )
			 if ( T[j] == 2 ) {
				swap( T[i], T[j] ); sol++;
				break;
			 }
		}
		
	printf( "%d\n", sol );
	
	return 0;
}
