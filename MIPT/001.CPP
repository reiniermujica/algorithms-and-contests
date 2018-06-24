#include <cstdio>

using namespace std;

int N, m = - ( (1 << 30) + 1 );

int main() {
	
	while ( scanf( "%d", &N ) != EOF ) {
		m >?= N;
	}
	
	printf( "%d\n", m );
	return 0;
}


