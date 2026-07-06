// Last updated: 7/6/2026, 12:10:15 PM
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);      // helper call
        return res;
    }

private:
    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        res.push_back(node->val);         // 1. Visit root
        preorder(node->left, res);        // 2. Go left
        preorder(node->right, res);       // 3. Go right
    }
};
