#include <iostream>
#include <string>

using namespace std;

int i, sol;
double V[256];
string line;

int main()
{
    /* const */
    V['W'] = 1;
    V['H'] = 0.5;
    V['Q'] = 0.25;
    V['E'] = 0.125;
    V['S'] = 0.0625;
    V['T'] = 0.03125;
    V['X'] = 0.015625;
        
    while ( true )
    {
          cin >> line;
          if ( line == "*" ) break;
          
          double sum = 0.0;
          sol = 0;
          
          for ( i = 1; i < line.size(); i++ )
          {
              if ( line[i] == '/' ) 
              {
                   if ( sum == 1.00 )
                      sol++;
                   sum = 0.0;                
              }
              else
                  sum = sum + V[line[i]];
          }

          cout << sol << endl;
    }

    return 0;
}
