// Last updated: 7/6/2026, 12:09:57 PM
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       
       int n = prices.size();
    //     if (n <= 1) return 0;   // handle empty or 1-element array

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));
    //    return cal(0,1,prices,dp,2);
    //
       
    
        if (n <= 1) return 0;   // handle empty or 1-element array
for(int i=0;i<=n;i++)
{
    for(int j=0;j<=1;j++)
    {
        dp[i][j][0]=0;
    }
}

        // dp[n][0] = dp[n][1] = 0 by default

        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int cap=0;cap<=k;cap++)
                {
                if (buy == 1) {
                    dp[ind][buy][cap] = max(
                        -prices[ind] + dp[ind+1][0][cap],  // buy
                        dp[ind+1][1] [cap]                  // skip
                    );
                } else {
                    if(cap>0)
                    {
                    dp[ind][buy][cap] = max(
                        prices[ind] + dp[ind+1][1][cap-1],   // sell
                        dp[ind+1][0] [cap]                  // skip
                    );
                    }
                }
            }
            }
        }
        return dp[0][1][k];
     
     
    }
};