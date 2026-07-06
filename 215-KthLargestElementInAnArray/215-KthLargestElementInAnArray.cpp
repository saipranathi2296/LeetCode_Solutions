// Last updated: 7/6/2026, 12:09:36 PM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min;
        for(int num:nums)
        {
            min.push(num);
            if(min.size()>k)
            {
                min.pop();
            }
        }
        return min.top();

    }
};