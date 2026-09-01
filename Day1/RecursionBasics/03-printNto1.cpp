#include <bits/stdc++.h>
using namespace std;

void printNames(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;
    printNames(n-1);
}

int main() {
    
    int n;
    cin>>n;
    printNames(n);

    return 0;
}