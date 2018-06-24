#include <iostream>
#include <set>

using namespace std;

int N, M;
set < int > S, sol;

int main() {
	
	while ( 1 ) {
		cin >> N;
		if ( N == -1 ) break;
		S.insert( N );	
	}
	while ( 1 ) {
		cin >> N;
		if ( N == -1 ) break;
		if ( S.find( N ) != S.end() ) sol.insert( N );
	}

	if ( sol.empty() ) cout << "empty" << endl;
	else
    while ( !sol.empty() ) {
        printf( "%d ", ( *sol.begin() ) );
        sol.erase( sol.begin() );
    }

	cout << endl;
	return 0;
}
