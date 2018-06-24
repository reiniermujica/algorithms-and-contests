#include <iostream>

using namespace std;

int T, base, exp;
int last, k;
int dig[50];

int main() {

	cin >> T;
	while ( T-- ) {
		cin >> base >> exp;
		last = base %= 10; k = 0;
		do {
			dig[++k] = last;
			last = ( last * base ) % 10;
		} while ( last != base );
		dig[0] = dig[k];
        	last = ( exp ) ? dig[exp % k] : 1;
		cout << last << endl;
	}

	return 0;
}
