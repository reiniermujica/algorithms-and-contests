//Reinier Cesar Mujica Hdez
//20 Feb 08 - 10:44 37s pm
//Optimizacion : Linked List

#include <cstdio>
#include <algorithm>

using namespace std;

const int mx = 50002, oo = 5000000;

struct piece{
       int x,y,c;
       };
       
int n,sol,ini,cont,best[mx],list[mx],cam[mx],cc[mx];
piece t[mx];

bool cmp(const int &a,const int &b){
     if (t[a].x != t[b].x) return t[a].x < t[b].x;
     else return t[a].y < t[b].y;
    }
    
void dynamic(){
     int i,j,k,z[2],a,b;
     for (i=0; i<=n; i++){
         a=list[i]; best[a]=oo; cam[a]=-1;
         cc[a]=1;
         z[0]=(t[a].x - (t[a].c * 2));
         z[1]=(t[a].y - (t[a].c * 2));
         for (j=i-1; j>=0; j--){
             b=list[j];
             if (t[b].x < z[0] && t[b].y < z[1]){
                k=(z[0] * z[1]) - (t[b].x * t[b].y);
                if (best[a] > k + best[b]){
                    best[a]=k + best[b];        
                    cam[a]=b;
                    cc[a]=cc[b] + 1;
                    }
                }
             }
         if (best[a] == oo){
             best[a]=(z[0] * z[1]);                     
             }
         if (a == ini){
               ini=a;
               sol=best[a];
               cont=cc[a];
               break;
               }
         }
     }

int main(){
    int i,x,y,c;
    freopen("aislante.in","r",stdin);
    freopen("aislante.out","w",stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++){ //read              
        scanf("%d %d %d",&x,&y,&c);
        if (x > y) swap(x,y);
        t[i].x=x; t[i].y=y; t[i].c=c;
        list[i]=i;
        }      
    scanf("%d",&ini);   //end read   
    ini--;
    sort(list,list+n,cmp);//sort pieces by the linked list
    n=0;
    while (list[n] != ini) n++;
    dynamic();            //catch        
    printf("%d\n",cont);  
    printf("%d\n",sol);
    printf("%d\n",ini+1);
    x=cam[ini];
    while (x!=-1){
      printf("%d\n",x+1);
      x=cam[x];
     }
    fflush(stdout);        
    return 0;
}
