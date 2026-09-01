#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&arr,vector<int>&ds,int sum,int s){
    // we will write the base case here
    if(i>=arr.size()){
        if(s==sum){
            for(int num:ds){
                cout<<num<<" ";
            }
            cout<<endl;
        }
        
        return;
    }

    //take it
    ds.push_back(arr[i]);
    s+=arr[i];
    solve(i+1,arr,ds,sum,s);

    //backtrack->dont take
    ds.pop_back();
    s-=arr[i];
    solve(i+1,arr,ds,sum,s);
}

int main() {
    vector<int>arr = {1,2,3,4};
    vector<int>ds;
    int sum = 4;
    solve(0,arr,ds,sum,0);

    return 0;
}