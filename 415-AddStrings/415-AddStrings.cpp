// Last updated: 7/6/2026, 12:08:57 PM
class Solution {
public:
    string addStrings(string num1, string num2) {
        int first=num1.size()-1;
        int second=num2.size()-1;
        int carry=0;
        string res;
        while(first>=0||second>=0||carry)
        {
            int sum=carry;
if(first>=0)
{
sum+=num1[first--]-'0';
}
if(second>=0)
{
    sum+=num2[second--]-'0';

}
res+=(sum%10)+'0';
carry=sum/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};