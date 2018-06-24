//Reinier César Mujica
//14/3/08 PSN - 2008

#include <cstdio>

const int
    mx = 2002;
    
int n,act;
char cad[mx],sol[mx];

int main(){
    int i,j,x,y;
    freopen("bcl.in","r",stdin);
    freopen("bcl.out","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        scanf("%s",&cad[i]);
    i=1; j=n; act=0;
    while (i <= j){
        if (cad[i] < cad[j]){
            sol[++act]=cad[i];
            i++;
        }
        else
        if (cad[i] > cad[j]){
            sol[++act]=cad[j];
            j--;      
        }
        else
        if (cad[i] == cad[j]){
            x=i; y=j;
            while (x < y && cad[x] == cad[y]){
             x++; y--;
            }
           if (cad[x] < cad[y]){
               sol[++act]=cad[i];
               i++;           
           }
           else
           {
           sol[++act]=cad[j];
           j--;                    
           }
        }
    }
    for (i=1; i<=n; i++)
       if (i % 80 == 0) printf("%c\n",sol[i]);
       else printf("%c",sol[i]);
    if (n % 80 != 0) printf("\n");
    return 0;
}
