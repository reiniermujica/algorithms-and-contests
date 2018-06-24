/*
 Reinier César Mujica
 22 - 12 - 2008
 test 2 fail to chance ?
*/

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int
	MAXN = 10500;
	
int N, M, sol;
int i, j, k;
string s1, s2, s3;
char c1, c2;
char T[MAXN];

int main() {

	freopen( "SUFIB.IN", "r", stdin );
	freopen( "SUFIB.OUT", "w", stdout );
	
	scanf( "%c\n", &c1 );
	scanf( "%c\n", &c2 );
	
	scanf( "%d\n", &N );
	for ( i = 1; i <= N; i++ )
		scanf( "%c\n", &T[i] );
	
	s1 = c1; s2 = c2;  k = 2;
	while ( true ) {
		k++;
		s3 = s2 + s1;
		s1 = s2; s2 = s3;
		M = s3.size();
		if ( M > N ) break;
		
		for ( i = N - M + 1, j = 0; i <= N; i++, j++ )
			if ( s3[j] != T[i] ) break;
		
		if ( i == N + 1 )
			sol = k;
	}

	printf( "%d\n", sol );
	return 0;
}
