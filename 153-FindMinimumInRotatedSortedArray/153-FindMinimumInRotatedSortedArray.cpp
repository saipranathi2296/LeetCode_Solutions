// Last updated: 7/6/2026, 12:10:11 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Right half is sorted → min is in left half (including mid)
            if (nums[mid] < nums[high]) {
                high = mid;
            }
            // Left half is sorted → min is in right half
            else {
                low = mid + 1;
            }
        }

        return nums[low];
    }
};
