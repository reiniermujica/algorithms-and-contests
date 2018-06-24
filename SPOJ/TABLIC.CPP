/*
 Reinier César Mujica
 10 - 3 - 2009
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 1050;

struct number {
	int id, x, y;
	int cx, cy;
} T[MAXN];
	
int N, K;
int i, j, k;

int move_cell( int x, int sx ) {
	int cont = 0;
	if ( x > sx ) {
		cont += N - x;
		cont += sx;
	}
	if ( x < sx )
		cont += sx - x;
	return cont;
}

int main() {
	
	scanf( "%d %d", &N, &K );
	for ( i = 1; i <= K; i++ ) {
		scanf( "%d %d %d", &T[i].id, &T[i].x, &T[i].y );
		k = T[i].id;
		if ( k % N == 0 ) {
			T[i].cx = k / N;
			T[i].cy = N;
		}
		else {
			T[i].cx = k / N + 1;
			T[i].cy = k % N;
		}
	}

    /* solving or trying */
	for ( i = 1; i <= K; i++ ) {

		int c_x = move_cell( T[i].cx, T[i].x );
		int c_y = move_cell( T[i].cy, T[i].y );

		for ( j = 1; j <= K; j++ ) {
			if ( T[j].id == T[i].id ) continue;

			if ( T[j].cx == T[i].cx ) {
    			if ( T[j].cy + c_y > N ) {
					T[j].cy += c_y;
					T[j].cy -= N;
				}
				else T[j].cy += c_y;
			}
        }

		for ( j = 1; j <= K; j++ ) {
			if ( T[j].id == T[i].id ) continue;

			if ( T[j].cy == T[i].y ) {
				if ( T[j].cx + c_x > N ) {
					T[j].cx += c_x;
					T[j].cx -= N;
				}
				else T[j].cx += c_x;
			}
        }

		for ( j = 1; j <= K; j++ )
			if ( T[j].id == T[i].id ) {
                T[j].cx = T[i].x;
                T[j].cy = T[i].y;
			}

		printf( "%d\n", c_x + c_y );
	}
	
	fflush( stdout );
	return 0;
}
