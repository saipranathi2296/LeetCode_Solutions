// Last updated: 7/6/2026, 12:08:39 PM
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                        prices[ind] + dp[ind+1][1]-fee,   // sell
                        dp[ind+1][0]                   // skip
                    );
                }
            }
        }
        return dp[0][1];
    }
};