/*

*/

#include <iostream>

using namespace std;

int a, b, c;

int main() {
	
	cin >> a >> b >> c;
	
	cout << int ( ( b - a - 1 ) >? ( c - b - 1 ) ) << endl;

	return 0;
}
