// Last updated: 7/6/2026, 12:11:33 PM
// class Solution {
//     // int first(vector<int>&nums,int target)
//     // {
//     //     int low=0;
//     //     int high=nums.size()-1;
//     //     int first=nums.size();
//     //     while(low<=high)
//     //     {
//     //         int mid=low+(high-low)/2;
//     //         if(nums[mid]>=target)
//     //         {
//     //     first=mid;
//     //     high=mid-1;

//     //         }
//     //         else
//     //         {
//     //             low=mid+1;
//     //         }
//     //     }
//     //     return first;
//     // }
//     // int last(vector<int>&nums,int target)
//     // {
//     //     int low=0;
//     //     int high=nums.size()-1;
//     //     int last=nums.size();
//     //     while(low<=high)
//     //     {
//     //         int mid=low+(high-low)/2;
//     //         if(nums[mid]>target)
//     //         {
//     //     last=mid;
//     //    high=mid-1;

//     //         }
            
//     //         else
//     //         {
//     //             low=mid+1;
//     //         }
        
//     //     return last;
//     // }
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//     //     int firs=first(nums,target);
//     //    int las=last(nums,target);
//     // if(firs==nums.size()||nums[firs]!=target) return {-1,-1};
//     // return {firs,las-1};
//     // }
// };
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // search left side for earlier occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // search right side for later occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);
        return {first, last};
    }
};

