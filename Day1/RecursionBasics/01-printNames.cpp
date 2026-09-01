#include <bits/stdc++.h>
using namespace std;

void printNames(int i,int n){
    if(i>=n){
        return;
    }
    cout<<"Chikuu"<<endl;
    printNames(i+1,n);
}
int main() {
    
    int n;
    cin>>n;
    printNames(0,n);

    return 0;
}