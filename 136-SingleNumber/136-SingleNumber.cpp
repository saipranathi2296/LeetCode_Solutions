// Last updated: 7/6/2026, 12:10:21 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo=0;
        for(int i=0;i<nums.size();i++)
        {
            xo^=nums[i];

        }
        return xo;
    }
};