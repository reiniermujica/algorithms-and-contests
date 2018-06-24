//Reinier César Mujica
//28-2-08 11:45 15s am.
//PSN-2008

#include <cstdio>
#include <algorithm>

using namespace std;

const
 int mx = 1500;
 
int n,d,p[mx*mx][3],s[mx][mx],t[mx][mx],sol[3];

void build_table(){
     int i,j;
     for (i=0; i<=1024; i++)
      for (j=0; j<=1024; j++)
       t[i][j]=s[i][j] + t[i-1][j] + t[i][j-1] - t[i-1][j-1];
     }
     
void calc_point(){
     int i,j,h1,h2,s1,s2,k;
     sol[2]=0;
     for (i=1; i<=1024; i++){
      for (j=1; j<=1024; j++){
          h1=max(i-d,0); h2=max(j-d,0);
          s1=min(i+d,1024); s2=min(j+d,1024);
          k=t[s1][s2] - t[h1-1][s2] - t[s1][h2-1] + t[h1-1][h2-1];
          if (sol[2]< k){
             sol[2]=k;
             sol[0]=i;
             sol[1]=j;         
             }
          }
       }
     }     

int main(){
    int i,j;
    freopen("rats.in","r",stdin);
    freopen("rats.out","w",stdout);
    scanf("%d",&d);
    scanf("%d",&n);
    for (i=1; i<=n; i++){
        scanf("%d %d %d",&p[i][0],&p[i][1],&p[i][2]);
        s[p[i][0]][p[i][1]]=p[i][2];
        }
    build_table();
    calc_point();
    printf("%d %d %d\n",sol[0],sol[1],sol[2]);
    fflush(stdout);
    return 0;
}
