#include <iostream>

using namespace std;

int a, b;

int main()
{
    cin >> a >> b;
    while ( a != 0 || b != 0 )
    {
          cout << a + b << endl;
          cin >> a >> b;
    }

    return 0;
}
