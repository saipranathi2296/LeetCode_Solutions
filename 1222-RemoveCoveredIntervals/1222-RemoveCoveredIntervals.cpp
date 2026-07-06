// Last updated: 7/6/2026, 12:08:00 PM
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=n;
             sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
       {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        else
        {
            return a[0]>b[0];
        }
       });
       for(int i =0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
            if(intervals[i][1]> intervals[j][1])
            {
                continue;
            }
            else
            {
count--;
break;
            }
        }
       }
       return count;
    }
};