#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int i, j, sol;
bool mark[105];

int main()
{
    cin >> T;
    while ( T-- )
    {
          cin >> N;
          
          fill( mark, mark + 105, true );
          
          for ( i = 1; i <= N; i++ )
          {
              for ( j = i; j <= N; j += i )
                  mark[j] = !mark[j];
          }
          
          sol = 0;
          for ( i = 1; i <= N; i++ )
              if ( !mark[i] ) sol++;
          
          cout << sol << endl;
    }

    return 0;
}
