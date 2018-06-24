/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 300;
	
int N, sol;
int i, j, k, c;
int cant[MAXN];
char line[MAXN];

int main() {
	
	freopen( "VHIST.IN", "r", stdin );
	freopen( "VHIST.OUT", "w", stdout );
	
	for ( i = 1; i <= 4; i++ ) {
		gets( line );
		N = strlen( line );
		for ( j = 0; j < N; j++ ) {
		 cant[line[j]]++;
		}
	}
	
	for ( i = 65; i <= 90; i++ )
        sol >?= cant[i];
	
	while ( sol ) {
		
		for ( i = 65; i <= 90; i++ ) {
			if ( cant[i] >= sol ) printf( "*" );
			else if ( i != 90 ) printf( " " );
			if ( i != 90 ) printf( " " );
		}
		printf( "\n" );
		sol--;
	}
	
	for ( i = 65; i < 90; i++ ) printf( "%c ", i );
	printf( "Z\n" );
	
	fflush( stdout );
	return 0;
}
