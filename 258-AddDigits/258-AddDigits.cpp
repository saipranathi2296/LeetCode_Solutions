// Last updated: 7/6/2026, 12:09:20 PM
class Solution {
public:
// int solve(int x)
// {
//      int sum=0;
//         while(x)
//         {
//             sum+=x%10;
//             x/=10;
//         }
//         return sum;
// }
    int addDigits(int num) {
    //  int ans=  solve(num);
    //    while(ans>=10)
    //    {
    //    ans= solve(ans);
    //    }
    //    return ans;
    if(num==0) return 0;
    else if(num%9==0)  return 9;
    else  return num%9;
        
    }
};