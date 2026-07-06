// Last updated: 7/6/2026, 12:10:53 PM
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
    // Helper function to check mirror
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;            // Both null → mirror
        if (!t1 || !t2) return false;           // One null → not mirror
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) && // left of t1 ↔ right of t2
               isMirror(t1->right, t2->left);   // right of t1 ↔ left of t2
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;                 // Empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
