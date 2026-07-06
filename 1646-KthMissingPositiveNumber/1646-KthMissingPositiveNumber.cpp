// Last updated: 7/6/2026, 12:07:38 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mising=arr[mid]-(mid+1);
            if(mising<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low+k;
    }
};