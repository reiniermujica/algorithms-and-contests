/*
 Reinier César Mujica
 9 - 1 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 150,
	mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
	
struct point {
	int x, y, dir;
	point( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; dir = c;
	}
} start, end;

int N, sol;
int i, j, k;
int cx, cy;
int min_dist[MAXN][MAXN][4];
bool mark[MAXN][MAXN];
char cad[MAXN];
queue < point > Q;

int main() {

	freopen( "obstacle.in", "r", stdin );
	freopen( "obstacle.out", "w", stdout );
	
	scanf( "%d\n", &N );
	for ( i = 1; i <= N; i++ ) {
		gets( cad + 1 );
		for ( j = 1; j <= N; j++ ) {
			if ( cad[j] == 'A' )
				start = point( i, j, 0 );
			if ( cad[j] == 'B' )
				end = point( i, j, 0 );
			if ( cad[j] == 'x' )
				mark[i][j] = true;
		}
	}
	
	memset( min_dist, 60, sizeof min_dist );
	for ( i = 0; i < 4; i++ )
		min_dist[start.x][start.y][i] = 0;
	
	for ( Q.push( start ); !Q.empty(); Q.pop() ) {
		point node = Q.front();
		
		for ( i = 0; i < 4; i++ ) {
			cx = node.x + mov[i][0];
			cy = node.y + mov[i][1];
			if ( cx <= 0 || cx > N || cy <= 0 || cy > N || mark[cx][cy] ) continue;
			
			if ( node.x == start.x && node.y == start.y ) k = 0;
			else k = ( i != node.dir ) ? 1 : 0;
			
			k += min_dist[node.x][node.y][node.dir];
			if ( min_dist[cx][cy][i] > k ) {
				min_dist[cx][cy][i] = k;
				Q.push( point( cx, cy, i ) );
			}
		}
	}
	
	sol = 1 << 30;
	for ( i = 0; i < 4; i++ )
        sol <?= min_dist[end.x][end.y][i];
	printf( "%d\n", sol );
	
	fflush( stdout );
	return 0;
}
