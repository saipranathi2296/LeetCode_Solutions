// Last updated: 7/6/2026, 12:10:58 PM
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
    bool valid(TreeNode*root,long long low,long long high)
    {
        if(root==NULL) return true;
        if(root->val<=low||root->val>=high)
        {
            return false;
        }
        return valid(root->left,low,root->val)&&valid(root->right,root->val,high);
    }
public:
    bool isValidBST(TreeNode* root) {
    if(  valid(root,LLONG_MIN,LLONG_MAX))
    {
        return true;
    }
else
{
    return false;
}
    }
};