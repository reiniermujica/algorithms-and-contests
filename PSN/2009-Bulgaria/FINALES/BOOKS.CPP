/*
 Reinier César Mujica
 23 - 4 - 2009
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 55;
	
int N, sol;
int i, j, m;
int H[MAXN][MAXN];
bool mark[MAXN][MAXN];

int main() {
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		for ( j = 1; j <= N; j++ )
			scanf( "%d", &H[i][j] );
		
	/* <----> */
	for ( i = 1; i <= N; i++ ) {
		m = 0;
		for ( j = 1; j <= N; j++ ) {
			if ( H[i][j] && H[i][j] > m && !mark[i][j] ) {
				sol++;
				mark[i][j] = true;
			}
			m >?= H[i][j];
        }
        
		m = 0;
		for ( j = N; j > 0; j-- ) {
			if ( H[i][j] && H[i][j] > m && !mark[i][j] ) {
				sol++;
				mark[i][j] = true;
			}
    		m >?= H[i][j];
        }
	}
	
	/* | | check */
	for ( i = 1; i <= N; i++ ) {
		m = 0;
		for ( j = 1; j <= N; j++ ) {
			if ( H[j][i] && H[j][i] > m && !mark[j][i] ) {
				sol++;
				mark[j][i] = true;
			}
			m >?= H[j][i];
        }
		
        m = 0;
		for ( j = N; j > 0; j-- ) {
			if ( H[j][i] && H[j][i] > m && !mark[j][i] ) {
				sol++;
				mark[j][i] = true;
			}
			m >?= H[j][i];
        }
	}
	
	printf( "%d\n", sol );
	return 0;
}
