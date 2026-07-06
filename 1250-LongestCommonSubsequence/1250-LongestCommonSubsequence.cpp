// Last updated: 7/6/2026, 12:07:57 PM
class Solution {
public:
// int solve(string text1, string text2,int ind1,int ind2)
// {
// if(ind1<0||ind2<0) return 0;
// if(text1[ind1]==text2[ind2])
// {
//   return 1+solve(text1,text2,ind1-1,ind2-1);  
// }
// return max(solve(text1,text2,ind1-1,ind2),solve(text1,text2,ind1,ind2-1));

// }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int> prev(n2+1,0);

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
       
        for(int i=1;i<=n1;i++)
        {
             vector<int> curr(n2+1,0);
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1+prev[j-1];

                }
                else
                {
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
     return prev[n2];
    }
};