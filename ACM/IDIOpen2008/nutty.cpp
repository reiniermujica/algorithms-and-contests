/*
    Reinier César Mujica Hdez
    xx-09-2011
*/

#include <cstdio>

using namespace std;

int T;
int d, n, s, p;

int main()
{
    scanf( "%d", &T );
    while ( T-- )
    {
	   scanf( "%d %d %d %d", &d, &n, &s, &p );
	
	   int serial = n * s;
	   int paralell = d + ( n * p );
	
	   if ( serial < paralell )
	   	   printf( "do not parallelize\n" );
       if ( serial > paralell )
           printf( "parallelize\n" );
       if ( serial == paralell )
           printf( "does not matter\n" );
    }
    
	return 0;
}
