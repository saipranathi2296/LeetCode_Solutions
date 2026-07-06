// Last updated: 7/6/2026, 12:09:03 PM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        struct cmp {
            bool operator()(pair<int,int> a, pair<int,int> b) {
                return a.second < b.second; // max heap by frequency
            }
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> p;

        vector<int> result;

        for(int x : nums)
        {
            mp[x]++;
        }

        for(auto it : mp)
        {
            p.push({it.first, it.second});
        }

        while(k > 0)
        {
            result.push_back(p.top().first);
            p.pop();
            k--;
        }

        return result;
    }
};