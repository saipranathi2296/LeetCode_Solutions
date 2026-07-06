// Last updated: 7/6/2026, 12:11:00 PM
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
        
    }
    void inorder(TreeNode* toot,vector<int> &ans)
    {
        if(!toot) return;
        inorder(toot->left,ans);
        ans.push_back(toot->val);
        inorder(toot->right,ans);
    }
};