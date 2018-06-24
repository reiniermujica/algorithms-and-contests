/*
 Reinier César Mujica
 8 - 1 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
	MAXN = 1051,
	START = 521,
	mov[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	
struct point {
    int x, y, time;
    point( int a = 0, int b = 0, int c = 0 ) {
        x = a; y = b; time = c;
    }
};

int N, T, sol;
int i, j, k;
int x, y, cx, cy;
int C[MAXN][MAXN];
point L[MAXN];
queue < point > Q;

int main() {

	freopen( "EXPLORA.IN", "r", stdin );
	freopen( "EXPLORA.OUT", "w", stdout );
	
	scanf( "%d %d", &N, &T );
    C[START][START] = N;
    
    for ( Q.push( point( START, START, 0 ) ); !Q.empty(); Q.pop() ) {
        x = Q.front().x;
        y = Q.front().y;
        k = Q.front().time;
        if ( k >= T ) continue;
        
        int cant = C[x][y];
        if ( C[x][y] % 4 != 0 ) continue;

        cant = C[x][y] / 4;
        C[x][y] = 0;
        for ( i = 0; i < 4; i++ ) {
            cx = x + mov[i][0];
            cy = y + mov[i][1];
            C[cx][cy] += cant;
            Q.push( point( cx, cy, k + 1 ) );
        }
    }
	
	for ( i = 0; i < MAXN; i++ )
        for ( j = 0; j < MAXN; j++ )
            if ( C[i][j] )
                L[++sol] = point( i - START, j - START, C[i][j] );

    printf( "%d\n", sol );
    for ( i = 1; i <= sol; i++ )
        printf( "%d %d %d\n", L[i].x, L[i].y, L[i].time );
    
    fflush( stdout );
	return 0;
}
