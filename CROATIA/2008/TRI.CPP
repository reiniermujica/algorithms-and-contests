#include <iostream>

using namespace std;

int a,b,c,sol,i,j;

void print(int pos,char x){
     if (pos == 1)
      cout << a << x << b << '=' << c << endl;
     else
      cout << a << '=' << b << x << c << endl;
      exit(0);
     }
     
int main(){
    cin >> a >> b >> c;
    if (a*b == c) print(1,'*');
    if ((double)a/b == c) print(1,'/');
    if (a+b == c) print(1,'+');        
    if (a-b == c) print(1,'-');    

    if (a == b*c) print(2,'*');
    if (a == (double)b/c) print(2,'/');
    if (a == b+c) print(2,'+');    
    if (a == b-c) print(2,'-');
    return 0;   
}
