// Last updated: 7/6/2026, 12:07:02 PM
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<int> indegree(n, 0);
        vector<vector<pair<int,int>>> adj(n);

        int maxi = INT_MIN;

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            indegree[it[1]]++;
            maxi = max(maxi, it[2]);
        }

        // Topological Sort
        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto &it : adj[node]) {

                int next = it.first;

                indegree[next]--;

                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        int low = 0;
        int high = maxi;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == LLONG_MAX)
                    continue;

                for (auto &it : adj[u]) {

                    int node = it.first;
                    int w = it.second;

                    if (w < mid)
                        continue;

                    if (node != n - 1 && !online[node])
                        continue;

                    dist[node] = min(dist[node], dist[u] + w);
                }
            }

            if (dist[n - 1] <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};