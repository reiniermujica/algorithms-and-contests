#include <iostream>

using namespace std;

int A, B, X, Y;

int ext_euclid( int a, int b, int &x, int &y )
{
    int x1 = 0, y1 = 0;

    if ( b == 0 )
    {
        x = 1; y = 0;
        return a;
    }
    else
    {
        int d = ext_euclid(b, a % b, x1, y1 );
        x = y1;
        y = x1 - (a / b) * (y1);
        return d;
    }
}

int main()
{
    while ( cin >> A >> B )
    {
        cout << "GCD = " << ext_euclid( A, B, X, Y ) << " X = " << X << " Y = " << Y << endl;
    }
    
    return 0;
}

