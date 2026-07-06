// Last updated: 7/6/2026, 12:07:04 PM
int minimumOperations(int* nums, int numsSize) {
    int sum=0;
     int diff=0;
     int Operations=0;
    for(int i=0;i<numsSize;i++)
    {
       
         if(nums[i]%3!=0)
        {
if((nums[i]+1)%3==0)
{

sum+=1;
}
else
{
   
    diff+=1;
}
        
        
    }

    }
    Operations=sum+diff;
        return Operations;
}

    
