// Last updated: 7/6/2026, 12:09:00 PM
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

    // Step 0: Sort the array
    sort(nums.begin(), nums.end());

    // dp[i] = size of largest divisible subset ending at index i
    vector<int> dp(n, 1);

    int maxi = 1;
    int max_idx = 0;

    // Step 1: Build dp array (LIS style)
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0)
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        if (dp[i] > maxi)
        {
            maxi = dp[i];
            max_idx = i;
        }
    }

    // Step 2: Backtrack and store answer
    vector<int> ans;

    while (max_idx >= 0)
    {
        ans.push_back(nums[max_idx]);

        int idx = max_idx - 1;
        while (idx >= 0)
        {
            if (nums[max_idx] % nums[idx] == 0 &&
                dp[idx] + 1 == dp[max_idx])
            {
                break;
            }
            idx--;
        }

        max_idx = idx;
    }

    // Reverse to get correct order
    reverse(ans.begin(), ans.end());

    return ans;
    }
};