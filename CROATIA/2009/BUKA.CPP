/*
 Reinier César Mujica
 12 - 3 - 2009
*/

#include <iostream>
#include <string>

using namespace std;

int i, j, k;
string a, b;
char op;

int main() {

	cin >> a;
	cin >> op;
	cin >> b;
	
	if ( op == '+' ) {
		if ( a < b ) {
			b[b.size() - a.size()] = '1';
			cout << b << endl;
		}
		else 
		if ( a > b ) {
			a[a.size() - b.size()] = '1';
			cout << a << endl;
		}
		else {
			a[0] = '2';
			cout << a << endl;
		}
	}
	else {
		k = count( a.begin(), a.end(), '0' );
		for ( i = 1; i <= k; i++ )
			b.push_back( '0' );
		cout << b << endl;
	}

    fflush( stdout );
	return 0;
}
