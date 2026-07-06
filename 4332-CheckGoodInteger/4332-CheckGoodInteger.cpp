// Last updated: 7/6/2026, 12:06:57 PM
class Solution {
public:
 

    bool checkGoodInteger(int n) {
        string s=to_string(n);
        int sum=0;
        int sq=0;
        for(char ch: s)
            {
            int digit=ch-'0';
            sum+=digit;
                sq+=digit*digit;
            }
        if(sq-sum>=50) return true;
        else return false;
    }
};
        
