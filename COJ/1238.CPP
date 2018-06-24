#include <iostream>
#include <string>


using namespace std;

int i, j, sol;
string line;
int fact[10];

int main()
{
    /* precalc */
    fact[1] = 1;
    for ( i = 2; i < 10; i++ )
        fact[i] = fact[i - 1] * i;
        
    while ( true )
    {
          cin >> line;
          if ( line == "0" ) break;
          
          sol = j = 0;
          for ( i = line.size(); i; i-- )
          {
              sol += ( line[j] - '0' ) * fact[i];
              j++;
          }
          
          cout << sol << endl;
    }

    return 0;
}
