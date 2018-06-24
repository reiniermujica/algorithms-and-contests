/*
 Reinier César Mujica
 24 - 11 - 2008
*/

#include <cstdio>
#include <queue>

using namespace std;

const int
	MAXN = 800,
	mov[8][2] = { {0,1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1},{0,-1} };
	
typedef pair < int, int > par;

int N, M, sol;
int i, j;
int T[MAXN][MAXN];
bool mark[MAXN][MAXN], OK;

void bfs( int x, int y ) {
     mark[x][y] = true;
	 OK = true;
	 queue < par > Q;
	 
	 for ( Q.push( par( x, y ) ); !Q.empty(); Q.pop() ) {
        int cx = Q.front().first;
        int cy = Q.front().second;
	    mark[cx][cy] = true;

		for ( int i = 0; i < 8; i++ ) {
			int dx = cx + mov[i][0];
			int dy = cy + mov[i][1];
			
			if ( dx > 0 && dx <= N && dy > 0 && dy <= M ) {
                if ( T[dx][dy] > T[cx][cy] ) {
                    OK = false;
                    continue;
                }
                if ( !mark[dx][dy] && T[dx][dy] == T[cx][cy] ) {
                    mark[dx][dy] = true;
                    Q.push( par( dx, dy ) );
                }
            }
		}
	 }
	 sol += ( OK );
}

int main() {
	
	freopen( "guardian.in", "r", stdin );
	freopen( "guardian.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= N; i++ )
	 for ( j = 1; j <= M; j++ )
	  scanf( "%d", &T[i][j] );

	for ( i = 1; i <= N; i++ )
	 for ( j = 1; j <= M; j++ )
		if ( !mark[i][j] ) bfs( i, j );
	  
	printf( "%d\n", sol );
	return 0;
}
