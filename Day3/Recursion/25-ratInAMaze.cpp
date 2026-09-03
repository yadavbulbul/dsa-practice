class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string>ans;
        string s="";
        vector<vector<int>>vis(n,vector<int>(n,0));
        int deli[] = {1, 0, 0, -1};
        int delj[] = {0, -1, 1, 0};
        if(maze[0][0]==1){
          vis[0][0] = 1;
          solve(0,0,s,ans,maze,vis,deli,delj,n);  
        }
        
        return ans;
        
    }
    void solve(int i, int j, string s,vector<string>&ans, vector<vector<int>>& maze, 
    vector<vector<int>>& vis, int deli[], int delj[],int n){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        //based on delta i and delta j
        string dir = "DLRU";
        for(int index=0;index<4;index++){
            int nexti = i + deli[index];
            int nextj = j + delj[index];
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && vis[nexti][nextj]==0 && maze[nexti][nextj]==1){
                vis[nexti][nextj]=1;
            
                solve(nexti,nextj,s+dir[index],ans,maze,vis,deli,delj,n);
                vis[nexti][nextj]=0;
            }
        }
        
    }
};