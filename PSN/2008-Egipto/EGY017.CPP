//Reinier César Mujica
//24/2/08 5:40 PM
//PSN-2008

#include <cstdio>
#include <cstring>

const int mx = 20,fact[10] = {0,1,2,6,24,120,720,5040,40320,362880};

int n,p[mx],m,pos,sol;
bool mk[mx];
char per[mx];

void number(){
     int i,j,k,l;
     l=strlen(per); sol=0;
     memset(mk,0,sizeof(mk));
     for (i=0; i<l; i++){
      k=per[i] - '0';
      for (j=0; j<k; j++)
       if (!mk[j]) sol+=fact[l-i-1];
       mk[k]=1;
      }
      printf("%d\n",sol+1);
     }

void permut(){
     int i,j,k=0;
     sol=0; for (i=0; i<=m; i++) mk[i]=0;
     for (i=0; i<m; i++){
         sol=0;
         for (j=0; j<m; j++)
          if (!mk[j]){
             if (k + sol + fact[m-i-1] >= pos){
                     p[i]=j;
                     mk[j]=1;
                     break;
                     }
             else
             {
                 sol+=fact[m-i-1];
                 p[i]=j;
             }
             }
           k+=sol;
         }
      for (i=0; i<m; i++)
       printf("%d",p[i]);
      printf("\n");
     }

int main(){
    int i;
    freopen("perlexi.in","r",stdin);
    freopen("perlexi.out","w",stdout);
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&m);
        if (m == -1) {
               scanf("%s",&per);
               number();
               }
        else
        {
         scanf("%d",&pos);
         permut();
        }
        }
    fflush(stdout);        
    return 0;   
}
