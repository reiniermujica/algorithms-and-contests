/*
 Reinier César Mujica
 2 - 12 - 2009
 Suffix Array O( N lg^2 ( N ) )
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int
    MAXN = 10010,
    MAXLOG = 25;

struct suffix {
	int f[2], idx;
	
	suffix ( int a = 0, int b = 0, int c = 0 ) {
		f[0] = a; f[1] = b; idx = c;
	}
	
	bool operator < ( const suffix &other ) const {
		return ( f[0] != other.f[0] ) ? f[0] < other.f[0] : f[1] < other.f[1];
	}
	
	bool operator == ( const suffix &other ) const {
		return f[0] == other.f[0] && f[1] == other.f[1];
	}
};

int N;
int i, j, cnt;
char S[MAXN];
int P[MAXLOG][MAXN];
suffix L[MAXN];

int main() {

	scanf( "%s", S + 1 );
	N = strlen( S + 1 );
    
	for ( i = 1; i <= N; i++ ) {
		P[0][i] = S[i] - 'a';
	}
	
	cnt = 1;
	for ( i = 1; cnt / 2 <= N; i++, cnt *= 2 ) {
		
		for ( j = 1; j <= N; j++ )
			L[j] = suffix( P[i - 1][j], ( j + cnt <= N ) ? P[i - 1][j + cnt] : -1, j );
		
		sort( L + 1, L + N + 1 );
		
		for ( j = 1; j <= N; j++ )
			P[i][L[j].idx] = ( j > 1 && L[j] == L[j - 1] ) ? P[i][L[j - 1].idx] : j;
	
	}
	
	for ( j = 1; j <= N; j++ ) {
		printf( "%d ", P[i - 1][j] );	
	}
	
	printf( "\n" );
    fflush( stdout );
    return 0;
}
