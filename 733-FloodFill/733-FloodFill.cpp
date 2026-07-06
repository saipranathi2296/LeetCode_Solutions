// Last updated: 7/6/2026, 12:08:36 PM
class Solution {
public:
    void bfs(int start, int color,
             vector<vector<int>>& image,
             int sr, int sc) {

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    image[nr][nc] == start) {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int start = image[sr][sc];

        if (start == color) return image;

        bfs(start, color, image, sr, sc);

        return image;
    }
};