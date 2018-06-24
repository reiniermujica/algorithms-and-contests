/*
 Reinier César Mujica
 2/10/2008
 "Vacas Acróbatas"
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int	
	MAXN = 50010;
	
struct cow {
	int w, s;
};

bool cmp( const cow &a, const cow &b ) {
	 return a.w - b.s < b.w - a.s;
}

int N, sol = - ( 1 << 29 );
cow T[MAXN];
int i, k;
int sum;

int main() {

	freopen( "acrobat.in", "r", stdin );
	freopen( "acrobat.out", "w", stdout );
	
	scanf( "%d", &N );
	for ( i = 1; i <= N; i++ ) 
		scanf( "%d %d", &T[i].w, &T[i].s );
		
	sort( T + 1, T + N + 1, cmp );
	for ( i = 1; i <= N; i++ ) {
		sol >?= sum - T[i].s;
		sum += T[i].w;
	}
	
	printf( "%d\n", sol );
	return 0;
}
