/*

*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
	MAXN = 200,
	MAXM = 100,
	oo = 1 << 30,
	mov[8][2] = { {-1,-1}, {0,1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {0,-1} };

typedef pair < int, int > par;

int N, M, sol;
int i, j, k;
int x, y, z;
int T[MAXN][MAXM];
bool mark[MAXN][MAXM];

queue < par > Q;

void bfs( int x1, int y1 ) {
	 mark[x1][y1] = true;
	 bool ok = true;
	 
	 for ( Q.push( par( x1, y1 ) ); !Q.empty(); Q.pop() ) {
		x = Q.front().first;
		y = Q.front().second;
		
		for ( int i = 0; i < 8; i++ ) {
			int cx = x + mov[i][0];
			int cy = y + mov[i][1];
			
            if ( cx > 0 && cx <= N && cy > 0 && cy <= M ) {
			
			if ( T[cx][cy] > T[x][y] ) ok = false;
			else { 
				if ( T[cx][cy] == T[x][y] && mark[cx][cy] == false ) {
					mark[cx][cy] = true;
					Q.push( par( cx, cy ) );
				}
			}
            }
		}
		
	 }
	 sol += ok;
}

int main() {

	freopen( "guard.in", "r", stdin );
	freopen( "guard.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N; i++ )
		for ( j = 1; j <= M; j++ )
			scanf( "%d", &T[i][j] );
	
	for ( i = 1; i <= N; i++ )
		for ( j = 1; j <= M; j++ )
			if ( !mark[i][j] ) {
				bfs( i, j );

			}
	
	printf( "%d\n", sol );
	return 0;
}
