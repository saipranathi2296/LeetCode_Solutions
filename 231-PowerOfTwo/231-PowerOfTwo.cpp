// Last updated: 7/6/2026, 12:09:31 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
};