// Last updated: 7/6/2026, 12:08:29 PM
class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> min;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums)
        {
            add(num);
        }
    }
    
    int add(int val) {
        min.push(val);
        if(min.size()>k)
        {
            min.pop();
        }
return min.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */