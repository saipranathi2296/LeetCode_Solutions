// Last updated: 7/6/2026, 12:11:35 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If found
            if (nums[mid] == target)
                return mid;

            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {
                // Target lies in left sorted half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Else, right half is sorted
            else {
                // Target lies in right sorted half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // target not found
    }
};
