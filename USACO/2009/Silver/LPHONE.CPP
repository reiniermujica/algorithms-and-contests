/*
 Reinier César Mujica
 15 - 2 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
	MAXN = 200,
	mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
	
struct point {
	int x, y, z;
	point( int a = 0, int b = 0, int c = 0 ) {
		x = a; y = b; z = c;
	}
};

int N, M, sol;
int i, j, k;
int cx, cy, dir;
int dp[MAXN][MAXN][4];
bool ok[MAXN][MAXN];
int pos[2][2];
char cad[MAXN];
queue < point > Q;

int main() {

	freopen( "lphone.in", "r", stdin );
	freopen( "lphone.out", "w", stdout );
	
	memset( dp, 60, sizeof dp );
	scanf( "%d %d\n", &M, &N );
	for ( i = 1; i <= N; i++ ) {
		gets( cad + 1 );
		for ( j = 1; j <= M; j++ ) {
			if ( cad[j] == 'C' ) {
				pos[k][0] = i; pos[k][1] = j;
				k++;
			}
			if ( cad[j] == '*' )
				ok[i][j] = true;
		}
	}
	
	for ( i = 0; i < 4; i++ )
		dp[pos[0][0]][pos[0][1]][i] = 0;
		
	for ( Q.push( point( pos[0][0], pos[0][1], -1 ) ); !Q.empty(); Q.pop() ) {
		cx = Q.front().x;
		cy = Q.front().y;
		dir = Q.front().z;
		for ( i = 0; i < 4; i++ ) {
			int x = cx + mov[i][0];
			int y = cy + mov[i][1];
			if ( x <= 0 || x > N || y <= 0 || y > M || ok[x][y] ) continue;
			int cost;
			if ( dir == -1 ) cost = 0;
			else cost = dp[cx][cy][dir] + ( dir != i );
			if ( dp[x][y][i] > cost ) {
				dp[x][y][i] = cost;
				Q.push( point( x, y, i ) );
			}
		}
	}
	
	sol = 1 << 30;
	for ( i = 0; i < 4; i++ )
		sol <?= dp[pos[1][0]][pos[1][1]][i];
		
	printf( "%d\n", sol );
	return 0;
}
