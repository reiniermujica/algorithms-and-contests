#include <iostream>
#define MAXN 15

using namespace std;

int N, sol = 1 << 30;
int T[MAXN][2];
int i, j, k, c;
bool ok;

int main() {

	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ )
	 cin >> T[i][0] >> T[i][1];
	 
	for ( i = 1; i < ( 1 << N ); i++ ) {
		
		c = 1; k = 0; ok = false;
		for ( j = 1; j <= N; j++ )
		 if ( i & ( 1 << ( j - 1 ) ) ) {
			c *= T[j][0];
			k += T[j][1];
			ok = true;
		 }
		if ( ok ) sol <?= abs( c - k );
	}
	
	cout << sol << endl;
	return 0;
}
