/*
 Reinier César Mujica
 8 - 1 - 2009
 A little speed optimization whit *= 2
 an expected to get full points
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct xxx {
	int cant;
	bool kind;
	xxx( int a = 0, bool b = false ) {
		cant = a;
		kind = b;
	}
};

int N, M, sol = 0;
int i, j, k, lo;
bool ok = false;
vector < xxx > S;

int main() {

	freopen( "ACROBAT.IN", "r", stdin );
	freopen( "ACROBAT.OUT", "w", stdout );
	
	scanf( "%d %d", &N, &M );
	
	while ( true ) {
		if ( k == 0 && ok ) break;
		
		if ( k >= M ) {
			lo = k / M;
			S.push_back( xxx( lo, false ) );
			k -= lo * M;
		} else {
            lo = 1;
    		while ( (N * lo) + k < M ) lo *= 2;
    		lo--;
    		while ( (N * lo) + k < M ) lo++;
			k += ( N * lo );
			S.push_back( xxx( lo, true ) );
		}
		sol >?= k;
		ok = true;
	}
		
	printf( "%d\n", sol );
    for ( i = 0; i < S.size(); i++ ) {
        char c = ( S[i].kind ) ? '+' : '-';
        for ( j = 0; j < S[i].cant; j++ )
            printf( "%c", c );
    }

    fflush( stdout );
	return 0;
}
