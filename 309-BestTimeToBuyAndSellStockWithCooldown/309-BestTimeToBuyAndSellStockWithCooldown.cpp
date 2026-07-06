// Last updated: 7/6/2026, 12:09:10 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // dp[ind][buy], +2 for cooldown
        vector<vector<int>> dp(n+2, vector<int>(2, 0));

        for (int ind = n-1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) { // can buy
                    dp[ind][buy] = max(
                        -prices[ind] + dp[ind+1][0], // buy
                        dp[ind+1][1]                  // skip
                    );
                } else { // must sell
                    dp[ind][buy] = max(
                        prices[ind] + dp[ind+2][1], // sell → cooldown
                        dp[ind+1][0]                 // skip
                    );
                }
            }
        }
        return dp[0][1];
    }
};
