/*
 Reinier César Mujica
 24 - 4 - 2009
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 100005,
	MAXX = 1000005;
	
int N, X, sol;
int i, j, k;
int T[MAXN];
bool mark[MAXX];

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d", &T[i] );
	scanf( "%d", &X );
	
	for ( i = 1; i <= N; i++ ) {
		if ( T[i] > X ) continue;
		k = X - T[i];
		if ( mark[k] ) {
			sol++;
			mark[k] = false;
		}
		else {
			mark[T[i]] = true;
		}
	}
		
	printf( "%d\n", sol );
	return 0;
}
