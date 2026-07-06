// Last updated: 7/6/2026, 12:07:35 PM
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max=0;
        int i,j;
        for(i=0;i<accounts.size();i++)
        {
            int sum=0;
            for(j=0;j<accounts[i].size();j++)
            {
               sum=sum+accounts[i][j];
            }
            if(sum>max)
            {
                max=sum;
            }
        }
return max;
        
    }
        
    
};