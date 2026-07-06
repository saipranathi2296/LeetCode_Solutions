// Last updated: 7/6/2026, 12:07:45 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3]={0,0,0};
        int n=s.length();
        int l=0;
        int ans=0;
        for(int r=0;r<s.length();r++)
        {
            cnt[s[r]-'a']++;
            while(cnt[0]>0 &&cnt[1]>0&&cnt[2]>0)
            {
                ans+=(n-r);
                cnt[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};