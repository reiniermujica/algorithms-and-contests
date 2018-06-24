/*
 Reinier César Mujica
 29 - 12 - 2008
*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int64
	SIGN[4][2] = { {-1,0} , {0,1}, {1,0}, {0,-1} };

int64 N, M, L;
int64 x, y, z, dir;
int64 amount;

int main() {

	freopen( "SPIRAL.IN", "r", stdin );
	freopen( "SPIRAL.OUT", "w", stdout );
	
	scanf( "%lld %lld", &x, &y );
	scanf( "%lld", &L );
	
	dir = 0; z = 1;
	while ( L > 0 ) {
        amount = min( L, z );
    	y += SIGN[dir][0] * amount;
		x += SIGN[dir][1] * amount;
		L -= amount;
		dir = ( dir + 1 ) % 4;
		z++;
	}

	printf( "%lld %lld\n", x, y );
	return 0;
}
