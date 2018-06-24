#include <iostream>

using namespace std;

long long A, B, res;

int main() {

    while ( cin >> A >> B ) {
        res = B - A;
        if ( res < 0 ) res *= -1;
        cout << res << endl;
    }
    
    fflush( stdout );
    return 0;
}
