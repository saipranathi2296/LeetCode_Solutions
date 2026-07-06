// Last updated: 7/6/2026, 12:09:39 PM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        // Build graph and indegree
        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]); // b -> a
            indeg[it[0]]++;
        }

        queue<int> q;
        // Push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        vector<int> res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }

        if (res.size() == numCourses)
            return res;
        return {};
    }
};
