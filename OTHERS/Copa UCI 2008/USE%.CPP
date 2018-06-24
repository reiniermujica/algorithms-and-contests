/*
 Reinier Cesar Mujica
 2/06/08
 "Utilizando %"
*/

#include <iostream>
#include <string>

using namespace std;

int i, j;
char c[81];

int main() {

    while ( 1 ) {
     gets( c );
     if ( c[0] == '#' ) break;
     for ( i = 0; i < strlen( c ); i++ ) {
        switch ( c[i] )  {
          case ' ' : cout << "%20"; break;
          case '!' : cout << "%21"; break;
          case '$' : cout << "%24"; break;
          case '%' : cout << "%25"; break;
          case '(' : cout << "%28"; break;
          case ')' : cout << "%29"; break;
          case '*' : cout << "%2a"; break;
          default : cout << c[i]; break;
        }
     }
     cout << '\n';
    }
    
    fflush( stdout );
    return 0;
}
