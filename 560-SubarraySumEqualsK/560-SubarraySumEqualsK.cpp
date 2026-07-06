// Last updated: 7/6/2026, 12:08:47 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        int sum=0,count=0;
        ans[0]=1;
        for(int i=0;i<nums.size();i++)
        {
sum+=nums[i];
if(ans.find(sum-k)!=ans.end())
{
    count+=ans[sum-k];
}
ans[sum]+=1;

        }
return count;
    }
};