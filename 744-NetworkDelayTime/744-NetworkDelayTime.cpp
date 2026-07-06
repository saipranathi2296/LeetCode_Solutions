// Last updated: 7/6/2026, 12:08:35 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n + 1];
        for (auto &it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
