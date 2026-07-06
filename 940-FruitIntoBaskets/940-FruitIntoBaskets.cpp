// Last updated: 7/6/2026, 12:08:20 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxlen = 0;
        unordered_map<int,int> mp;

        while (r < fruits.size()) {
            mp[fruits[r]]++;

            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
