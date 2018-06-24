/*

*/

#include <iostream>

using namespace std;

int N, sol, i;
int a, b, c;
string s1 = "ABC", s2 = "BABC", s3 = "CCAABB", s;

int main() {
	
	cin >> N;
	cin >> s;

    for ( i = 1; s1.size() <= 100; i++ ) {
        s1 += s1;
        s2 += s2;
        s3 += s3;
    }
    
	for ( i = 0; i < N; i++ ) {
        if ( s[i] == s1[i] ) a++;
        if ( s[i] == s2[i] ) b++;
        if ( s[i] == s3[i] ) c++;
	}
	
	sol = a >? b >? c;
	cout << sol << endl;
	if ( a == sol ) cout << "Adrian" << endl;
	if ( b == sol ) cout << "Bruno" << endl;
	if ( c == sol ) cout << "Goran" << endl;

	return 0;
}
