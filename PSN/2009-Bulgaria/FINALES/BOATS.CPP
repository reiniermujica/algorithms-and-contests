/*
 Reinier César Mujica
 20 - 4 - 2009
 DP + Binary Search
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 10005;
	
struct ship {
	int pos, len;
	bool operator < ( const ship &other ) const {
		return pos < other.pos;
	}
} T[MAXN];

int N, sol = 1;
int i;
int dp[MAXN];

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%d %d", &T[i].len, &T[i].pos );

	sort( T + 1, T + N + 1 );
	
	dp[1] = T[1].pos;
	for ( i = 2; i <= N; i++ ) {
		int low = upper_bound( dp + 1, dp + sol + 1, T[i].pos ) - dp;
		int cos = ( dp[low - 1] + T[i].len ) >? T[i].pos;

		if ( !dp[low] || dp[low] > cos )
			dp[low] = cos;
			
		if ( low - 1 == sol ) sol++;
	}
	
	printf( "%d\n", sol );
	return 0;
}
