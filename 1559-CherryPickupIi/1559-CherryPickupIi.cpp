// Last updated: 7/6/2026, 12:07:42 PM
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();     // rows
        int m = grid[0].size();  // columns

        // dp[col1][col2] => max cherries collected when robot1 is at col1, robot2 at col2 at current row
        vector<vector<int>> front(m, vector<int>(m, 0));

        // Base case: fill the last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    front[j1][j2] = grid[n-1][j1];
                else
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Bottom-up DP
        for (int i = n-2; i >= 0; i--) {
            vector<vector<int>> curr(m, vector<int>(m, 0));
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = 0;

                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                int value = 0;
                                if (j1 == j2)
                                    value = grid[i][j1];
                                else
                                    value = grid[i][j1] + grid[i][j2];

                                value += front[nj1][nj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m-1];
    }
};
