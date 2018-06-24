/*
 Reinier César Mujica
 2 - 10 - 2008
 "Fotografías Satelitales"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 1010,
    MAXM = 90;
	
int N, M, sol;
int i, j, cont, act;
int val[MAXN][MAXM];
char cad[MAXN][MAXM];

void dfs( int x, int y ) {
     if ( val[x][y] != 0 || cad[x][y] != '*' ) return ;
     val[x][y] = cont; act++;
     dfs( x - 1, y );
     dfs( x, y - 1 );
     dfs( x + 1, y );
     dfs( x, y + 1 );
}

int main() {
	
	freopen( "SATPIX.IN", "r", stdin );
	freopen( "SATPIX.OUT", "w", stdout );

    for ( i = 0; i < MAXN; i++ )
     fill( val[i], val[i] + MAXM, -1 );
     
    scanf( "%d %d\n", &M, &N );
    for ( i = 1; i <= N; i++ ) {
     gets( cad[i] + 1 );
     for ( j = 1; j <= M; j++ )
      val[i][j] = 0;
    }
    
    for ( i = 1; i <= N; i++ )
     for ( j = 1; j <= M; j++ )
      if ( val[i][j] == 0 ) {
       cont++; act = 0;
       dfs( i, j );
       sol >?= act;
      }
       

    printf( "%d\n", sol );
	return 0;
}
