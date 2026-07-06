// Last updated: 7/6/2026, 12:09:09 PM
class Solution {
public:
// int solve(int ind,vector<int>& coins, int amount)
// {
//     if(amount==0) return 0;
//     if(ind==0)
//     {
//         if(amount%coins[0]==0)
//         {
//             return amount/coins[0];
//         }
//         return INT_MAX;
//     }
//     int nottake=solve(ind-1,coins,amount);
//     int take=coins[ind];
//     if(coins[ind]<=amount)
//     {
//        take=1+solve(ind,coins,amount-coins[ind]); 
//     }
//     return min(take,nottake);
// }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
      
       vector<vector<int>> dp(n,vector<int>(amount+1,0));
for(int i=0;i<n;i++)
{
    for(int j=0;j<=amount;j++)
    {
        if(j==0) dp[i][j]=0;
        else if(i==0)
        {
            if(j%coins[0]==0)
            {
                dp[i][j]=j/coins[0];
            }
            else
            {
dp[i][j]=1e9;
            }
            
        }
        else
        {
int nottake=dp[i-1][j];
    int take=INT_MAX;
    if(coins[i]<=j)
    {
      take=1+dp[i][j-coins[i]];
    }
    dp[i][j]=min(take,nottake);
        }
    }
}
int ans = dp[n - 1][amount];
return (ans >= 1e9) ? -1 : ans;
    }
};