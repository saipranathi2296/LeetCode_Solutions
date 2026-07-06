// Last updated: 7/6/2026, 12:07:11 PM
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {

        // Step 1: Build parent map (same as LC 863)
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: Find the start node (same as finding target in 863)
        TreeNode* startNode = nullptr;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) {
                startNode = node;
                break;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        // Step 3: BFS from start (same as LC 863)
        queue<TreeNode*> bfs;
        unordered_set<TreeNode*> visited;

        bfs.push(startNode);
        visited.insert(startNode);

        int time = 0;

        while(!bfs.empty()) {
            int size = bfs.size();
            bool spread = false;

            for(int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if(node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    bfs.push(node->left);
                  
                }

                if(node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    bfs.push(node->right);
                   
                }

                if(parent[node] && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    bfs.push(parent[node]);
                   
                }
            }

            if(!bfs.empty()) 
        time++;  // exactly like counting levels in 863
        }

        return time;
    }
};
