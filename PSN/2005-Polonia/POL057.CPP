/*
 Reinier César Mujica
 7/4/08  PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int
      mv = 1002,
      mc = 202,
      oo = 1<<28;
       
typedef pair <int,int> par;

int n,m,e,b[mc],c[mc],d[mc][mv],sol=oo,s1,s2;
vector < int > G[mv];
priority_queue < par,vector <par>, greater <par> > Q;

void dijkstra(int v){
     int i;
     fill(d[v],d[v]+mv,oo);
     d[v][c[v]]=0; Q.push(make_pair(0,c[v]));
     while (!Q.empty()){
      int node = Q.top().second;
      int cost = Q.top().first;
      Q.pop();
      for (i=0; i<G[node].size(); i++){
          int nex = G[node][i];
          if (d[v][nex] > cost + 1){
           d[v][nex]=cost + 1;    
           Q.push(make_pair(d[v][nex],nex));
          }
      }       
     }
}

int main(){
    int i,j,k,x,y;
    freopen("nevenka.in","r",stdin);
    freopen("nevenka.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&e);
    scanf("%d",&c[0]);
    for (i=1; i<=c[0]; i++){
      scanf("%d",&c[i]);    
    }
    scanf("%d",&b[0]);
    for (i=1; i<=b[0]; i++){
      scanf("%d",&b[i]);    
    }
    scanf("%d",&m);
    for (i=0; i<m; i++){
      scanf("%d%d",&x,&y);
      G[x].push_back(y);
      G[y].push_back(x);    
    }
    for (i=1; i<=c[0]; i++) dijkstra(i); 
    int mn,maxc;
    for (i=1; i<=b[0]-1; i++)
     for (j=i+1; j<=b[0]; j++){
      maxc=0;
      for (k=1; k<=c[0]; k++){
       mn=min(d[k][b[i]],d[k][b[j]]);    
       maxc>?=mn - d[k][e];
      } 
      if (maxc < sol){
         sol = maxc;
         s1=b[i]; s2=b[j];                 
      }
     }
    if (s1 > s2) swap(s1,s2);
    printf("%d %d\n",s1,s2);
    return 0;    
}
