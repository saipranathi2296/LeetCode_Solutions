// Last updated: 7/6/2026, 12:06:58 PM
class Solution {
public:
    int getWeight(string &s,vector<int>& weights)
    {
        int sum = 0;
        for(char c : s)
        {
            sum+=weights[c-'a'];
        }
        return sum%26;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string s : words)
        {
            int w = getWeight(s,weights);
            char c = 'z' - w;
            ans.push_back(c);
        }
        return ans;
    }
};