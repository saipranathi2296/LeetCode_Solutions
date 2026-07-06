// Last updated: 7/6/2026, 12:11:32 PM
class Solution {

public:
vector<int> temp;
vector<vector<int>> ans;
void solve(int ind,vector<int>& candidates,int target)
{
    if(target==0)
    {
         ans.push_back(temp);
         return;
    }
    if(ind<0) return;
    if(candidates[ind]<=target)
    {
        temp.push_back(candidates[ind]);
    solve(ind,candidates,target-candidates[ind]);
    temp.pop_back();
    }
    solve(ind-1,candidates,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        solve(n-1,candidates,target);
        return ans;
    }
};