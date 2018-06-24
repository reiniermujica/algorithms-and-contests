/*

*/

#include <cstdio>

using namespace std;

const int
	MAXN = 550;
	
int N, M;
int a, b, id;
int i, j, k;
bool mark[MAXN];

int main() {

	freopen( "swtch.in", "r", stdin );
	freopen( "swtch.out", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	for ( i = 1; i <= M; i++ ) {
		scanf( "%d %d %d", &id, &a, &b );
		if ( !id )
			for ( j = a; j <= b; j++ )
				mark[j] = !mark[j];
		else {
			k = 0;
			for ( j = a; j <= b; j++ )
				k += mark[j];
			printf( "%d\n", k );
		}
	}
	
	fflush( stdout );
	return 0;
}
