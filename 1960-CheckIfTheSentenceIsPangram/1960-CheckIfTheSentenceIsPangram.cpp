// Last updated: 7/6/2026, 12:07:31 PM
class Solution {
public:
    bool checkIfPangram(string sentence) {
       int arr[26]={0};
       for(char c:sentence)
       {
        arr[c-'a']++;
       } 
       for(int i=0;i<26;i++)
       {
        if(arr[i]==0)
        {
            return false;
        }
       }
       return true;
    }
};