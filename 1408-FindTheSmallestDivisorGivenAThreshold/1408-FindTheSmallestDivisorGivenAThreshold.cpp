// Last updated: 7/6/2026, 12:07:50 PM
#include <vector>
#include <algorithm> // for max_element
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end()); // largest possible divisor
        int ans = high; // store the smallest valid divisor

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;

            // compute sum of ceil(nums[i] / mid)
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // ceil division trick
            }

            if (sum > threshold) {
                // divisor too small → sum too big → move right
                low = mid + 1;
            } else {
                // divisor works → try smaller one
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
