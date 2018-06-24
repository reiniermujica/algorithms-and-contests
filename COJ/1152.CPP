/*
 Reinier César Mujica
 04/07/2008
 "A concrete simulation"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXR = 1234,
    MAXC = 5678;

int i, j, k, x, y;
int R[MAXR + 2], C[MAXC + 2];
int id_R[MAXR + 2], id_C[MAXC + 2];
int S[MAXR + 2][MAXC + 2];
char ch;

void init() {
     FOR( i, 1, MAXR )
      R[i] = id_R[i] = i;
     FOR( i, 1, MAXC )
      C[i] = id_C[i] = i;
     k = 1;
     FOR( i, 1, MAXR )
      FOR( j, 1, MAXC )
       S[i][j] = k++;
}

void swap_R() {
     scanf( "%d %d\n", &x, &y );
     swap( R[x], R[y] );
     id_R[R[x]] = x; id_R[R[y]] = y;
}

void swap_C() {
     scanf( "%d %d\n", &x, &y );
     swap( C[x], C[y] );
     id_C[C[x]] = x; id_C[C[y]] = y;
}

void write_Q() {
     scanf( "%d %d\n", &x, &y );
     printf( "%d\n", S[R[x]][C[y]] );
}

void write_Z() {
     scanf( "%d\n", &x );
     k = 1;
     while ( x - MAXC > 0 ) {
        x -= MAXC;
        k++;
     } 
     printf( "%d %d\n", id_R[k], id_C[x] );
}

int main() {

    init();
    while ( scanf( "%c", &ch ) != EOF ) {
      switch ( ch ) {
        case 'R' : swap_R(); break;
        case 'C' : swap_C(); break;
        case 'Q' : write_Q(); break;
        case 'W' : write_Z(); break;
      }
    }

    fflush( stdout );
    return 0;
}
