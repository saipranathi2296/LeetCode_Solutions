// Last updated: 7/6/2026, 12:07:08 PM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxOnes = -1;
        int rowIndex = -1;

        for (int i = 0; i < n; i++) {
            int onesCount = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) onesCount++;
            }
            // Update max only if current row has more ones
            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};
