// Last updated: 7/6/2026, 12:11:08 PM
class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low+=1;
                mid+=1;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high-=1;
            }
        }
    }
};