// Last updated: 7/6/2026, 12:11:39 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int  i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];

            }
        }
        return i+1;
    }
};