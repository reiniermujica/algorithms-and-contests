/*
 Reinier César Mujica
 28/3/08 PSN - 2008
*/

#include <cstdio>
#include <vector>

using namespace std;

const int
      mx = 1002;

int n,act=0,low[mx];
bool mk[mx];
vector <int> G[mx];

int dfs(int v){
    int i,k,min;
    act++; low[v]=act; min=act;
    for (i=0; i<G[v].size(); i++)
     if (low[G[v][i]] == 0){
        k=dfs(G[v][i]);
        if (k >= low[v])
           mk[v]=true;
        min<?=k;               
     }    
     else
      min<?=low[G[v][i]];
    return min;
}

int main(){
    int i,x,y;
    freopen("camino.ent","r",stdin);
    freopen("camino.sal","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);    
    }
    dfs(1);
    for (i=2; i<mx; i++) 
     if (mk[i]) printf("%d\n",i);
    fflush(stdout);
    return 0;    
}
