// Last updated: 7/6/2026, 12:08:59 PM
class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int parts = 1;
        int currSum = 0;

        for (int x : nums) {
            if (currSum + x > maxSum) {
                parts++;
                currSum = x;
            } else {
                currSum += x;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
