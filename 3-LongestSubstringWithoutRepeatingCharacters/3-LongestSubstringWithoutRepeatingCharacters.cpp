// Last updated: 7/6/2026, 12:11:48 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> ans;
        int l=0,r=0;
        int an=0;
        while( r<s.size()){
       
        while(find(ans.begin(),ans.end(),s[r])!=ans.end())
        {
            ans.erase(ans.begin());
            l++;


        }
        ans.push_back(s[r]);
an=max(an,r-l+1);
r++;

        }
        return an;
    }
};