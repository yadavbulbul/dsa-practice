/*
If a recursive call represents a choice and you want to count how many choices succeed, return the count from each branch and add them
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int i,vector<int>&arr,int sum,int s){
    // we will write the base case here
    if(i>=arr.size()){
        if(s==sum){
            return 1;
        }
        else{
            return 0;
        }
    }

    //take it
    s+=arr[i];
    int l = solve(i+1,arr,sum,s);

    //backtrack->dont take
    s-=arr[i];
    int r = solve(i+1,arr,sum,s);

    return l+r;
}

int main() {
    vector<int>arr = {1,2,3,4,5,6,7};
    int sum = 6;
    cout<<solve(0,arr,sum,0);

    return 0;
}