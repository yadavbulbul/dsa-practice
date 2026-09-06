class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        int maxi = solve(mat,n-1,3,dp);
        return maxi;
    }
    int solve(vector<vector<int>>& mat,int day,int last,vector<vector<int>>&dp){

        if(day==0){
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxi = max(maxi,mat[day][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        int maxi = 0;
        for(int task=0;task<3;task++){
            if(task != last){
                int points = mat[day][task]+solve(mat,day-1,task,dp);
                maxi = max(points,maxi);
            }
            
        }
        return dp[day][last]=maxi;
    }
};