// Last updated: 7/6/2026, 12:10:57 PM
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
TreeNode* first;
TreeNode* prev;
TreeNode* middle;
TreeNode* last;
void inorder(TreeNode*node)
{
    if(node==NULL) return;
    inorder(node->left);
    if(prev!=NULL && prev->val>node->val)
    {
        if(first==NULL)
        {
first=prev;
middle=node;

        }
        else
        {
            last=node;
        }
       
    }
     prev=node;
        inorder(node->right);
}
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=NULL;
        inorder(root);
        if(first&&last) swap(first->val,last->val);
       else if(first&& middle) swap(first->val,middle->val);    }
};