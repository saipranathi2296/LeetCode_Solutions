// Last updated: 7/6/2026, 12:07:23 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int n=nums.size();
        int count=1;
        int mini=INT_MAX;
        int right=0;
        while(left<=right &&right<n)
        {
while(count>k)
{
    left++;
    count--;
}
if(count==k)
{
    mini=min(mini,abs(nums[left]-nums[right]));
    cout<<mini<<endl;
}
right++;
count++;
        }
return mini;
    }
};