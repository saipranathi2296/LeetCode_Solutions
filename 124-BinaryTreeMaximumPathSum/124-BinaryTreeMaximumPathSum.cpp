// Last updated: 7/6/2026, 12:10:30 PM
class Solution {
    int check(TreeNode* root, int &maxi) {
        if (root == nullptr) return 0;

        int left = max(0, check(root->left, maxi));
        int right = max(0, check(root->right, maxi));

        int curr = root->val + left + right;
        maxi = max(maxi, curr);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        check(root, maxi);
        return maxi;
    }
};
