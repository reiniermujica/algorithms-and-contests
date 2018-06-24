#include <cstdio>
#include <fstream> //para que intercambie sin &
using namespace std;
#define mx 152

long n,m,r,act=0,sav[mx][4],t[mx*mx*mx][4],sol[mx][mx];

void swap(long *a,long *b){
     long s;
     s=*a; *a=*b; *b=s;
     }
     
void ubica(long x){
     long a,c,d;
     a=x;
     while (a > 1 && t[a][1] > t[a/2][1]){
           swap(t[a][1],t[a/2][1]);
           swap(t[a][2],t[a/2][2]);
           swap(t[a][3],t[a/2][3]);
           a=a/2;
           }
     while (a <= act && (t[a*2][1] > t[a][1] || t[a*2+1][1] > t[a][1])){
           c=t[a*2][1]; d=t[a*2+1][1];
           if (c > d && c > t[a][1]){
                 swap(t[a][1],t[a*2][1]);
                 swap(t[a][2],t[a*2][2]);
                 swap(t[a][3],t[a*2][3]);
                 a=a*2;                 
                 }
           else
           if (d > t[a][1]){
                 swap(t[a][1],t[a*2+1][1]);
                 swap(t[a][2],t[a*2+1][2]);
                 swap(t[a][3],t[a*2+1][3]);
                 a=a*2+1;                 
                 }
           }
     }
     
int main(){
    long i,j,k=1,p=0;
    freopen("pant.in","r",stdin);
    freopen("pant.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&r);
    for (i=1; i<=n; i++){
     if (i % 2 == 0){     
       for (j=m; j>=1; j--){ //    <----------
           scanf("%d",&sav[j][1]);
           sav[j][2]=i;
           sav[j][3]=m-j+1;
           }
           }
     else
     { for (j=1; j<=m; j++){ //    ---------->
           scanf("%d",&sav[j][1]);
           sav[j][2]=i;
           sav[j][3]=j;
           }
           }
     for (j=1; j<=m; j++){
         act++; p++;
         t[act][1]=sav[j][1]; 
         t[act][2]=sav[j][2]; 
         t[act][3]=sav[j][3];
         ubica(act);
         if (p % r == 0){
                 sol[t[1][2]][t[1][3]]=k;
                 k++;
                 t[1][1]=t[act][1];
                 t[1][2]=t[act][2];
                 t[1][3]=t[act][3];
                 t[act][1]=0;
                 act--;  
                 ubica(1);              
                 }
                 }                
         }
    while (act > 0){
          ubica(1);
          sol[t[1][2]][t[1][3]]=k;
          k++;
          t[1][1]=t[act][1];
          t[1][2]=t[act][2];
          t[1][3]=t[act][3];
          t[act][1]=0;
          act--;                
        }
    for (i=1; i<=n; i++){
     for (j=1; j<=m; j++)
      printf("%d ",sol[i][j]);
     printf("\n");
     }
    return 0;
}
