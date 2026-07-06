// Last updated: 7/6/2026, 12:07:19 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         vector<int> result;
        int i;
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++)
        {
        if(nums[i]==target)
        {
            result.push_back(i);
        }
        }
        return result;
    }
        
    
};