class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ways = solve1(n,dp);
        
        return ways;
    }
    //recursion
    int solve(int index){
        if(index==0 || index==1){
            return 1;
        }
        int choice1 = solve(index-1);
        int choice2 = solve(index-2);

        return choice1+choice2;
    }
    //memoization
    int solve1(int index,vector<int>&dp){
        if(index==0 || index==1){
            return 1;
        }
        if(dp[index]==-1){
            dp[index]=solve1(index-1,dp)+solve1(index-2,dp);
        }
        return dp[index];
    }
    //tabulation
    int solve2(int index,vector<int>&dp){
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=index;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[index];
    }
    
};