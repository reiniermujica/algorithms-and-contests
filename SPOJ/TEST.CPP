/*
 Reinier César Mujica
 11/05/08
 SPOJ #1 Life, the Universe, and Everything.
*/

#include <cstdio>

int N;

int main() {

    scanf( "%d", &N );
    while ( N != 42 ) {
      printf( "%d\n", N );
      scanf( "%d", &N );
    }

    fflush( stdout );
    return 0;
}
