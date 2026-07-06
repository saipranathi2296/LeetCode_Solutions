// Last updated: 7/6/2026, 12:07:49 PM
class Solution {
public:
    int minInsertions(string s) {
        string first=s;
        reverse(s.begin(),s.end());
        string second=s;
        int ind=s.size();
        vector<vector<int>> dp(ind+1,vector<int>(ind+1,0));
        for(int i=1;i<=ind;i++)
        {
            for(int j=1;j<=ind;j++)
            {
               if(first[i-1]==second[j-1])
               {
                dp[i][j]=1+dp[i-1][j-1];
               }
               else
               {
dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }
            }
        }
        return ind-dp[ind][ind];
    }
    
};