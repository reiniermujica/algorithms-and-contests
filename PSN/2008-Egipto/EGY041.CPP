/*
 Reinier César Mujica
 1/4/08 PSN - 2008
*/

#include <cstdio>

const int
    mx = 10002;
    
FILE *in,*out;
int li,hi,ri,n=mx,m=0,t[mx];

int main(){
    int i;
    in = stdin; //fopen("skyline.in","r");
    out = stdout;//fopen("skyline.out","w");
    while (!feof(in)){
        fscanf(in,"%d %d %d",&li,&hi,&ri);
        n<?=li; m>?=ri;
        for (i=li; i<ri; i++)
         t[i]>?=hi;
    }
    for (i=n; i<=m; i++)
     if (t[i] !=  t[i-1])
        fprintf(out,"%d %d ",i,t[i]);
    return 0;
}
