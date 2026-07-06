// Last updated: 7/6/2026, 12:07:03 PM
class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n,vector<int>(m,-1));
        best[0][0]=health-grid[0][0];
        queue<pair<int, pair<int, int>>> q;
        if(best[0][0]<=0) return false;
        q.push({best[0][0], {i, j}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        

        while (!q.empty()) {
            int h = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if (h < 0)
                continue;
            if (row == n - 1 && col == m - 1 && h>=0)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = row + delRow[k];
                int nc = col + delCol[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nh=h-grid[nr][nc];
                    if(nh>best[nr][nc]&& nh>0)
                    {
                        q.push({nh,{nr,nc}});
                        best[nr][nc]=nh;

                    }
                }
            }
        }
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        return bfs(0, 0, grid, health);
    }
};