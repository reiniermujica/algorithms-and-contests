/*
 Reinier César Mujica
 2/4/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int
    mx = 30,
    mc = 1000,
    oo = 1<<29;
    
typedef pair <int,int> par;

int n,m,sol,c,p[3],d[mx];
char cad[mc];
bool mk[mx];
vector <par> G[mx];
priority_queue < par,vector <par>,greater<par> > Q;

int dijkstra(){
    int i,j,x;
    Q.push(make_pair(0,p[1]));
    while (!Q.empty()){
     int cost = Q.top().first;
     int node = Q.top().second;
     Q.pop();
     for (i=0; i<G[node].size(); i++){
      int next = G[node][i].second;
      int ncos = G[node][i].first;
      if (d[next] > cost + ncos){
       Q.push(make_pair(ncos + cost,next));
       d[next]=cost + ncos;
      }
     }
    }
    return d[p[2]];
}

int main(){
    int i,j,k,x,y;
    freopen("ruta.in","r",stdin);
    freopen("ruta.out","w",stdout);
    scanf("%s",&cad);
    while (strcmp(cad,"deadend") != 0){
     k=strlen(cad);
     x=cad[0] - 'a' + 1;
     y=cad[k-1] - 'a' + 1;
     G[x].push_back(make_pair(k,y));
     mk[x]=true;
     G[y].push_back(make_pair(k,x));
     mk[y]=true;
     sol+=k;
     scanf("%s",&cad);
    }
    bool ok=true;
    for (i=1; i<=26; i++){
     k=G[i].size();
     if (k % 2 != 0 && mk[i]){
        c++;
        p[c]=i;
        ok=false;
        if (c == 2) break;
     }
    }
    fill(d,d+mx,oo);
    d[p[1]]=0;
    if (!ok) sol+=dijkstra();
    printf("%d\n",sol);
    return 0;
}
