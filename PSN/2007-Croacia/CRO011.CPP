//Reinier César Mujica
//27/2/08 3:15 5s
//PSN - 2008

#include <cstdio>

const int
      mx = 1001,
      oo = 1000000;
      
struct book{
       int h,w;
       };
      
int n,m,sol,best[mx],sum[mx],hmax[mx][mx],cam[mx];
book lib[mx];

void dynamic(){
     int i,j;
     for (i=1; i<=n; i++){ //pre calc
      for (j=i+1; j<=n; j++){
          hmax[i][j] = hmax[i][j-1] >? lib[j].h;
          }
         }                 //end p.calc
     best[1]=lib[1].h;    
     for (i=2; i<=n; i++){//dynamic programing
      best[i]=oo;
      for (j=1; j<=i; j++){
          if (sum[i] - sum[j-1] <= m){
             if (best[i] > hmax[j][i]+best[j-1]){
                best[i]=hmax[j][i]+best[j-1];         
                cam[i]=j-1;
                }
             } 
          }   
      }                  //end dp
     sol=best[n];
     }
     
int main(){
    int i,j;
    freopen("estante.in","r",stdin);
    freopen("estante.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; i++){
        scanf("%d %d",&lib[i].h,&lib[i].w);
        sum[i]=sum[i-1] + lib[i].w;
        hmax[i][i]=lib[i].h;
        }
    dynamic();     
    j=n; i=0;
    while (j){
          i++;
          sum[i]=j-cam[j];
          j=cam[j];
          }
    printf("%d %d\n",sol,i);
    for (j=i; j>0; j--)
     printf("%d\n",sum[j]);
    fflush(stdout);
    return 0;   
}
