/*

*/

#include <iostream>

using namespace std;

int T;
string a, b;

int main()
{
	cin >> T;
	while ( T-- )
	{
		cin >> a >> b;
		if ( a != b )
			cout << "ERROR" << endl;
		else
			cout << "OK" << endl;	
	}
	
	return 0;
}
