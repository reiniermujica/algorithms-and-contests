#include <iostream>

using namespace std;

int N;
int i, k, sol;
bool mark[1005];

int main()
{
    for ( i = 1; i <= 10; i++ )
    {
        cin >> N;
        k = N % 42;
        if ( !mark[k] )
        {
             sol++;
             mark[k] = true;
        }
    }
    
    cout << sol << endl;

    return 0;
}
