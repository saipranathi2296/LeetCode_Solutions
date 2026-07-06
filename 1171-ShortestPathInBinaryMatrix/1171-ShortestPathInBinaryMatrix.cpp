// Last updated: 7/6/2026, 12:08:01 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<pair<int,pair<int,int>>> q;
       q.push({1,{0,0}});
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> dis(n,vector<int>(m,1e9));
       if(grid[0][0]==1|| grid[n-1][m-1]==1) return -1;
       dis[0][0]=1;
       while(!q.empty())
       {
        auto node=q.front();
        q.pop();
        int dist=node.first;
        int r=node.second.first;
        int c=node.second.second;
        if(r==n-1 && c==m-1) return dist;
        vector<int> delRow = {-1, -1, -1,  0, 0,  1, 1, 1};
vector<int> delCol = {-1,  0,  1, -1, 1, -1, 0, 1};
for(int k=0;k<8;k++)
{
    int nrow=delRow[k]+r;
    int ncol=delCol[k]+c;
   
    if(nrow>=0 && nrow<n &&ncol >=0 &&ncol<m && grid[nrow][ncol]==0 && 1+dist<dis[nrow][ncol])
    {
        dis[nrow][ncol]=1+dist;
    q.push({dis[nrow][ncol],{nrow,ncol}});
    }
   

}
       } 
       return -1;
    }
};