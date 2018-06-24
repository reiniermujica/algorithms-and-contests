/*
 Reinier César Mujica
 17 - 11 - 2008
 String Matching ( Kmp )
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 1000005;
	
int N;
int i, k;
int pkmp[MAXN];
char need[MAXN], s;

int main() {

	while ( scanf( "%d\n", &N ) != EOF ) {

		/* pre KMP for needle pattern */
		gets( need + 1 ); k = 0; 
		for ( i = 2; i <= N; i++ ) {
			pkmp[i] = 0;
			while ( k > 0 && need[i] != need[k + 1] )
				k = pkmp[k];
			if ( need[i] == need[k + 1] ) k++;
			pkmp[i] = k;
		}
		
		k = 0; i = 1;
		while ( scanf( "%c", &s ) != EOF && s != '\n' ) {
            while ( k > 0 && s != need[k + 1] )
				k = pkmp[k];
			if ( s == need[k + 1] ) k++;
			if ( k == N ) {
				printf( "%d\n", i - N );
				k = pkmp[k];
			}
            i++;
        }
	
		printf( "\n" );
	}

	fflush( stdout );
	return 0;
}
