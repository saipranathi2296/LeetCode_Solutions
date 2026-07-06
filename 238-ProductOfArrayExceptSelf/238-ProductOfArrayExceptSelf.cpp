// Last updated: 7/6/2026, 12:09:26 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i];
        }

        suff[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            suff[i] = suff[i+1] * nums[i];
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(i == 0)
                ans[i] = suff[1];
            else if(i == n-1)
                ans[i] = pref[n-2];
            else
                ans[i] = pref[i-1] * suff[i+1];
        }

        return ans;
    }
};