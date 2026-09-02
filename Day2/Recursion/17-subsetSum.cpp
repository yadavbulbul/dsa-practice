/*
I tried generating all the subsets first and solved L78-Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums,ans,ds);
        return ans;
    }
    void solve(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>&ds){
        if(i>=nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        solve(i+1,nums,ans,ds);

        ds.pop_back();
        solve(i+1,nums,ans,ds);
    }
};

then solved this https://www.geeksforgeeks.org/problems/subset-sums2234/1
*/

class Solution {
  public:
    void solve(int i,vector<int>& nums,vector<int>& ans,int s){
        if(i>=nums.size()){
            ans.push_back(s);
            return;
        }

        s+=nums[i];
        solve(i+1,nums,ans,s);

        s-=nums[i];
        solve(i+1,nums,ans,s);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>sums;
        solve(0,arr,sums,0);
        return sums;
        
    }
    
};
