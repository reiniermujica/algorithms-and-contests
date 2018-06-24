#include <iostream>
#define MAXN 1050

using namespace std;

int N, K, sol;
int i, j, k;
bool mark[MAXN];

int main() {
	
	cin >> N >> K;
	for ( i = 2; i <= N; i++ ) {
		if ( !mark[i] ) { 
			mark[i] = true;
			k++;
			if ( k == K ) {
				sol = i;
				break;
			}
			for ( j = i; j <= N; j += i )
				if ( !mark[j] ) {
					mark[j] = true;
					k++;
					if ( k == K ) {
						sol = j;
						break;
					}
				}
		}
	}
	
	cout << sol << endl;
	return 0;
}
