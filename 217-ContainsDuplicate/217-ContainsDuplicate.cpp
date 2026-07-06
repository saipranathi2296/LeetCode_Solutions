// Last updated: 7/6/2026, 12:09:35 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num: nums)
        {
            if(seen.find(num)!=seen.end())
            {
                return true;
               
        }
        seen.insert(num);
        }
        return false;
    }

};