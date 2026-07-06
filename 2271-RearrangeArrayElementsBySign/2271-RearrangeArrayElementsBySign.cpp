// Last updated: 7/6/2026, 12:07:17 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        // Separate positives and negatives
        for(int num : nums) {
            if(num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        int i = 0, j = 0;
        vector<int> ans;

        // Alternate till one finishes
        while(i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        // Remaining positives
        while(i < pos.size()) {
            ans.push_back(pos[i++]);
        }

        // Remaining negatives
        while(j < neg.size()) {
            ans.push_back(neg[j]);
            j++;
        }

        return ans;
    }
};
