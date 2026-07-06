// Last updated: 7/6/2026, 12:08:25 PM
class Solution {
public:
bool dfs(vector<vector<int>>& graph, vector<int>&vis,vector<int>&pathvis,  vector<int>&check,int node)
{
    vis[node]=1;
    pathvis[node]=1;
    for(auto adj:graph[node])
    {
        if(!vis[adj])
        {
            if(dfs(graph,vis,pathvis,check,adj)) 
            {
                check[node]=0;
                return true;
            }
        }
            else if(pathvis[adj])
            {
                check[node]=0;
                return true;
            }
        
    }
    pathvis[node]=0;
    check[node]=1;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>check(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,pathvis,check,i);
            }
        }
        vector<int>safenode;
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
            {
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};