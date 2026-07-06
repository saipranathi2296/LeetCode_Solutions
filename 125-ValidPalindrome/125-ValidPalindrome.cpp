// Last updated: 7/6/2026, 12:10:29 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";

        for (char ch : s) {
            if (isalnum(ch)) {
                result += tolower(ch);
            }
        }

        int i = 0, j = result.size() - 1;
        while (i < j) {
            if (result[i] != result[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
