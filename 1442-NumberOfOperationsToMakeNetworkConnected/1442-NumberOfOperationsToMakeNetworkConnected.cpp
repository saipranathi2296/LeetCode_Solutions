// Last updated: 7/6/2026, 12:07:48 PM
class Solution {
public:
    
    vector<int> parent, rank;
    
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if (u == v) return;
        
        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        // Not enough cables
        if (connections.size() < n - 1)
            return -1;
        
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        // Union all connections
        for (auto &it : connections) {
            unionSet(it[0], it[1]);
        }
        
        // Count connected components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (findParent(i) == i)
                components++;
        }
        
        // Minimum operations needed
        return components - 1;
    }
};
