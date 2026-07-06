// Last updated: 7/6/2026, 12:10:32 PM


class Solution {
public:
int cal(int ind,int buy,vector<int>& prices,vector<vector<vector<int>>> &dp,int cap)
{
    int n=prices.size();
    if(ind==n|| cap==0)
    {
        return 0;
    }
    int profit=0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    if(buy==1)
    {
        profit=max(-prices[ind]+cal(ind+1,0,prices,dp,cap),cal(ind+1,1,prices,dp,cap));
    }
    else
    {
        profit=max(prices[ind]+cal(ind+1,1,prices,dp,cap-1),cal(ind+1,0,prices,dp,cap));
    }
    return dp[ind][buy][cap]=profit;
}
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
    //     if (n <= 1) return 0;   // handle empty or 1-element array

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
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
                for(int cap=0;cap<3;cap++)
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
        return dp[0][1][2];
     
    }
};
