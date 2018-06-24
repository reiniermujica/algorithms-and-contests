/*
    Eulerian Path
    undirected graph
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int 
    MAXN = 1001;
    
int N, M;
int u, v;
int i, j, k;
vector < int > G[MAXN];
vector < int > :: iterator it;
stack < int > path;

void dfs( int node )
{
    if ( G[node].size() == 0 )
        path.push( node );
    else
    {
        while ( G[node].size() )
        {
            int next = G[node][G[node].size() - 1];
            G[node].pop_back();

            //delete back edge
            it = lower_bound( G[next].begin(), G[next].end(), node );
            G[next].erase(it);

            dfs( next );
        }
        path.push( node );
    }
    
    return ;
}

int main()
{
    cin >> N >> M;
    for ( i = 0; i < M; i++ )
    {
        cin >> u >> v;
        G[u].push_back( v );    
        G[v].push_back( u );
    }
    
    for ( i = 1; i <= N; i++ )
        sort( G[i].begin(), G[i].end() );
        
    dfs(1);
        
    while ( !path.empty() )
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
    
    return 0;
}
