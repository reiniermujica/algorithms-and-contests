/*
 Reinier César Mujica
 xx/08/2008
 "Bitmap"
 The School comes in one week
 """I very happy?"""
*/

#include <cstdio>
#include <queue>

using namespace std;

#define FOR( _i, _j, _k ) \
    for ( _i = (_j); _i <= (_k); _i++ )

const int
    MAXN = 200,
	mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} },
    oo = 1 << 29;

struct point {
	int x, y;
};

int N, M;
int i, j, k;
int x, y;
int dist[MAXN][MAXN];
char line[MAXN];
queue < point > Q;

int main() {

    freopen( "BIT.in", "r", stdin );
    freopen( "BIT.out", "w", stdout );
	
	scanf( "%d %d\n", &N, &M );
	FOR( i, 1, N ) {
        gets( line + 1 );
		FOR( j, 1, M ) {
			if ( line[j] == '1' ) {
				dist[i][j] = 0;
				Q.push( (point) { i, j } );
			}
			else
			 dist[i][j] = oo;
		}
	}
	
	/* ...BFS... */
	while ( !Q.empty() ) {
		point top = Q.front();
		Q.pop();
		k = dist[top.x][top.y];
		
		FOR( i, 0, 3 ) {
			x = top.x + mov[i][0];
			y = top.y + mov[i][1];
			if ( dist[x][y] > k + 1 ) {
				dist[x][y] = k + 1;
				Q.push( (point) { x, y } );
			}
		}
	}
	
	FOR( i, 1, N ) {
		FOR( j, 1, M )
		 printf( "%d ", dist[i][j] );
		printf( "\n" );
	}

    fflush( stdout );
    return 0;
}
