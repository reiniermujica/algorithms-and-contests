#include <iostream>

using namespace std;

long long n,k=1,i;

int main(){
    cin >> n;
    for (i=2; i*i<=n; i++){
        if (n % i == 0){
              k=i;
              break;
        }
    }
    if (k == 1) cout << n-1 << endl;
    else cout << n-(n/k) << endl;
    return 0;       
}
