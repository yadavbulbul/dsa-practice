#include<bits/stdc++.h>
using namespace std;

void solve(int i,int s,vector<int>& candidates, int target,vector<int>&ds,vector<vector<int>>&ans){
        if (s>target){
            return;
        }
        if(i>=candidates.size()){
            if(s==target){
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[i]);
        s+=candidates[i];
        //we can reuse the same number hence not doing i+1 
        solve(i,s,candidates,target,ds,ans);

        ds.pop_back();
        s-=candidates[i];
        solve(i+1,s,candidates,target,ds,ans);

    }

int main() {
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>>ans;;
    vector<int>ds;
    int s = 0;
    solve(0,0,candidates,target,ds,ans);
    for(auto v : ans) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}