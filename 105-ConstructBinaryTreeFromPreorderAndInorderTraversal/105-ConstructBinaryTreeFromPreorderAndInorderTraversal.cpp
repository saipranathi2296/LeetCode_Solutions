// Last updated: 7/6/2026, 12:10:43 PM
class Solution {
public:
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            inorderIndexMap[inorder[i]] = i;

        int index = 0;
        return helper(preorder, index, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int& index, int inStart, int inEnd) {
        if(inStart > inEnd) return nullptr;

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndexMap[rootVal];

        root->left = helper(preorder, index, inStart, mid - 1);
        root->right = helper(preorder, index, mid + 1, inEnd);

        return root;
    }
};
