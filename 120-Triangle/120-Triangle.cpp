// Last updated: 7/6/2026, 12:10:36 PM
class Solution {
    
//     int solve(int row,int col,vector<vector<int>>& triangle)
//     {
// int n=triangle.size();
// if(row==n-1) return triangle[row][col];

// int left=solve(row+1,col,triangle)+triangle[row][col];
// int right=solve(row+1,col+1,triangle)+triangle[row][col];
// return min(left,right);
//     }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

vector<vector<int>> dp(n,vector<int>(n,0));
for(int i=n-1;i>=0;i--)
{
    for(int j=i;j>=0;j--)
    {
        if(i==n-1)
        {
          dp[i][j]=triangle[i][j];  
        }
        else
        {
            int left=dp[i+1][j]+triangle[i][j];
            int right=dp[i+1][j+1]+triangle[i][j];
              dp[i][j]=min(left,right);

        }
      

    }
}
return dp[0][0];
    }
};
