/*
 Reinier César Mujica
 5 - 3 - 2009
 Be sure to check '+' first
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int
	MAXN = 55;
	
int N, M;
int i, j, k;
char T[MAXN][MAXN];

void force( int a, int b, char c ) {
	 printf( "%d %d %c\n", a, b, c );
	 exit( 0 );
}

int main() {

	scanf( "%d %d\n", &N, &M );
	for ( i = 1; i <= N; i++ ) {
		gets( T[i] + 1 );
	}
	
	for ( i = 1; i <= N; i++ ) {
		for ( j = 1; j <= M; j++ ) {
			if ( T[i][j] != '.' ) continue;
			for ( k = 1; k <= 7; k++ ) {
				int x1, y1, x2, y2;
				char a, b;
				if ( k == 3 ) {
					a = T[i - 1][j];
					b = T[i + 1][j];
					if ( a == 'Z' || a == 'M' || a == '|' || a == '+' ||
						 a == '1' || a == '4' ) {
						if ( b == 'Z' || b == 'M' || b == '|' || b == '+' ||
							b == '2' || b == '3' ) {
							force( i, j, '|' );
						}
						else continue;
					} else continue;
				}
				if ( k == 2 ) {
					a = T[i][j - 1];
					b = T[i][j + 1];
					if ( a == 'Z' || a == 'M' || a == '-' || a == '+' ||
						 a == '1' || a == '2' ) {
						if ( b == 'Z' || b == 'M' || b == '-' || b == '+' ||
							b == '3' || b == '4' ) {
							force( i, j, '-' );
						}
						else continue;
					} else continue;
				}
				if ( k == 1 ) {
					a = T[i - 1][j];
					b = T[i][j + 1];
					char c = T[i + 1][j], d = T[i][j - 1];
					if ( a == 'Z' || a == 'M' || a == '|' || a == '+' ||
						 a == '1' || a == '4' ) {
						if ( b == 'Z' || b == 'M' || b == '-' || b == '+' ||
							b == '3' || b == '4' ) {
							if ( c == 'Z' || c == 'M' || c == '|' || c == '+' ||
							     c == '2' || c == '3' ) {
								if ( d == 'Z' || d == 'M' || d == '-' || d == '+' ||
									d == '1' || d == '2' ) {
									force( i, j, '+' );
								} else continue;
							} else continue;
						}
						else continue;
					} else continue;
				}
				if ( k == 4 ) {
					a = T[i][j + 1];
					b = T[i + 1][j];
					if ( a == 'Z' || a == 'M' || a == '-' || a == '+' ||
						 a == '3' || a == '4' ) {
						if ( b == 'Z' || b == 'M' || b == '|' || b == '+' ||
							b == '2' || b == '3' ) {
							force( i, j, '1' );
						}
						else continue;
					} else continue;
				}
				if ( k == 5 ) {
					a = T[i - 1][j];
					b = T[i][j + 1];
					if ( a == 'Z' || a == 'M' || a == '|' || a == '+' ||
						 a == '1' || a == '4' ) {
						if ( b == 'Z' || b == 'M' || b == '-' || b == '+' ||
							b == '3' || b == '4' ) {
							force( i, j, '2' );
						}
						else continue;
					} else continue;
				}
				if ( k == 6 ) {
					a = T[i - 1][j];
					b = T[i][j - 1];
					if ( a == 'Z' || a == 'M' || a == '|' || a == '+' ||
						 a == '1' || a == '4' ) {
						if ( b == 'Z' || b == 'M' || b == '-' || b == '+' ||
							b == '1' || b == '2' ) {
							force( i, j, '3' );
						}
						else continue;
					} else continue;
				}
				if ( k == 7 ) {
					a = T[i][j - 1];
					b = T[i + 1][j];
					if ( a == 'Z' || a == 'M' || a == '-' || a == '+' ||
						 a == '1' || a == '2' ) {
						if ( b == 'Z' || b == 'M' || b == '|' || b == '+' ||
							b == '2' || b == '3' ) {
							force( i, j, '4' );
						}
						else continue;
					} else continue;
				}
			}
		}
	}
	
	return 0;
}
