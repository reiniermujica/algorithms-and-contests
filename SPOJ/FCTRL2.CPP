/*
 Reinier César Mujica
 12 - 12 - 2008
 Daddy Heart Hot Time...
*/

#include <cstdio>

using namespace std;

const int
	MAXN = 200;
	
int N, T;
int i, j, k, cc;
int c, carry, p, num;
int cant, t;
int fct[MAXN][MAXN], len[MAXN];

int main() {

	fct[1][1] = len[1] = 1;
	for ( i = 2; i <= 100; i++ ) {
        len[i] = len[i - 1]; carry = 0;

        for ( j = 1; j <= len[i]; j++ ) {
            k = fct[i - 1][j] * i + carry;
            fct[i][j] = k % 10;
            carry = k / 10;
        }
        
        while ( carry ) {
            fct[i][++len[i]] = carry % 10;
            carry /= 10;
        }
	}
	
	scanf( "%d\n", &T );
	for ( i = 0; i < T; i++ ) {
		scanf( "%d", &N );
		for ( j = len[N]; j > 0; j-- )
            printf( "%d", fct[N][j] );
        printf( "\n" );
	}

	return 0;
}
