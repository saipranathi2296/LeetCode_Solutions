// Last updated: 7/6/2026, 12:08:14 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
int t=0;
        vector<vector<int>> vis;
int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {                
                q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }

            }
        }
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
           t=q.front().second;
          q.pop();
          
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
                 for(int k=0;k<4;k++)
                 {
                    int nrow=r+delrow[k];
                    int ncol=c+delcol[k];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1)
                    {
                        grid[nrow][ncol]=2;
                        fresh--;
                        q.push({{nrow,ncol},t+1});

                    }
                 } 

                    }
                    if(fresh>0) return -1;
                     return t;
    }
};