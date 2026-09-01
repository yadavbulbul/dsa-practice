/*
follows the order, either contiguous or non-contiguous

took me a while to understand this one

this template will help with such kind of patterns

void solve(int index, vector<int>& arr, vector<int>& ds) {

    // Base case
    if(index == arr.size()) {
        // process ds
        return;
    }

    // TAKE
    ds.push_back(arr[index]);
    solve(index + 1, arr, ds);

    // BACKTRACK
    ds.pop_back();

    // NOT TAKE
    solve(index + 1, arr, ds);
}

1. Take
2. Recurse
3. Undo
4. Don't take

*/

#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&arr,vector<int>&ds){
    // we will write the base case here
    if(i>=arr.size()){
        for(int num:ds){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }

    //take it
    ds.push_back(arr[i]);
    solve(i+1,arr,ds);

    //backtrack->dont take
    ds.pop_back();
    solve(i+1,arr,ds);
}

int main() {
    vector<int>arr = {1,2,3,4};
    vector<int>ds;
    solve(0,arr,ds);

    return 0;
}