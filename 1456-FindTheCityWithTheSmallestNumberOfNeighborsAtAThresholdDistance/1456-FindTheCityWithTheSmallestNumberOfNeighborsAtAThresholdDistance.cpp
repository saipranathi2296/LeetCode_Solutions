// Last updated: 7/6/2026, 12:07:46 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        
        // Fill initial edges
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w; // undirected
        }
        
        // Floyd-Warshall: compute shortest distances
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        // Count reachable cities within threshold
        int minCount = n+1, city = -1;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            // choose smallest count, if tie choose largest city number
            if(count <= minCount) {
                minCount = count;
                city = i;
            }
        }
        
        return city;
    }
};