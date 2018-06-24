#include <iostream>

using namespace std;

#define LL long long

LL T, N, sol;
LL i, j;

int main()
{
    cin >> T;
    while ( T-- )
    {
        cin >> N;
        
        sol = 0;
        for ( i = 0; i < 64; i++ )
            if ( N & ( 1 << i ) )
            {
                sol = 1 << i;
                break;
            }
        
        cout << sol << endl;
    }
    
    return 0;
}
