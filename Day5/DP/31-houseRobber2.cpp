class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int option1 = maxi(nums,1,n-1,dp1);

        int option2 = maxi(nums,0,n-2,dp2);
        return max(option1,option2);
    }
    int maxi(vector<int>& nums,int start,int end,vector<int>&dp){
        if(end==start){
            return nums[end];
        }
        if(end<start){
            return 0;
        }
        if(dp[end]!=-1){
            return dp[end];
        }
        int rob = nums[end]+maxi(nums,start,end-2,dp);
        int notRob = 0+maxi(nums,start,end-1,dp);
        return dp[end]=max(rob,notRob);
    }
};

//same logic as that of house robber, just remember because this is in circle we can either take first house or last house, hence again we have 2choices here