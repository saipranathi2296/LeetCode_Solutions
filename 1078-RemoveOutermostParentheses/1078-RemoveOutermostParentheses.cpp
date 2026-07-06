// Last updated: 7/6/2026, 12:08:07 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int count=0;
        for(char ch : s)
        {
            if(ch=='(')
            {
if(count>0) result+=ch;
count++;
            }
            else
            {
                count--;
               if(count>0)
               { result+=ch;
               }
            }
        }
return result;
    }
};