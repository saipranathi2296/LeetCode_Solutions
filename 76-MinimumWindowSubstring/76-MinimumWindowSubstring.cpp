// Last updated: 7/6/2026, 12:11:06 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int left=0,right=0;
        int mini=INT_MAX;
        int start=0;
        unordered_map<char,int> mp;
        for(char c:t)
        {
            mp[c]++;

        }
        int count=t.size();
        int n=s.size();
        while(right<n)
        {
          if(mp[s[right]]>0)
          {
count--;
          }
          mp[s[right]]--;
          while(count==0)
{
          if(right-left+1 < mini) {
                   mini = right-left+1;
                    start = left;
                }  
          mp[s[left]]++;
          if(mp[s[left]]>0) count++;
          left++;
        }
right++;
    }
      if(mini == INT_MAX)
            return "";
    return s.substr(start,mini);
    }
};