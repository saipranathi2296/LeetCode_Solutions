// Last updated: 7/6/2026, 12:11:51 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // store value with original index
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // sort by value
        sort(arr.begin(), arr.end());

        int l = 0, r = n - 1;

        while(l < r) {
            int sum = arr[l].first + arr[r].first;

            if(sum == target) {
                return {arr[l].second, arr[r].second}; // original indices
            }
            else if(sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return {-1, -1};
    }
};
