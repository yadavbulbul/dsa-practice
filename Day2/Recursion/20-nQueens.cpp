class Solution {
public:
    bool safePlace(int row,int col,vector<string>&board,int n){
        //for upper diagonal left
        int trow = row;
        int tcol = col;

        while(col>=0 && row>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        //for horizontal left
        row = trow;
        col = tcol;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }

        //for lower diagonal right
        row = trow;
        col = tcol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<string>&board,int col,int n,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safePlace(row,col,board,n)){
                board[row][col]='Q';
                solve(board,col+1,n,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n, string(n, '.'));
        solve(board,0,n,ans);
        return ans;
    }
};