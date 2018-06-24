/*
 Reinier César Mujica
 2/4/08 PSN - 2008
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int
      mx = 650,
      oo = 1<<29;
            
int n,m,p,sol,kv[mx],t[mx],sum[mx][mx],dp[mx][mx],cam[mx][mx];
vector <int> V[mx];

bool cmp(const int &a,const int &b){
     return t[a] < t[b];
}

int main(){
    int i,j,l,k;
    freopen ("tooth.in","r",stdin);
    freopen ("tooth.out","w",stdout);
    scanf ("%d %d %d",&n,&m,&p);
    for (i=1; i<=m; i++) scanf ("%d",&kv[i]);
    for (i=1; i<=n; i++){
        scanf ("%d %d",&t[i],&k);
        V[k].push_back(i);
    }
    for (i=1; i<=m; i++)
     sort(V[i].begin(),V[i].end(),cmp); 
    for (i=1; i<=m; i++){
     for (j=0; j<V[i].size(); j++)
       sum[i][j+1]=sum[i][j] + t[V[i][j]];
     for (j=0; j<V[i].size(); j++)
       sum[i][j+1]+=kv[i];   
    }
    for (i=1; i<=m; i++)
     fill(dp[i]+1,dp[i]+n+1,oo); //el 0 no,casi me vuelvo loco con ese error
    /*..Case Base..*/
    for (i=0; i<V[1].size(); i++){
        dp[1][i+1]=sum[1][i+1];
        cam[1][i+1]=i+1;
    }
    /*..DP..*/
    for (i=2; i<=m; i++){
     for (j=1; j<=n; j++) dp[i][j]=dp[i-1][j];
     for (j=1; j<=n; j++)
      for (l=1; (l<=V[i].size() && l<=j); l++){
          if (dp[i][j] > sum[i][l] + dp[i-1][j-l]){
             dp[i][j]=sum[i][l] + dp[i-1][j-l];        
             cam[i][j]=l;
          }       
      }
    }
    sol=1;
    while (dp[m][sol] <= p) sol++;    
    printf("%d\n",--sol);
    int r=m;
    while (r){
       for (i=1; i<=cam[r][sol]; i++)
         printf("%d ",V[r][i-1]);
        sol-=cam[r][sol];
        r--;
    }
    fflush(stdout);
    return 0;    
}
