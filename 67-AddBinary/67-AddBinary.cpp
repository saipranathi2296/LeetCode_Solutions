// Last updated: 7/6/2026, 12:11:15 PM
class Solution {
public:
    string addBinary(string a, string b) {
        int first = a.size() - 1;
        int second = b.size() - 1;
        int carry = 0;
        string res = "";
        while (first >= 0 || second >= 0 || carry) {
            int sum = carry;
            if (first >= 0)
                sum += a[first--] - '0';
            if (second >= 0)
                sum += b[second--] - '0';
            res += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};