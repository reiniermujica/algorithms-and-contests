/*
 Reinier César Mujica
 26 - 5 - 2009
 SPOJ #1787 ENCONDIN
*/

#include <cstdio>
#include <cstring>

using namespace std;

int N;
int i, j;
char cad[1000005];

int main() {
    
    while ( gets( cad ) ) {
		N = strlen( cad ); cad[N] = '\0';
		for ( i = 0; i < N; ) {
            if ( cad[i] == cad[i + 1] ) {
                for ( j = 1; j < 9; j++ )
                    if ( cad[i] != cad[i + j] ) break;
                printf( "%d%c", j, cad[i] );
                i += j;
            }
			else {
				printf( "1" );
				j = i;
  				while ( j < N && cad[j] != cad[j + 1] ) {
       				if ( cad[j] == '1' )
                        printf( "11" );
                    else
                       printf( "%c", cad[j] );
	      			j++;
    	       	}
				printf( "1" );
                i = j;
            }
		}
		
        printf( "\n" );
    }
    
    fflush( stdout );
    return 0;
}
