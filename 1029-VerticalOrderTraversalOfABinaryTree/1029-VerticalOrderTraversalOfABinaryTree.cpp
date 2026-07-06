// Last updated: 7/6/2026, 12:08:17 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        // BFS queue: node, row, col
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}}); // root: row=0, col=0

        // map of (col,row) -> multiset of node values
        map<pair<int,int>, multiset<int>> nodes;

        int minCol = 0, maxCol = 0;

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            nodes[{col,row}].insert(node->val);

            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if (node->left) q.push({node->left, {row+1, col-1}});
            if (node->right) q.push({node->right, {row+1, col+1}});
        }

        // Collect results column by column
        for (int col = minCol; col <= maxCol; ++col) {
            vector<int> colVals;
            for (auto& kv : nodes) {
                if (kv.first.first == col) { // same column
                    colVals.insert(colVals.end(), kv.second.begin(), kv.second.end());
                }
            }
            res.push_back(colVals);
        }

        return res;
    }
};
