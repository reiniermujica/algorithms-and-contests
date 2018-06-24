/*
 ID: reywork2
 PROG: holstein
 LANG: C++
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 30;

int N, V, sol = 1 << 30, best;
int i, j, k;
int cow[MAXN], S[MAXN];
int tmp[MAXN], sum[MAXN];
int scp[MAXN][MAXN];
	
int main() {

	freopen( "holstein.in", "r", stdin );
	freopen( "holstein.out", "w", stdout );
	
	scanf( "%d", &V );
	for ( i = 1; i <= V; i++ )
	 scanf( "%d", &cow[i] );
	 
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
	 for ( j = 1; j <= V; j++ )
	  scanf( "%d", &scp[i][j] );

	for ( i = 1; i < ( 1 << N ); i++ ) {

        best = 0;
		memset( sum, 0, sizeof sum );
		
		for ( j = 1; j <= N; j++ ) {
			if ( i & ( 1 << ( j - 1 ) ) ) {
				for ( k = 1; k <= V; k++ )
				 sum[k] += scp[j][k];
				tmp[++best] = j;
			}
		}
		
		bool ok = true;
		for ( j = 1; j <= V; j++ )
			if ( sum[j] < cow[j] ) {
				ok = false;
				break;
			}
		
		if ( ok && best <= sol ) {
			sol = best;
			for ( j = 1; j <= best; j++ )
			 S[j] = tmp[j];
		}
	}
	
	printf( "%d ", sol );
	for ( i = 1; i <= sol; i++ )
	 printf( ( i == sol ) ? "%d\n" : "%d ",  S[i] );
	 
	fflush( stdout );
	return 0;
}
