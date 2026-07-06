// Last updated: 7/6/2026, 12:09:13 PM
class Solution {
public:


int cal(int ind,int prev,vector<int>& nums)
{
    int n=nums.size();
    if(ind==n)
    {
        return 0;
    }
    int nottake=0+cal(ind+1,prev,nums);
    int take=0;
    if(prev==-1||nums[ind]>nums[prev])
    {
        take=1+cal(ind+1,ind,nums);
    }
    return max(take,nottake);
}
// tabulation
    int lengthOfLIS(vector<int>& nums) {
//  return cal(0,-1,nums);
int n=nums.size();
vector<vector<int>> dp(n+1,vector<int>(n+1,0));
for(int ind=n-1;ind>=0;ind--)
{
    for( int prev=ind-1;prev>=-1;prev--)
    {
         int nottake=0+dp[ind+1][prev+1];
    int take=0;
    if(prev==-1||nums[ind]>nums[prev])
    {
        take=1+dp[ind+1][ind+1];
    }
    dp[ind][prev+1]=max(take,nottake);
    }
}
return dp[0][0];

    
    }
};
// };      
// here we did coordinate shifting in tabualtion bcz base cnndition ind==n so n+1 and prev canot be -1 dp[0[-1] not valid so another shift of n+1;]  
    