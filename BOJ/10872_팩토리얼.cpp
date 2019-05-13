#include <iostream>

using namespace std;

int main(){
    int n, ret = 1;
    cin >> n;
    
    for(int i=1; i<=n; ++i){
        ret *= i;
    }
    cout<<ret;
    
    return 0; 
}