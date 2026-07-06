// Last updated: 7/6/2026, 12:11:47 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
                
                if(prefix == "")
                    return "";
            }
        }
        
        return prefix;
    }
};