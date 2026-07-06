// Last updated: 7/6/2026, 12:08:08 PM
class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
             int r, int c) {

        int n = grid.size();
        int m = grid[0].size();

        // out of bounds or water or already visited
        if (r < 0 || c < 0 || r >= n || c >= m ||
            grid[r][c] == 0 || visited[r][c])
            return;

        visited[r][c] = true;

        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 1: DFS from boundary land cells
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, visited, i, 0);
            if (grid[i][m - 1] == 1) dfs(grid, visited, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(grid, visited, 0, j);
            if (grid[n - 1][j] == 1) dfs(grid, visited, n - 1, j);
        }

        // Step 2: Count unvisited land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    count++;
            }
        }

        return count;
    }
};
