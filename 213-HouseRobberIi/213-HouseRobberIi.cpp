// Last updated: 7/6/2026, 12:09:38 PM
class Solution {
public:
int res(vector<int>&num,vector<int>& dp,int ind)
{
    dp[0]=num[0];
    for(int i=1;i<ind;i++)
    {
int pick=num[i];
if(i>1)
{
    pick+=dp[i-2];
}
int not_pick=dp[i-1];
dp[i]=max(pick,not_pick);
    }
    return dp[ind-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++)
        {
if(i!=0) temp1.push_back(nums[i]);
if(i!=n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), 0);
        vector<int> dp2(temp2.size(), 0);
        return max(res(temp1,dp1,temp1.size()),res(temp2,dp2,temp2.size()));
    }
};