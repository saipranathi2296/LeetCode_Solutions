// Last updated: 7/6/2026, 12:07:33 PM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1) {
            arr[0]=1;
        }
        for(int i=1;i<arr.size();i++)
        {
            int val=abs(arr[i]-arr[i-1]);
           if(val>1)
           {
            arr[i]=arr[i-1]+1;
           }


        }
        int maxi=*max_element(arr.begin(),arr.end());
        return maxi;
    }
};