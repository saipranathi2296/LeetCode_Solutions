// Last updated: 7/6/2026, 12:11:13 PM
class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        int mid;
        int res;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if((long)mid*mid>x)
            {
                high=mid-1;
            }
            else if((long)mid *mid<x)
            {
                low=mid+1;
                res=mid;
            }
            else
            {
return mid;
            }

        }
        return res;
    }
};