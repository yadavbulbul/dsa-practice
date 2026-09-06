/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair.

From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs.

Determine the minimum total cost required for the frog to reach the last stair.

Example:

Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation: Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        int ans = cost(height,n-1,dp);
        return ans;
        
    }
    int cost(vector<int>& height,int index,vector<int>&dp){
        if(index==0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int choice1;
        int choice2;
        choice1 = cost(height,index-1,dp)+abs(height[index]-height[index-1]);
        if(index>1){
            choice2 = cost(height,index-2,dp)+abs(height[index]-height[index-2]);
        }else{
            return choice1;
        }
        
        
        return dp[index]=min(choice1,choice2); 
    }
};

