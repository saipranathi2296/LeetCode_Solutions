// Last updated: 7/6/2026, 12:10:41 PM
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
unordered_map<int,int> inor;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            inor[inorder[i]]=i;

        }
        return helper(postorder,0,inorder.size()-1,index);

    }
    TreeNode* helper(vector<int> &postorder,int low,int high,int &index)
    
    {
        if(low>high) return nullptr;
        int val=postorder[index--];
        TreeNode* root=new TreeNode (val);
        int ind=inor[val];
        root->right=helper(postorder,ind+1,high,index);
        root->left=helper(postorder,low,ind-1,index);
return root;

    }
};