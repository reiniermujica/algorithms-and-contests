/*
 Reinier Cesar Mujica
 17/06/2008
 "SJECISTA"
*/

#include <iostream>

using namespace std;

long long N;

int main() {

    cin >> N;
    
    cout << (N * (N-1) * (N-2) * (N-3)) / 24 << endl;

    fflush( stdout );
    return 0;
}
