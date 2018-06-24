#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int T, NG, NM;
int i, k;
int A, B;
bool win;
char line[10000000];
int top;
int size;

int nextInt()
{
    int n = (int)(line[top] - '0');
    top++;

	while (top < size && line[top] != ' ' && line[top] != '\n')
    {
		n *= 10;
        n += (int)(line[top] - '0');
		top++;
	}

    top++;
	return n;
}


int main()
{
    
    scanf( "%d", &T );
    while (T--)
    {
        win = false;
        priority_queue<int, vector<int>, greater<int> > G, M;
        
        scanf( "%d %d\n", &NG, &NM );
        gets( line );
        top = 0; size = strlen( line );
        for ( i = 0; i < NG; i++ )
        {
            k = nextInt();
            G.push( k );
        }
        
        gets( line );
        top = 0; size = strlen( line );
        for ( i = 0; i < NM; i++ )
        {
            k = nextInt();
            M.push( k );
        }
        
        A = G.top();
        G.pop();
            
        B = M.top();
        M.pop();
            
        while (win == false)
        {    
            while ( A >= B )
            {
                if ( M.size() == 0 )
                {
                    puts( "Godzilla" );
                    win = true;
                    break;
                }
                B = M.top();
                M.pop();
            }
            
            while ( A < B )
            {
                if ( G.size() == 0 )
                {
                    puts( "MechaGodzilla" );
                    win = true;
                    break;
                }
                A = G.top();
                G.pop();
            }   
        }
    }

    return 0;
}
