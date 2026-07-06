// Last updated: 7/6/2026, 12:10:25 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> st(nums.begin(), nums.end());
        // int ans = 0;

        // while (!st.empty()) {
        //     int curr = *st.begin();
        //     st.erase(curr);

        //     int left = curr - 1;
        //     int right = curr + 1;

        //     while (st.count(left)) {
      //         st.erase(left);
        //         left--;
        //     }

        //     while (st.count(right)) {
        //         st.erase(right);
        //         right++;
        //     }

        //     ans = max(ans, right - left - 1);
        // }
        // return ans;
      if(nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int count = 1;
    int maxi = 1;

    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] == nums[i-1] + 1)
        {
            count++;
        }
        else if(nums[i] == nums[i-1])
        {
            continue;
        }
        else
        {
            count = 1;
        }

        maxi = max(maxi, count);
    }

    return maxi;
    }
};
