#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 10002

int N, E, T;
int i, j, k;
int u, v;
int dc_time;
int cant;
int low[MAXN];
int dfsnum[MAXN];
int C[MAXN];
bool del[MAXN];
bool markn[MAXN];
bool markc[MAXN];
bool can[MAXN];
vector < int > G[MAXN];
stack< int > S;
queue < int > Q;

void dfs(int node, int father)
{
    dfsnum[node] = low[node] = ++dc_time;
    S.push( node );
    
    for ( int i = 0; i < G[node].size(); i++ )
    {
        int next = G[node][i];
        if ( next == father ) continue;
        if ( !low[next] )
        {
             dfs( next, node );
             low[node] = min( low[node], low[next] );
        }
        else
        if ( !del[next] )
           low[node] = min( low[node], low[next] );         
    }
    
    if ( low[node] == dfsnum[node] )
    {
         ++cant;
         while ( !del[node] )
         {
               C[S.top()] = cant;
               del[S.top()] = true;
               S.pop();                   
         }
    }
    
    return ;
}

int main()
{
    scanf( "%d %d %d", &N, &E, &T );
    while ( N != 0 || E != 0 || T != 0 )
    {
          /* filling */
          fill( low, low + MAXN, 0 );
          fill( dfsnum, dfsnum + MAXN, 0 );
          fill( C, C + MAXN, 0 );
          fill( del, del + MAXN, false );
          for ( i = 0; i <= N; i++ )
              G[i].clear();
          dc_time = cant = 0;
                           
          for ( i = 0; i < E; i++ )
          {
              scanf( "%d %d", &u, &v );
              G[u].push_back( v );
              G[v].push_back( u );              
          }
          
          for ( i = 1; i <= N; i++ )
              if ( !low[i] ) 
                 dfs( i, -1 );
                 
          for ( j = 0; j < T; j++ )
          {
              scanf( "%d %d", &u, &v );
                            
              fill( markn, markn + MAXN, false );    
              fill( markc, markc + MAXN, false ); 
              fill( can, can + MAXN, false );    
              
              markn[u] = markc[C[u]] = can[u] = true;
              Q.push( u );
              while ( !Q.empty() )
              {
                    int node = Q.front();
                    Q.pop();      
                    
                    for ( i = 0; i < G[node].size(); i++ )
                    {
                        int next = G[node][i];
                        if ( !can[next] && !markn[next] && !markc[C[next]] )
                        {
                           markn[next] = true;
                           markc[C[next]] = true;
                           can[next] = true;
                           Q.push( next );
                        }                      
                    }                                        
              }              
              
              if ( can[v] ) printf( "Y\n" );
              else printf( "N\n" );
          }

          printf( "-\n" ); //fucking minus, I got WA twice becouse it
          scanf( "%d %d %d", &N, &E, &T );                
    }
    
    return 0;
}
