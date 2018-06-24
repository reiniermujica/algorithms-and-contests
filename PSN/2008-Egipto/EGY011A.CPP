//Reinier César Mujica
//26/2/08 3:00 01 s
//PSN-2008

#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int
   mx = 301,
   oo = 20000000;
   
const int mov[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const int val[4]    = { 1 , 0 , 1 , 0};

typedef pair<int,int> point;

int n,m,sol,r,c,pos[4],t[mx][mx],cont[mx][mx];
point cam[mx][mx],res[mx*mx];
bool mk[mx][mx];

queue < point > q;  // Cola

void bfs(){
     int i,j,k,x,y,z[2];
     bool mark[mx][mx];
     q.push(make_pair(pos[0],pos[1]));
     t[pos[0]][pos[1]]=0;
     while (!q.empty()){
           x=q.front().first;
           y=q.front().second;
           q.pop();
           for (j=0; j<4; j++){
             z[0]=x + mov[j][0];
             z[1]=y + mov[j][1];
             if (z[0] > 0 && z[0] <=n && z[1] > 0 && z[1] <= m
              && !mk[z[0]][z[1]]){
                if ( t[x][y] + val[j] < t[z[0]][z[1]] ) {
                    t[z[0]][z[1]] = t[x][y] + val[j];
                    cont[z[0]][z[1]]=cont[x][y] + 1;              
                    cam[z[0]][z[1]].first=x;
                    cam[z[0]][z[1]].second=y;
                    q.push(make_pair(z[0],z[1]));                    
                    }                  
                }
               }
           }
       sol=t[pos[2]][pos[3]];
       c=cont[pos[2]][pos[3]];
     }
     
int main(){
    int i,j,x,y;
    freopen("sensor.in","r",stdin);
    freopen("sensor.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=0; i<4; i++)
     scanf("%d",&pos[i]);
    scanf("%d",&r);
    for (i=1; i<=r; i++){
        scanf("%d %d",&x,&y);
        mk[x][y]=true;
        }
    for (i=0; i<=n; i++){
         fill(t[i],t[i]+m+1,oo);
        }
    bfs();
    printf("%d\n",c+1);    
    printf("%d\n",sol);        
    x=cam[pos[2]][pos[3]].first;
    y=cam[pos[2]][pos[3]].second;
    i=0;
    while (x!=0 && y!=0){
          i++;
          res[i].first=x;
          res[i].second=y;
          j=x;
          x=cam[x][y].first;
          y=cam[j][y].second;
          }
    for (i=c; i>0; i--){
        printf("%d %d\n",res[i].first,res[i].second);
        }
    printf("%d %d\n",pos[2],pos[3]);
    fflush(stdout);
    return 0;   
}
