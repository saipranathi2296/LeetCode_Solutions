// Last updated: 7/6/2026, 12:06:55 PM
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> dp(m,string(n,'#'));
        for(int j=0;j<n;j++)
        {
            dp[0][j]='.';
        }
        for(int i=0;i<m;i++)
        {
            dp[i][n-1]='.';
        }
       return dp;
    }
};