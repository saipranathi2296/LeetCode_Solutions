// Last updated: 7/6/2026, 12:10:33 PM
class Solution {
public:
int cal(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp)
{
    int n=prices.size();
    if(ind==n)
    {
        return 0;
    }
    int profit=0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy==1)
    {
        profit=max(-prices[ind]+cal(ind+1,0,prices,dp),cal(ind+1,1,prices,dp));
    }
    else
    {
        profit=max(prices[ind]+cal(ind+1,1,prices,dp),cal(ind+1,0,prices,dp));
    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
        if (n <= 1) return 0;   // handle empty or 1-element array

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0 by default

        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) {
                    dp[ind][buy] = max(
                        -prices[ind] + dp[ind+1][0],  // buy
                        dp[ind+1][1]                   // skip
                    );
                } else {
                    dp[ind][buy] = max(
                        prices[ind] + dp[ind+1][1],   // sell
                        dp[ind+1][0]                   // skip
                    );
                }
            }
        }
        return dp[0][1];
    }
};