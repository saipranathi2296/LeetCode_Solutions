// Last updated: 7/6/2026, 12:07:44 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0,rsum=0,maxsum=0;
        if(k>n) return 0;
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        maxsum=lsum;
       int i=k-1;
       int j=n-1;
       while(i>=0)
       {
        lsum-=cardPoints[i];
        rsum+=cardPoints[j];
        maxsum=max(maxsum,lsum+rsum);
        i--;
        j--;
       }
       return maxsum;
    }
};
//you can only pick elemnts from end so u did not wite code fro move winfow from left ot right