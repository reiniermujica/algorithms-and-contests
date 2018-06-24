/*
ID: reywork2
PROG: frac1
LANG: C++
*/

/* more fastest */

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 161;
	
typedef double real;

struct fr {
    int n, d;
    
    fr( int a = 0, int b = 0 ) {
        n = a; d = b;
    }
    
    bool operator < ( const fr &other ) const {
         real c1 = (real) n / d;
         real c2 = (real)other.n / other.d;
         return c1 < c2;
    }
} T[MAXN * MAXN];

int N, i, j, sol;
bool num, den;

int gcd1( int n1, int n2 ) {
    if ( !n2 ) return n1;
    return gcd1( n2, n1 % n2 );
}

int gcd( fr a ) {
    if ( a.n == 0 && !num ) {
        num = true;
        return 1;
    }
    if ( a.d == 0 && !den ) {
        den = true;
        return 1;
    }
    return gcd1( a.n, a.d );
}

int main() {

	freopen( "frac1.in", "r", stdin );
	freopen( "frac1.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) 
		for ( j = 0; j < MAXN; j++ ) {
			double res = (double) j / i;
			if ( res >= 0. && res <= 1. && gcd( fr( j, i ) ) == 1 ) {
			 T[++sol] = fr ( j, i );
            }
		}
	
    sort( T + 1, T + sol + 1 );
    for ( i = 1; i <= sol; i++ )
     printf( "%d/%d\n", T[i].n, T[i].d );
     
	return 0;
}
