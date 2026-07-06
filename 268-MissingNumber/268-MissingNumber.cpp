// Last updated: 7/6/2026, 12:09:19 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      /*  sort(nums.begin(),nums.end());
    
       for(int  i=0;i<nums.size();i++)
       {
if(nums[i]!=i) return i;
if(i==(nums.size()-1)&& nums[i]==i) return i+1;
       }
      return -1;
 */
 int n=nums.size();
 int miss=n;
 for(int i=0;i<n;i++)
 {
 miss^=i^nums[i];
 } 
 return miss;
}
};