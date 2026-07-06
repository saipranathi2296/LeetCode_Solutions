// Last updated: 7/6/2026, 12:10:14 PM
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        post(root,res);
        return res;
    }
    void post(TreeNode* toot,vector<int> & ans)
    {
        if(!toot) return;
        post(toot->left,ans);
        post(toot->right,ans);
        ans.push_back(toot->val);

    }
};