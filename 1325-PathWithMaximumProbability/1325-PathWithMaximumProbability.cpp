// Last updated: 7/6/2026, 12:07:55 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        priority_queue<pair<double,int>> pq; // max-heap
        vector<double> dist(n, 0.0);

        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) return prob;

          

            for (auto &nei : adj[node]) {
                int next = nei.first;
                double edgeProb = nei.second;

                if (dist[next] < prob * edgeProb) {
                    dist[next] = prob * edgeProb;
                    pq.push({dist[next], next});
                }
            }
        }

        return 0.0;
    }
};
