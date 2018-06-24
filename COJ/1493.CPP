#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

double circle( double r )
{
    return 3.14 * r * r;
}

double triangle( double a, double b )
{
    return ( a * b ) / 2.0;
}

string s;
double a, b, sol;

int main()
{
    cin >> s;
    if ( s == "circle" )
    {
       cin >> a;
       sol = circle( a );
    }    
    if ( s == "triangle" )
    {
       cin >> a >> b;
       sol = triangle( a, b );    
    }
    if ( s == "rhombus" )
    {
         cin >> a >> b;
         sol = triangle( a, b / 2.0 ) * 2.0;            
    }
    
    printf( "%.2lf\n", sol );
    return 0;
}
