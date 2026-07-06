// Last updated: 7/6/2026, 12:08:04 PM
class Solution {
public:
  
        bool isPredecessor(string s1, string s2)
{
    if (s2.size() != s1.size() + 1)
        return false;

    int i = 0, j = 0;
    bool skipped = false;

    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (skipped)
                return false;
            skipped = true;
            j++;  // skip one char in s2
        }
    }

    return true;
}
  int longestStrChain(vector<string>& words) {

    int n = words.size();

    // Step 0: Sort by length
    sort(words.begin(), words.end(),
         [](string &a, string &b)
         {
             return a.size() < b.size();
         });

    // dp[i] = longest chain ending at words[i]
    vector<int> dp(n, 1);

    int maxi = 1;
    int max_idx = 0;

    // Step 1: DP (same LIS pattern)
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (isPredecessor(words[prev], words[i]))
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

    return maxi;
    }
};