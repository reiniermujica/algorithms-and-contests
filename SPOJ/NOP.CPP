#include <iostream>
#include <string>
using namespace std;int r,i,j,k,p[500];string s;main(){for(i=4;j<499;j++,i+=4)p[j]=i;cin>>s;for(i=1,j=1,k=0;i<s.size();){if(s[i]>=97&&s[i]<='z'){i++;if(j+1==p[k]){j++;k++;}else j++;}else{if(!(j%4)){i++;j++;}else{r+=p[k]-j;j=p[k]+1;k++;i++;}}}cout<<r<<endl;}
