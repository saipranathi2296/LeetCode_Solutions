// Last updated: 7/6/2026, 12:09:48 PM
class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<int>> &vis)
    {

int n=grid.size();
int m=grid[0].size();
if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0'||vis[i][j]==1) return;
vis[i][j]=1;
dfs(grid,i+1,j,vis);
dfs(grid,i-1,j,vis);
dfs(grid,i,j+1,vis);
dfs(grid,i,j-1,vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&& vis[i][j]==0)
                {
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};