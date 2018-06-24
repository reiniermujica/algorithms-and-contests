/*

*/

#include <cstdio>
#include <string>

using namespace std;

const int
	MAXN = 25;
	
int N, M;
int i, j, k;
char cad[MAXN][MAXN];
bool mark[MAXN][MAXN][2];
string a, sol;

int main() {

	scanf( "%d %d\n", &N, &M );
	for ( i = 1; i <= N; i++ )
		gets( cad[i] + 1 );

    for ( i = 0; i < N * M; i++ )
     sol.push_back( '¦' );
     
	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= M; j++ ) {
            if ( cad[i][j] == '#' ) continue;
			if ( mark[i][j][0] == false ) {
				int cx = i, cy = j;
				a.clear();
                do {
					mark[cx][cy][0] = true;
                    a.push_back( cad[cx][cy] );
                    cy++;
                } while ( cy <= M && cad[cx][cy] != '#' );
                if ( a.size() > 1 && a < sol ) sol = a;
			}
    		if ( mark[i][j][1] == false ) {
				int cx = i, cy = j;
				a.clear();
                do {
					mark[cx][cy][1] = true;
                    a.push_back( cad[cx][cy] );
                    cx++;
                } while ( cx <= N && cad[cx][cy] != '#' );
                if ( a.size() > 1 && a < sol ) sol = a;
            }
		}
	}
	
    printf( "%s\n", sol.c_str() );
	return 0;
}
