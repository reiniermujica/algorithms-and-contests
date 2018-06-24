#include <iostream>

using namespace std;

long long N, s;

int main()
{
    cin >> N;
    if ( N < 0 )
    {
         N *= -1;    
         s = ( N * ( N + 1 ) ) / (long long)2;
         s--;
         cout <<  -1 * s << endl;        
    }
    else
    {
        s = ( N * ( N + 1 ) ) / (long long)2;
        cout << s << endl;
    }
}
