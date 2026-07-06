// Last updated: 7/6/2026, 12:10:23 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        int n = board.size();
        int m = board[0].size();

        // Out of bounds or not 'O' or already visited
        if (r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O' || visited[r][c])
            return;

        visited[r][c] = true; // mark safe 'O'

        // Explore 4 directions
        dfs(board, visited, r + 1, c);
        dfs(board, visited, r - 1, c);
        dfs(board, visited, r, c + 1);
        dfs(board, visited, r, c - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 1: DFS from border 'O's
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, visited, i, 0);
            if (board[i][m - 1] == 'O') dfs(board, visited, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, visited, 0, j);
            if (board[n - 1][j] == 'O') dfs(board, visited, n - 1, j);
        }

        // Step 2: Flip cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X'; // captured
            }
        }
    }
};
