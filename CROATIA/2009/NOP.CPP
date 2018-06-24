/*
 Reinier César Mujica
 5 - 3 - 2009
*/

#include <iostream>
#include <string>

using namespace std;

int sol;
int i, j, k;
int pot[1050];
string s;

int main() {
	
	for ( i = 4, j = 0; j <= 1000; j++, i += 4 )
        pot[j] = i;

	cin >> s;
	
	for ( i = 1, j = 1, k = 0; i < s.size(); ) {
		if ( s[i] >= 'a' && s[i] <= 'z' ) {
			i++;
			if ( j + 1 == pot[k] ) {
                j++;
                k++;
            } else j++;
		}
		else {
			if ( j % 4 == 0 ) {
				i++;
				j++;
			}
			else {
				sol += pot[k] - j;
				j = pot[k] + 1; k++;
				i++;
			}
		}
    }

	cout << sol << endl;
	return 0;
}
