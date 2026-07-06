// Last updated: 7/6/2026, 12:09:29 PM
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        if(root->val == p->val || root->val == q->val)
            return root;

        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root; // split case
    }
};
