#include <bits/stdc++.h>
using namespace std;

void printNames(int n){
    if(n<1){
        return;
    }
    
    printNames(n-1);
    cout<<n<<endl;
}

int main() {
    
    int n;
    cin>>n;
    printNames(n);

    return 0;
}