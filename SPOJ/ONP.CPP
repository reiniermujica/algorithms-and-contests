/*
 Reinier César Mujica
 13 - 11 - 2008
*/

#include <iostream>
#include <stack>

using namespace std;

const int
	MAXN = 405;
	
bool isletter( char a ) {
     if ( a > 96 && a < 123 ) return true;
	 return false;
}

int N, T;
int i;
char cad[MAXN]; 

int main() {
	
	scanf( "%d\n", &T );
	while ( T-- ) {
		gets( cad );
		N = strlen( cad );
        stack < char > sign;
		for ( i = 0; i < N; i++ ) {
            if ( cad[i] == '(' ) continue;
			if ( isletter( cad[i] ) ) {
				cout << cad[i];
				continue;
			}
			if ( cad[i] == ')' ) {
				cout << sign.top();
				sign.pop();
				continue;
			}
		    sign.push( cad[i] );
		}
     cout << endl;
    }
	
	return 0;
}
