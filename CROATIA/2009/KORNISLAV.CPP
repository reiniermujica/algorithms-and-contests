#include <iostream>

using namespace std;

int T[4];

int main() {
	
	cin >> T[0] >> T[1] >> T[2] >> T[3];
	sort( T, T + 4 );
	cout << T[0] * T[2] << endl;
	return 0;
}
