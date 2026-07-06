// Last updated: 7/6/2026, 12:09:27 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;           // Base case: empty tree
        if (root == p || root == q) return root; // If root is one of p or q, it is LCA

        // Recurse into left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in different subtrees, root is LCA
        if (left && right) return root;

        // Else, LCA is in the subtree where at least one is found
        return left ? left : right;
    }
};
