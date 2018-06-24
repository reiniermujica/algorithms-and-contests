/*
 Reinier César Mujica
 5 - 3 - 2009
*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair < int, int > par;

const int
	MAXN = 155,
	mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
	
int N, M, K, sol;
int i, j, k;
int x, y, comp;
int num[MAXN][MAXN];
char T[MAXN][MAXN];

bool ok( int cx, int cy ) {
	 if ( cx > 0 && cx <= N && cy > 0 && cy <= M ) 
		return true;
}

void bfs( int cx, int cy ) {
	
	 int i, j, k;
	 queue < par > Q;
	 num[cx][cy] = comp;
	 
	 for ( Q.push( par( cx, cy ) ); !Q.empty(); Q.pop() ) {
		par top = Q.front();
		for ( i = 0; i < 4; i++ ) {
			int x = top.first + mov[i][0];
			int y = top.second + mov[i][1];
			if ( ok( x, y ) && T[x][y] == 'x' && num[x][y] == 0 ) {
				num[x][y] = comp;
				Q.push( par( x, y ) );
			}
		}
	 }
}

void down( int id ) {
	 int i, j, k;
	 queue < par > S;

	 bool ok = true;
	 while ( ok ) {

	 for ( i = N; i > 0; i-- )
		for ( j = 1; j <= M; j++ ) {
			if ( num[i][j] == id ) {
				if ( i + 1 <= N ) {
					if ( T[i + 1][j] == 'x' ) {
						if ( num[i + 1][j] != id ) {
							ok = false;
							break;
						}
						else
							S.push( par( i, j ) );
					}
					else
						S.push( par( i, j ) );
				}
				else {
					ok = false;
					break;
				}
			}
		}
	 if ( ok ) { 
		while ( !S.empty() ) {
			par tope = S.front();
			T[tope.first][tope.second] = '.';
			T[tope.first + 1][tope.second] = 'x';
			num[tope.first][tope.second] = 0;
			num[tope.first + 1][tope.second] = id;
			S.pop();
		}
	 }
     }
}

int main() {
	
	scanf( "%d %d\n", &N, &M );
	for ( i = 1; i <= N; i++ )
		gets( T[i] + 1 );
		
	scanf( "%d", &K );
	for ( i = 1; i <= K; i++ ) {
		scanf( "%d", &k );
		k = N - k + 1;
		if ( i % 2 == 0 ) {
			j = M;
			while ( j > 0 && T[k][j] == '.' ) j--;
		}
		else {
			j = 1;
			while ( j > 0 && T[k][j] == '.' ) j++;
		}
		x = k; y = j;

		if ( T[x][y] == 'x' ) {
			T[x][y] = '.';
			memset( num, 0, sizeof num ); comp = 0;

			for ( j = 0; j < 4; j++ ) {
				int cx = x + mov[j][0];
				int cy = y + mov[j][1];
				if ( ok( cx, cy ) && T[cx][cy] == 'x' ) {
					if ( num[cx][cy] == 0 ) {
						comp++;
						bfs( cx, cy );					
					}
				}
			}
			if ( comp > 1 ) {
				for ( j = 1; j <= comp; j++ )
					down( j );
			}
		}
	}

	for ( i = 1; i <= N; i++ )
		puts( T[i] + 1 );
		
	return 0;
}
