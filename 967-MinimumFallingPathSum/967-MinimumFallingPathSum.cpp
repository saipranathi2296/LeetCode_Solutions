// Last updated: 7/6/2026, 12:08:18 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
vector<int> front(m,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(m,0);
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1)
                {
                    curr[j] = matrix[i][j];
                }
                else
                {
                    int diagl = (j>0) ? front[j-1] : 1e9;

                    int diagri = (j<m-1) ? front[j+1] : 1e9;

                    int down = front[j];

                    curr[j] = matrix[i][j] +
                               min({diagl, diagri, down});
                }
            }
            front=curr;
        }

        int mini = INT_MAX;

        for(int j=0;j<m;j++)
        {
            mini = min(mini, front[j]);
        }

        return mini;
    }
};