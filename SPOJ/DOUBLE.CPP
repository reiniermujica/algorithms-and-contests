/*
 Reinier César Mujica
 9 - 11 - 2008
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 1005,
	MAXB = 305;
	
struct Bnumber {
	int lenght;
	int digit[MAXN + 1];
	Bnumber( int n = 0 ) { lenght = n; }
	bool operator < ( const Bnumber &other ) const {
		if ( lenght != other.lenght ) return lenght < other.lenght;
		for ( int i = lenght; i > 0; i-- )
			if ( digit[i] != other.digit[i] ) return digit[i] < other.digit[i];
		return false;
	}
	void add( int x ) { digit[++lenght] = x; }
} N, Best;

int T, B;
int i, k, carry;

int main() {
	
	scanf( "%d", &T );
	while ( T-- ) {

		scanf( "%d", &B ); Best = Bnumber( MAXN );
		for ( i = 1; i < B; i++ ) {
			k = i; carry = 0;
			N = Bnumber( 0 ); N.add( i );
			while ( 1 ) {
				k = 2 * k + carry;
				carry = k / B;
				k %= B;
				if ( carry == 0 && k == i ) break;
				N.add( k );
			}
			if ( N < Best ) Best = N;
        }

        for ( i = Best.lenght; i > 0; i-- )
		 printf( ( i == 1 ) ? "%d\n" : "%d ", Best.digit[i] );
	}

	fflush( stdout );
	return 0;
}
