// Last updated: 7/6/2026, 12:07:29 PM
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int *ans =(int *)malloc ( numsSize * sizeof(int));
    * returnSize=numsSize;
    for (int i=0;i<numsSize;i++)
    {
        ans[i]=nums[nums[i]];
    }
    return ans;
}