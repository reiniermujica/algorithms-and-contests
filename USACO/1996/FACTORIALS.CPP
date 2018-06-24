/*
 Reinier César Mujica
 3 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 100;
	
int N, ls = 1;
int i, sol;

int main() {

    do {
	scanf( "%d", &N );
    if ( !N ) break; ls = 1;
	for ( i = 1; i <= N; i++ ) {
		
		ls = ls * i;
		while ( ls % 10 == 0 ) {
			ls /= 10;
		}
        if ( ls > 10000 ) ls %= 1000;
	}

	printf( "%d\n", ls % 10 ); }
	while ( 1 );
	return 0;
}