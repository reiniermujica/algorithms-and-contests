#include <cstdio>

using namespace std;

const int
	NUM[8] = { 137, 1315, 73, 136, 255, 1384, 16385 };
	
void dfs( int x, bool ok ) {

	 while ( x > 0 ) {
        printf( "2" );
        int n = 1;
        while ( 1 << n <= x ) n++; n--;
        if ( n >= 2 ) {
            printf( "(" );
            dfs( n, false );
            x -= 1 << n;
            if ( x > 0 ) printf( "+" );
            else printf( ( !ok ) ? ")" : "" );
        }
        if ( n == 1 ) {
            x -= 1 << n;
           if ( x > 0 ) printf( "+" );
            else printf( ( !ok ) ? ")" : "" );
        }
        if ( n == 0 ) {
            printf( "(0)" );
            x -= 1 << n;
           if ( x > 0 ) printf( "+" );
            else printf( ( !ok ) ? ")" : "" );
        }
     }
}

int main() {

	for ( int i = 0; i < 7; i++ ) {
		printf( "%d=", NUM[i] );
		dfs( NUM[i], true );
		printf( "\n" );
	}

	fflush( stdout );
	return 0;
}
