// Last updated: 7/6/2026, 12:06:59 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
    //     int i=0;
    //     for(int j=0;j<nums.size();j++)
    //     {
    //         if(nums[j]!=0)
    //         {
               
    //             int temp=nums[i];
    //             nums[i]=nums[j];
    //             nums[j]=temp;
    //             i++;
    //         }
    //     }
    //     return i;
    // }
       int n=nums.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }
        int ans=0;
        for(int i=n-count;i<n;i++)
        {
            if(nums[i]!=0)  ans++;
        }
        return ans;
    }
    
};