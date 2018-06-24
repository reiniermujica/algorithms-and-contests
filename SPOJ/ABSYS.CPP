/*
 Reinier César Mujica
 03/07/2008
 "Anti-Blot System"
*/

#include <cstdio>
#include <cstring>

int cases, a, b, c;
char s1[20], s2[20], s3[20];

bool isin( char *a ) {
     if ( strstr( a, "machula" ) ) return 1;
     return 0;
}

int main() {

    scanf( "%d", &cases );
    
    while ( cases-- ) {
      scanf( "%s + %s = %s\n", &s1, &s2, &s3 );
      sscanf( s1, "%d", &a );
      sscanf( s2, "%d", &b );
      sscanf( s3, "%d", &c );
      if ( isin( s1 ) ) a = c - b;
      if ( isin( s2 ) ) b = c - a;
      if ( isin( s3 ) ) c = a + b;
      printf( "%d + %d = %d\n", a, b, c );
    }

    fflush( stdout );
    return 0;
}
