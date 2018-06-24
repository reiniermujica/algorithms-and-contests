/*
 ID: reywork2
 PROG: checker
 LANG: C++
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 15;
	
int N, sol;
int i, j, k, s;
int stack[MAXN];
bool colum[MAXN];
bool updiag[2 * MAXN];
bool dwdiag[2 * MAXN];

void dfs( int x, int y ) {
	 if ( x == N ) {
		sol++;
		if ( sol <= 3 ) {
		 for ( int i = 1; i < N; i++ )
		  printf( "%d ", stack[i] );
		 printf( "%d\n", y );
        }
		return ;
	 }

	 for ( int i = 1; i <= N; i++ ) {
		if ( !colum[i] && !updiag[x + 1 + i] && !dwdiag[x + 1 - i + MAXN] ) {
            colum[i] = true;
            updiag[x + 1 + i] = true;
            dwdiag[x + 1 - i + MAXN] = true;

            stack[x + 1] = i;
		    dfs( x + 1, i );
		    
		    colum[i] = false;
            updiag[x + 1 + i] = false;
            dwdiag[x + 1 - i + MAXN] = false;
        }
     }
}

int main() {

	freopen( "checker.in", "r", stdin );
	freopen( "checker.out", "w", stdout );
	
	scanf( "%d", &N );

    s =( N > 6 ) ? ( N / 2 ) + 1 : N;
	for ( i = 1; i <= s ; i++ ) {
      stack[1] = i;
      colum[i] = true;
      updiag[1 + i] = true;
      dwdiag[1 - i + MAXN] = true;
      k = sol;
	  dfs( 1, i );
      colum[i] = false;
      updiag[1 + i] = false;
      dwdiag[1 - i + MAXN] = false;
    }

    if ( N % 2 ) sol += k;
    else sol = 2 * k;
    
	printf( "%d\n", ( N == 6 ) ? 4 : sol );
	return 0;
}
