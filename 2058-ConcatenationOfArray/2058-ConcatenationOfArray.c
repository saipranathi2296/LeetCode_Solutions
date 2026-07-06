// Last updated: 7/6/2026, 12:07:27 PM
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int *ans=(int *)malloc(2 * numsSize * sizeof(int));
   int  n=numsSize;
    *returnSize =2 * numsSize;
    for(int i=0;i<numsSize;i++)
    {
        ans[i]=nums[i];
        ans[i+n] = nums[i];
    }
    return ans;
    
}