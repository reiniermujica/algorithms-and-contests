/*
 Reinier Cesar Mujica
 17/06/2008
 "ABC"
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int
    MAXN = 5;

int N[MAXN];
string D;

int main() {

    cin >> N[0] >> N[1] >> N[2];
    sort( &N[0], &N[3] );
    
    cin >> D;
    for ( int i = 0; i < 3; i++ )
     cout << N[D[i] - 'A'] << ' ';
    
    cout << '\n';
    
    fflush( stdout );
    return 0;
}
