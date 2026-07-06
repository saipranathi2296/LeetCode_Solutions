// Last updated: 7/6/2026, 12:07:52 PM
class Solution {
public:
    int n, m;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1)
            return;

        grid[i][j] = 1;  // mark visited

        for (int d = 0; d < 4; d++) {
            dfs(i + dx[d], j + dy[d], grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // 1️⃣ Remove boundary connected lands
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) dfs(i, 0, grid);
            if (grid[i][m - 1] == 0) dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) dfs(0, j, grid);
            if (grid[n - 1][j] == 0) dfs(n - 1, j, grid);
        }

        // 2️⃣ Count remaining closed islands
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};
