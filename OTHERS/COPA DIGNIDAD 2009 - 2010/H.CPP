/*
 Reinier Cesar Mujica
 11 - 9 - 2010
 the day of the 9-11 happenings
*/

#include <cstdio>

using namespace std;

int T, x;

int sumdig( int x ) {
	int res = 0;
	while ( ( x / 10 ) > 0 ) {
		res += x % 10;
		x /= 10;
	}
	return res + x;
}

int fact( int x ) {
	int res = 1;
	for ( int i = 0; i < x; i++ )
		res *= ( i + 1 );
	return res;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &x );
		if ( x <= 5 )  
    		printf( "%d\n", sumdig( fact( x ) ) );
		else printf( "9\n" );
	}
	
	return 0;
}
