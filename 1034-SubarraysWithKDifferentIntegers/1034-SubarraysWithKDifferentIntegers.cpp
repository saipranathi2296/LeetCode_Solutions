// Last updated: 7/6/2026, 12:08:15 PM
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int count = 0;

        while (r < n) {
            
            mpp[nums[r]]++;
           

            
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
r++;
            
            count += r - l+1;
        }

        return count;
    }
};
