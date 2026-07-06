// Last updated: 7/6/2026, 12:07:56 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
       string s= "balloon";
       unordered_map<char,int> mp1;
       unordered_map<char,int>mp2;
       for(char ch:s)
       {
      mp1[ch]++;

       }
       for( char ch:text)
       {
        mp2[ch]++;
       }
       int mini=INT_MAX;
       for(auto it :mp1)
       {
         char ch = it.first;
       if(mp2.find(ch)!=mp2.end())
       {
        int a=mp1[ch];
        int b=mp2[ch];
        int c=b/a;
        mini=min(mini,c);
       } 
       else{
        return 0;
       }
       }
return mini;
    }
};