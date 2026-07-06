// Last updated: 7/6/2026, 12:08:54 PM
class Solution {
public:
// int solve(string s1,string s2,int ind1,int ind2,vector<vector<int>> &dp)
// {
//     if(ind1<0||ind2<0)
//     {
//         return 0;
//     }
//     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//     if(s1[ind1]==s2[ind2])
//     {
//         return dp[ind1][ind2]= 1+solve(s1,s2,ind1-1,ind2-1,dp);
//     }
//     return dp[ind1][ind2]=max(solve(s1,s2, ind1-1, ind2,dp),solve(s1,s2,ind1,ind2-1,dp));


// }
    int longestPalindromeSubseq(string s) {
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
        return dp[ind][ind];
    }
};