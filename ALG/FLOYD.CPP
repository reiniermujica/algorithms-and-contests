/*

*/

#include <cstdio>

using namespace std;

int main() {

	/* Floyd */
	for ( k = 1; k <= N; k++ )
		for ( i = 1; i <= N; i++ ) 
			for ( j = 1; j <= N; j++ )
				cost[i][j] <?= cost[i][k] + cost[k][j];
							
	return 0;				
}
