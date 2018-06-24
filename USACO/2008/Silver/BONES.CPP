/*
 PROG: bones
 LANG: C++
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 21,
	MAXK = 41;
	
int s1, s2, s3, sol;
int i, j, k;
int msum = 0;
int cant[MAXN * MAXN * MAXK];

int main() {

	freopen( "bones.in", "r", stdin );
	freopen( "bones.out", "w", stdout );
	
	scanf( "%d %d %d", &s1, &s2, &s3 );
	for ( i = 1; i <= s1; i++ )
	 for ( j = 1; j <= s2; j++ )
	  for ( k = 1; k <= s3; k++ ) {
		int sum = i + j + k;
		msum >?= sum;
		cant[sum]++;
	  }
	
	for ( i = 1; i <= msum; i++ ) {
		if ( cant[i] > cant[sol] ) sol = i;
	}

	printf( "%d\n", sol );
	return 0;
}
