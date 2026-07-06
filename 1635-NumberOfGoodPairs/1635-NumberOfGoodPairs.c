// Last updated: 7/6/2026, 12:07:40 PM
int numIdenticalPairs(int* nums, int numsSize) {
    int total=0;
    int n=numsSize;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i] == nums[j])
            {
                total+=1;
            }
        }
    }
    return total;
}