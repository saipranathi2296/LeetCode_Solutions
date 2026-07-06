// Last updated: 7/6/2026, 12:08:51 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                  
                    dist[i][j]=0;
                    q.push({i,j});
                }
               
              
            }
        }
    
    int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nrow=r+delRow[k];
                int ncol=c+delCol[k];
                  if(nrow >= 0 && nrow < n && ncol>= 0 && ncol < m && dist[nrow][ncol] == -1)
                  {
                    dist[nrow][ncol]=1+dist[r][c];
                    q.push({nrow,ncol});
                  }
            }
            
        }
        return dist;
    }
};