/*
  Reinier César Mujica
  12 - 12 - 2008
*/

#include <cstdio>

using namespace std;

int N, T, sol;

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &N );
		
		sol = 0;
		while ( N ) {
			sol += ( N / 5 );
			N /= 5;
		}
		
		printf( "%d\n", sol );
	}
	
	return 0;
}
