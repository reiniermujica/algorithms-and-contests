//Reinier César Mujica
//25/2/08 5:10 pm 31s
//PSN-2008

#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 151;

struct cell{
       int num,x,y; 
       };

struct cmp{
       bool operator()(const cell &a,const cell &b){
            return (a.num < b.num);
            } 
       };

int n,m,r,sol[MAXN][MAXN],cant;

priority_queue < cell,vector<cell> ,cmp > q;

int main(){ 
    int i,j,k,tmp[MAXN],t=0;
    freopen("pant.in","r",stdin);
    freopen("pant.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d",&r);
    for (i=1; i<=n; i++){
     if (i % 2 != 0)
      for (j=1; j<=m; j++){
        t++;
        scanf("%d",&k);
        q.push( (cell){k,i,j});
        if (t == r){
            t=0;
            sol[q.top().x][q.top().y]=++cant;
            q.pop();
            }
        }
    else
    {
     for (j=1; j<=m; j++)
         scanf("%d",&tmp[j]);   
     for (j=m; j>0; j--){
         q.push( (cell){tmp[j],i,j});
         t++;
         if (t == r){
            t=0;
            sol[q.top().x][q.top().y]=++cant;
            q.pop();
            }
        }       
    }
    }
    while (!q.empty()){
          sol[q.top().x][q.top().y]=++cant;
          q.pop();
         }
    for (i=1; i<=n; i++){
     for (j=1; j<=m; j++)
      printf("%d ",sol[i][j]);
     printf("\n");
    }
    fflush(stdout);
    return 0;    
}
