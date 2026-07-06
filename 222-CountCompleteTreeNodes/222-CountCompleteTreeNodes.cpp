// Last updated: 7/6/2026, 12:09:34 PM
class Solution {
public:
    int lefth(TreeNode* root) {
        int h = 0;
        while (root != nullptr) {
            h++;
            root = root->left;
        }
        return h;
    }

    int righth(TreeNode* root) {
        int h = 0;
        while (root != nullptr) {
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = lefth(root);
        int rh = righth(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
