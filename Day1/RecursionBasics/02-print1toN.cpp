#include <bits/stdc++.h>
using namespace std;

void printNames(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    printNames(i+1,n);
}

int main() {
    
    int n;
    cin>>n;
    printNames(1,n);

    return 0;
}