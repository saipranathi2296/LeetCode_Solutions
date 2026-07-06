// Last updated: 7/6/2026, 12:07:10 PM
class Solution {
public:
int ans=INT_MAX;
void dfs(int node,vector<vector<pair<int,int>>>& adj, vector<int>&vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        int adjnode=it.first;
        int adjwei=it.second;
        ans=min(ans,adjwei);
        if(!vis[adjnode])
        {

            dfs(adjnode,adj,vis);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1,0);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        dfs(1,adj,vis);
        return ans;
    }
};