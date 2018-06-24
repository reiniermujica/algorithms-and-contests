/*
ID: reywork2
PROG: frac1
LANG: C++
*/

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
bool mark[MAXN][MAXN];

void frac( fr a ) {
     int i, j, k;
     mark[a.n][a.d] = true;
     for ( i = 2; i * a.n < MAXN, i * a.d < MAXN; i++ ) {
        int x = a.n, y = a.d;
        while ( x * i < MAXN && y * i < MAXN ) {
            x *= i; y *= i;
            mark[x][y] = true;
        }
     }
}

int main() {

	freopen( "frac1.in", "r", stdin );
	freopen( "frac1.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) 
		for ( j = 0; j < MAXN; j++ ) {
			double res = (double) j / i;
			if ( res >= 0. && res <= 1. && !mark[j][i] ) {
			 T[++sol] = fr ( j, i );
             frac( T[sol] );
            }
		}
	
    sort( T + 1, T + sol + 1 );
    for ( i = 1; i <= sol; i++ )
     printf( "%d/%d\n", T[i].n, T[i].d );
     
	return 0;
}
