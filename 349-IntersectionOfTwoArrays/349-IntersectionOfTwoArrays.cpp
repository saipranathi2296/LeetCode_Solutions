// Last updated: 7/6/2026, 12:09:01 PM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
          sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0,j=0;
        vector<int>result;
        while(i<n1 && j<n2)
        {
            if(i>0 && nums1[i]==nums1[i-1])
            {
                i++;
                continue;
            }
            if(j>0 && nums2[j]==nums2[j-1])
            {
                j++;
                continue;
            }
            if(nums1[i]>nums2[j])
            {
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                result.push_back(nums1[i]);
                i++;
                j++;
                
            }
        }
return result;
    }
};