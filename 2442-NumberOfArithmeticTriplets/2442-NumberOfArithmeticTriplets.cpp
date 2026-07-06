// Last updated: 7/6/2026, 12:07:13 PM
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i,j,k;
        int sum=0;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                for(k=j+1;k<nums.size();k++)
                {
                    if(nums[k]-nums[j]==diff && nums[j]-nums[i]==diff)
                    {
                        sum+=1;
                    }
                }
            }
        }
       return sum; 
    }
};