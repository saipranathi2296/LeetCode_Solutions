// Last updated: 7/6/2026, 12:08:28 PM
class Solution {
    bool dfs(vector<vector<int>>& graph,vector<int> &color,int i)
    {
        color[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for( auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }

return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int> color(n,-1);
       for(int i=0;i<n;i++)
       {
        if(color[i]==-1)
        {
            if(!dfs(graph,color,i)) return false;
            
        }
       }
    
    return true;
    }
};