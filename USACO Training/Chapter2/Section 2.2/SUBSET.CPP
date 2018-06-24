/*
 ID: reywork2
 PROG: subset
 LANG: C++
*/

#include <cstdio>

using namespace std;

const int
	MAXS = 1650;
	
typedef unsigned int uE;

uE N, S;
uE i, j;
uE dp[MAXS];

int main() {
	
	freopen( "subset.in", "r", stdin );
	freopen( "subset.out", "w", stdout );
	
	scanf( "%d", &N );
	S = ( N * ( N + 1 ) ) / 2;
	if ( S % 2 ) {
		printf( "0\n" );
		return 0;
	}
	
	S /= 2;
	dp[0] = 1;
	for ( i = 1; i <= N; i++ ) {
		for ( j = S; j >= i; j-- )
			dp[j] += dp[j - i];
	}
	
	printf( "%u\n", dp[S] / 2 ); // %u means unsigned int
	return 0;
}
