// Last updated: 7/6/2026, 12:08:11 PM
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
int index=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return con(preorder,INT_MIN,INT_MAX);
    }
    TreeNode* con(vector<int> &preorder,int lower,int upper)
    {

if(index>=preorder.size()) return nullptr;
int val=preorder[index];
if(val<lower|| val>upper) return nullptr;
index++;
TreeNode * root=new TreeNode(val);
root->left=con(preorder,lower,val);
root->right=con(preorder,val,upper);
return root;
    }
};