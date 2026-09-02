class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        solve(0,nums,ans,ds);
        return ans;
    }
    void solve(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>&ds){
        
        ans.push_back(ds);
        for(int index=i;index<nums.size();index++){
            if(index>i && nums[index]==nums[index-1]){
                continue;
            }
            else{
                ds.push_back(nums[index]);
                solve(index+1,nums,ans,ds);

                ds.pop_back();
            }
        }
    }
};