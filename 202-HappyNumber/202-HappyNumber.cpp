// Last updated: 7/6/2026, 12:09:47 PM
class Solution {
public:
int sq(int n)
{
    int sum=0;
    while(n>0)
    {
        int digit=n%10;
        sum+=digit*digit;
        n/=10;

    }
    return sum;
}
    bool isHappy(int n) {
       int slow=n;
    int fast=n;
    do
    {
        slow=sq(slow);
        fast=sq(sq(fast));

    }while(slow!=fast);
    return slow==1;

    }
};