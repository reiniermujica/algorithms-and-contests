#include <cstdio>
#include <string>

using namespace std;

int N;
double M, H;
int i;
string macho, hembra;
char temp[15];
char ch;

int main()
{
    scanf( "%d", &N );
    while ( N != 0 )
    {
        M = H = 0.0;
        
        for ( i = 0; i < N; i++ )
        {
            double a, b, c;
            
            scanf( "%s %c %lf %lf", temp, &ch, &a, &b );
            
            c = 100.0 - ( b * 100.0 / a );
            if ( ch == 'M' )
            {
                if ( c > M )
                {
                    M = c;
                    macho = temp;                
                }            
            }
            else
            {
                if ( c > H )
                {
                    H = c;
                    hembra = temp;                
                }            
            }        
        }
    
        printf( "%s %.2lf%% %s %.2lf%%\n", macho.c_str(), M, hembra.c_str(), H );
        
        scanf( "%d", &N );
    }
    
    return 0;
}
