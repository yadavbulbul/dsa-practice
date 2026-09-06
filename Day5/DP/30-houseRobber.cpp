/*

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = maxi(nums,nums.size()-1);
        return ans;
    }

    int maxi(vector<int>& nums,int index){
        if(index==0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        int rob = nums[index]+maxi(nums,index-2);
        int notRob = 0+maxi(nums,index-1);
        return max(rob,notRob);
    }
};

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans = maxi(nums,nums.size()-1,dp);
        return ans;
    }

    int maxi(vector<int>& nums,int index,vector<int>&dp){
        if(index==0){
            return nums[index];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int rob = nums[index]+maxi(nums,index-2,dp);
        int notRob = 0+maxi(nums,index-1,dp);
        return dp[index]=max(rob,notRob);
    }
};