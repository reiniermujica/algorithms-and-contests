#include <cstdio>

using namespace std;

int V, T;

int main()
{
    while ( scanf( "%d %d", &V, &T ) != EOF )
    {
          printf( "%d\n", V * ( T << 1 ) );
    }

    return 0;
}
