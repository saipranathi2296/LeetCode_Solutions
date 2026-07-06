// Last updated: 7/6/2026, 12:08:55 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
       int maxi=INT_MIN; 
       if(nums.size()==1 &&  nums[0]==1) return 1;
       if(nums.size()==1 && nums[0]!=1) return 0;
      for(int i=0;i<nums.size();i++)
      {
if(count==0 &&nums[i]==1)
{
    count=1;
  
}
else if(nums[i]==1)
{
    count++;
   
}
else
{
    count=0;
}
 maxi=max(maxi,count);
      }
      return (maxi==INT_MIN)?0:maxi;
    }
};