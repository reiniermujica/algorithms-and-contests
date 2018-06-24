/*
 Reinier César Mujica
 17 - 11 - 2008
*/

#include <iostream>

using namespace std;

typedef long long int64;

const int
    MAXN = 1000005;

int N, i;
int dp[MAXN];

int64 dfs( int x ) {
	if ( x < MAXN ) return dp[x];
	return x >? ( dfs( x / 2 ) + dfs( x / 3 ) + dfs( x / 4 ) );
}

int main() {
	
	/* pre calc */
	for ( i = 1; i < MAXN; i++ )
        dp[i] = i >? ( dp[i / 2] + dp[i / 3] + dp[i / 4] );
        
	while ( cin >> N )
		cout << dfs( N ) << endl;
	
	fflush( stdout );
	return 0;
}
