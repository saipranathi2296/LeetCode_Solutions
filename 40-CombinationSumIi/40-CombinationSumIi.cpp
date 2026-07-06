// Last updated: 7/6/2026, 12:11:30 PM
class Solution {
    void find(int index, int target, vector<int>& candidates,
              vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);
            find(i + 1, target - candidates[i], candidates, ds, ans);
            ds.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());  // Step 1: sort the input
        find(0, target, candidates, ds, ans);
        return ans;
    }
};
