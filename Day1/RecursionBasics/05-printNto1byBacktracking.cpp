#include <bits/stdc++.h>
using namespace std;

void printNames(int n,int i){
    if(i>n){
        return;
    }
    
    printNames(n,i+1);
    cout<<i<<endl;
}

int main() {
    
    int n;
    cin>>n;
    printNames(n,1);

    return 0;
}