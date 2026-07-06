// Last updated: 7/6/2026, 12:07:07 PM
class Solution {
public:
    void dfs1(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs1(it, vis, adj, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<int>& vis, vector<vector<int>>& adjT,
              int &nodes, int &edges) {
        vis[node] = 1;
        nodes++;
        edges += adjT[node].size();   // count incoming edges

        for (auto it : adjT[node]) {
            if (!vis[it])
                dfs2(it, vis, adjT, nodes, edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n), adjT(n);

        // Undirected graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        stack<int> st;

        // Step 1: Topo DFS
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs1(i, vis, adj, st);
        }

        // Step 2: Transpose + reset vis (Striver way)
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        int scc = 0;

        // Step 3: Unstack and DFS
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!vis[node]) {
                int nodes = 0, edges = 0;
                dfs2(node, vis, adjT, nodes, edges);

                edges /= 2;  // undirected

                if (edges == (nodes * (nodes - 1)) / 2)
                    scc++;
            }
        }

        return scc;
    }
};
