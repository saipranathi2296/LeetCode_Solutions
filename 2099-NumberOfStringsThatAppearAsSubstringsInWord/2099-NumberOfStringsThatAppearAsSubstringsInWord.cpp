// Last updated: 7/6/2026, 12:07:24 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
       for(string it:patterns)
       {
       
if(word.find(it)!=string::npos)
{
    count++;

        }
       }
       return count;
    }
};