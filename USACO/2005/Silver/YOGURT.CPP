/*
 Reinier César Mujica
 10-10-2008
 Greedy
*/

#include <iostream>

using namespace std;

const int
	MAXN = 100010;

struct day {
	int cost, cant;
} L[MAXN];
	
int N, S;
int i, j, k;
long long sol;

int main() {

	freopen( "yogurt.in", "r", stdin );
	freopen( "yogurt.out", "w", stdout );
	
	scanf( "%d %d", &N, &S );
	for ( i = 1; i <= N; i++ )
	  scanf( "%d %d", &L[i].cost, &L[i].cant );
	
	for ( i = 1; i <= N; i++ ) {
		L[i].cant -= k;
		j = ( L[i].cant + L[i + 1].cant ) * L[i].cost +
			( L[i + 1].cant * S );
		
		int c1 = L[i].cant * L[i].cost;
		int c2 = c1 + ( L[i + 1].cant * L[i + 1].cost );
		
		if ( j < c2 ) {
			k = L[i + 1].cant;
			sol += j;
		}
		else {
			k = 0;
			sol += c1;
		}
	}
	
	cout << sol << endl;
	return 0;
}
