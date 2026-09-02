/*
for left side rows.. directly check the rowss.

for lower diagonal.. mark row+col

for upper diagonal.. mark n-1+col-row
*/

class Solution {
public:
    void solve(vector<string>&board,int col,int n,vector<vector<string>>&ans,vector<int>&lrow,vector<int>&ud,vector<int>&ld){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(lrow[row]==0 && ud[row+col]==0 && ld[n-1+col-row]==0){
                board[row][col]='Q';
                lrow[row]=1;
                ud[row+col]=1;
                ld[n-1+col-row]=1;
                solve(board,col+1,n,ans,lrow,ud,ld);
                board[row][col]='.';
                lrow[row]=0;
                ud[row+col]=0;
                ld[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        
        vector<int>lrow(n,0);
        vector<int>ld(2*n-1,0);
        vector<int>ud(2*n-1,0);
        solve(board,0,n,ans,lrow,ud,ld);

        return ans;
    }
};