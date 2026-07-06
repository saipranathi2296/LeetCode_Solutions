// Last updated: 7/6/2026, 12:08:34 PM
// class Solution {
// public:
// int cal (int ind,vector<int>&cost,vector<int> &dp)
// {
//     // if(ind<=1) return 0;
//     // if(dp[ind]!=-1) return dp[ind];

//     // int left=cal(ind-1,cost,dp)+cost[ind-1];
    
//     //     int right=cal(ind-2,cost,dp)+cost[ind-2];

//     // return dp[ind]=min(left,right);
//     if(ind<=1) return 0;
//     dp[0]=0;
//     dp[1]=0;
//     for(int i=2;i<=ind;i++)
//     {
//         int left=dp[ind-1]+cost[ind-1];
//         int rigth=dp[ind-2]+cost[ind-2];
//         dp[i]=min(left,right);

//     }
//     return dp[ind];
// }
//     int minCostClimbingStairs(vector<int>& cost) {
//         // int n=cost.size();
//         // vector<int> dp(n+1,-1);
//         // int result=cal(n,cost,dp);
//         // return result;
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         int result=cal(n,cost,dp);
//         return result;
        
//     }
// };
// class Solution {
// public:
//     int cal(int ind, vector<int>& cost, vector<int>& dp) {
//         if (ind <= 1) return 0;

//         dp[0] = 0;
//         dp[1] = 0;

//         for (int i = 2; i <= ind; i++) {
//             int left  = dp[i - 1] + cost[i - 1];
//             int right = dp[i - 2] + cost[i - 2];
//             dp[i] = min(left, right);
//         }

//         return dp[ind];
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1, -1);
//         return cal(n, cost, dp);
//     }
// };
class Solution {
public:
  
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
       int prev=0;
       int  prev2=0,current;
        for(int i=2;i<=n;i++)
        {
            int left=prev+cost[i-1];
            int right=prev2+cost[i-2];
            current=min(left,right);
            prev2=prev;
            prev=current;
            
        }
        return prev;
    }
};
