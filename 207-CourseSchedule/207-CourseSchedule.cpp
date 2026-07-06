// Last updated: 7/6/2026, 12:09:42 PM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree
        for (auto it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; // number of courses completed

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            // Reduce indegree of neighbors
            for (auto neigh : adj[curr]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        // If we were able to finish all courses, return true
        return count == numCourses;
    }
};
