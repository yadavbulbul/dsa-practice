class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(v,0);
        
        return solve(0,adj,color,m);
        
        
        
    }
    bool solve(int node,vector<vector<int>>&adj,vector<int>&color,int m){
        
        if(node==adj.size()){
            return true;
        }
        
        for(int j=1;j<=m;j++){
            if(validColor(node,j,adj,color)){
                //choose
                color[node]=j;
                //explore
                if(solve(node+1,adj,color,m)){
                    return true;
                }
                //backtrack
                color[node]=0;
            } 
            
        }
        return false;
            
        
    }
    bool validColor(int node,int j,vector<vector<int>>&adj,vector<int>&color){
        for(int neigh:adj[node]){
            if(color[neigh]==j){
                return false;
            }
        }
        return true;
    }
};