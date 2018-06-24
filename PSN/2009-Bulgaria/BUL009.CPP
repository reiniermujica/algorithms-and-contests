/*
 Reinier César Mujica
 3 - 3 - 2009
 No cabe tanta memoria pa el preKMP
 pero es una solucion tambien.
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
	MAXN = 20000002;
	
int N, sol;
int i, k;
vector < int > kmp;
char cad[MAXN];

int main() {
	
	freopen( "PATRON.IN", "r", stdin );
	freopen( "PATRON.OUT", "w", stdout );
	
	scanf( "%d\n", &N );
	gets( cad + 1 );
	
	kmp.resize( N + 1 );
	for ( i = 2; i <= N; i++ ) {
		while ( k && cad[i] != cad[k + 1] )
			k = kmp[k];
		if ( cad[i] == cad[k + 1] ) k++;
		kmp[i] = k;
	}
	
	sol = N - kmp[N];
	if ( N % sol != 0 ) printf( "%d\n", N );
	else printf( "%d\n", sol );
	
	fflush( stdout );
	return 0;
}
