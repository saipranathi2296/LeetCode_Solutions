// Last updated: 7/6/2026, 12:08:50 PM
class Solution {
    int maxi = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        // update diameter (in terms of edges)
        maxi = max(maxi, left + right);

        // return height of tree
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};
