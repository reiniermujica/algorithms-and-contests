/*
 Reinier César Mujica
 20 - 11 - 2008
*/

#include <cstdio>
#include <string>

using namespace std;

const int
	MAXN = 1000;
	
int N, L, sol;
int i;
char pass[MAXN], code[MAXN];

bool isletter( char c ) {
	 return ( c >= 'a' && c <= 'z' ) ||
			( c >= 'A' && c <= 'Z' );
}

int main() {

	freopen( "decode.in", "r", stdin );
	freopen( "decode.out", "w", stdout );
	
	gets( pass );
	gets( code );
	
	N = strlen( code );
	for ( i = 0; i < N; i++ ) {
		char c = code[i];
		if ( !isletter( c ) ) {
			printf( "%c", c );
			continue;
		}
		if ( c >= 'A' && c <= 'Z' ) {
			c = c + 32;
			c = pass[c - 'a'];
			c = c - 32;
			printf( "%c", c );
		}
		else {
			c = pass[c - 'a'];
			printf( "%c", c );
		}
	}
	printf( "\n" );
	return 0;
}
