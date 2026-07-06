// Last updated: 7/6/2026, 12:08:23 PM
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        // Build parent map inline
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q1;
        q1.push(root);
        while (!q1.empty()) {
            TreeNode* node = q1.front();
            q1.pop();
            if (node->left) {
                parent[node->left] = node;
                q1.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q1.push(node->right);
            }
        }
        // BFS from target to find distance K
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                // Right child
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                // Parent
                if (parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            dist++;
        }

        return {};
    }
};
