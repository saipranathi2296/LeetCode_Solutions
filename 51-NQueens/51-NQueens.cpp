// Last updated: 7/6/2026, 12:11:25 PM
class Solution {
    bool check(int row,int col,vector<string>board,int n)
     {
        int r = row, c = col;

        // Check upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Check left
        c = col;
        while (c >= 0) {
            if (board[row][c] == 'Q') return false;
            c--;
        }

        // Check lower-left diagonal
        r = row, c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        return true;
    }

    void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(check(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board (n,string(n,'.'));
        solve(0,ans,board,n);
        return ans;
    }
};