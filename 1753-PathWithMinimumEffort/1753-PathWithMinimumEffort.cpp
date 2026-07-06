// Last updated: 7/6/2026, 12:07:37 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int effort = node.first;
            int r = node.second.first;
            int c = node.second.second;

            if (r == n-1 && c == m-1) return effort;

            if (effort > dist[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(
                        effort,
                        abs(heights[nr][nc] - heights[r][c])
                    );

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};
