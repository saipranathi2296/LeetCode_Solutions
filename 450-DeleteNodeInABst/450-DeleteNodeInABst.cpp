// Last updated: 7/6/2026, 12:08:56 PM
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root) {
        TreeNode* curr = root;
        while (curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // 🎯 Node found

            // Case 1: Leaf node
            if (!root->left && !root->right) {
                return NULL;
            }

            // Case 2: One child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Case 3: Two children
            TreeNode* succ = inorderSuccessor(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
