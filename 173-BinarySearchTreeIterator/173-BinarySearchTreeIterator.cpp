// Last updated: 7/6/2026, 12:10:03 PM
class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        
        // If right child exists, process its left subtree
        if(node->right)
            pushAllLeft(node->right);
        
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
