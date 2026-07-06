// Last updated: 7/6/2026, 12:09:16 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       /* unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans[nums[i]]++;
        }
        for( auto &it:ans)
        {
            if(it.second>=2)
            {
                return it.first;
            }
        }
        return -1;
    }
    */
    /*
    unordered_set<int>ans;
    for(int i=0;i<nums.size();i++)
    {
      if(ans.find(nums[i])!=ans.end())
      {
       return nums[i];
        
      }
      else
      {
       ans.insert(nums[i]);
      }
    }
    return -1;
    }*/
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];

    }while(slow!=fast);
    fast=nums[0];
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];

    }
    return slow;
    }
};