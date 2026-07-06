// Last updated: 7/6/2026, 12:11:19 PM

class Solution {
public:
  
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

vector<int>prev(n,0);
    for (int i = 0; i < m; i++) prev[0] = 1;
    for (int j = 0; j < n; j++) prev[j] = 1;

    // fill table
    for (int i = 1; i < m; i++) {
        vector<int>curr(n,0);
        curr[0]=1;
        for (int j = 1; j < n; j++) {
            curr[j] = prev[j] + curr[j - 1];
        }
        prev=curr;
    }

    return prev[n - 1];
}
};
// tabualtion
// int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, 0));

//     dp[0][0] = 1;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {

//             if (i == 0 && j == 0) continue;

//             int up = (i > 0) ? dp[i - 1][j] : 0;
//             int left = (j > 0) ? dp[i][j - 1] : 0;

//             dp[i][j] = up + left;
//         }
//     }

//     return dp[m - 1][n - 1];
// }
// space
// int uniquePaths(int m, int n) {
//     vector<int> dp(n, 0);

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {

//             if (i == 0 && j == 0)
//                 dp[j] = 1;
//             else {
//                 int up = (i > 0) ? dp[j] : 0;
//                 int left = (j > 0) ? dp[j - 1] : 0;
//                 dp[j] = up + left;
//             }
//         }
//     }

//     return dp[n - 1];
// }
