/*

*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 150;
	
int N, M;
int i, j, k;
int T[MAXN][3];
int last[MAXN][3];
char cad[MAXN];

int main() {

	freopen( "timecards.in", "r", stdin );
	freopen( "timecards.out", "w", stdout );
	
	scanf( "%d %d\n", &N, &M );
	for ( i = 0; i < M; i++ ) {
		int id, hh, mm;
		scanf( "%d", &id );
		scanf( "%s", &cad );
		scanf( "%d", &hh );
		scanf( "%d", &mm );
		if ( strstr( "START", cad ) ) {
			last[id][0] = hh;
			last[id][1] = mm;
		}
		else {
			int nhh = 0, nmm = 0;
			if ( mm - last[id][1] < 0 ) {
				nhh = -1;
				nmm = ( ( 60 - last[id][1] ) +  mm );
			}
			else {
				nmm = mm - last[id][1];
			}
			nhh += ( hh - last[id][0] );			

            if ( T[id][1] + nmm >= 60 ) {
                T[id][1] += nmm;
                T[id][1] %= 60;
                T[id][0]++;
            }
            else { 
                T[id][1] += nmm;
            }
            
            T[id][0] += nhh;
		}
	}
	
	for ( i = 1; i <= N; i++ ) {
		printf( "%d %d\n", T[i][0], T[i][1] );
	}
	
	fflush( stdout );
	return 0;
}
