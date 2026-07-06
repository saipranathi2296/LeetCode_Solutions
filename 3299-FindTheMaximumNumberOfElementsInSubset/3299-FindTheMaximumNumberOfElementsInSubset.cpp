// Last updated: 7/6/2026, 12:07:06 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        // Count frequency of every number
        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        // Try every distinct number as the starting value
        for (auto &[x, cnt] : freq) {

            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur)) {

                if (freq[cur] >= 2) {
                    // One copy for left, one copy for right
                    len += 2;

                    // Prevent overflow when squaring
                    if (cur > 1000000000LL)
                        break;

                    cur = cur * cur;
                }
                else {
                    // Only one copy -> becomes the center
                    len++;
                    break;
                }
            }

            // If chain ended with two copies instead of one,
            // remove one because center must appear only once.
            if (len % 2 == 0)
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};