#include <iostream>

using namespace std;

int N, T;
int i, k;

int main()
{
    cin >> T;
    while ( T-- )
    {
          cin >> N;
          int sum = 0;
          
          for ( i = 1; i <= N; i++ )
          {
              cin >> k;
              sum = sum + k;
          }

          if ( sum % N == 0 )
            cout << "YES" << endl;
          else
            cout << "NO" << endl;
    }

    return 0;
}
