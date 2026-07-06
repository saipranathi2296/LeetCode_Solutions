// Last updated: 7/6/2026, 12:09:51 PM
class Solution {
public:

    int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,-1);
   int prev=nums[0];
   int secondprev=0;

    for(int i=1;i<n;i++)
    {int curr;
        int notp=prev;
        int pick=nums[i];
        if(i>1)
        {
            pick+=secondprev;
        }
        curr=max(pick,notp);
        secondprev=prev;
        prev=curr;

    }
   return prev;

    }
};