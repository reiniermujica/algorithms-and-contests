/*

*/

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 102

const int mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

typedef pair <int, int> par;

int T, H, W;
int i, j, k;
int sol;
char grid[MAXN][MAXN];
int mark[MAXN][MAXN];
queue <par> Q;

bool valid( int x, int y )
{
	if ( x > 0 && x <= H && y > 0 && y <= W && grid[x][y] != '.' )
		return true;
	return false;
}

void bfs( int x, int y )
{
	Q.push(par(x, y));
	while ( !Q.empty() )
	{
		par top = Q.front();
		Q.pop();
		
		for ( int i = 0; i < 4; i++ )
		{
			int nx = top.first + mov[i][0];
			int ny = top.second + mov[i][1];
			if ( valid(nx,ny) && !mark[nx][ny] )
			{
				mark[nx][ny] = sol;
				Q.push( par( nx, ny ) );
			}		
		}	
	}
}

int main()
{
	scanf( "%d\n", &T );
	while ( T-- )
	{
		scanf( "%d %d\n", &H, &W );
		for ( i = 1; i <= H; i++ )
		{
			for ( j = 1; j <= W; j++ )
			{
				scanf("%c", &grid[i][j] );
				mark[i][j] = 0;						
			}
			scanf( "%c", &grid[0][0] ); // new line char
		}
		
		/* bfs */		
		for ( i = 1, sol = 0; i <= H; i++ )
		{
			for ( j = 1; j <= W; j++ )
			{
				if ( grid[i][j] == '#' && !mark[i][j] )
				{
					mark[i][j] = ++sol;
					bfs( i, j );
				}
			}			
		} 
		
		printf( "%d\n", sol );
	}

	return 0;
}
