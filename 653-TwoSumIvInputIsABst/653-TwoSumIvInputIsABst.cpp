// Last updated: 7/6/2026, 12:08:42 PM
/**
 * Definition for a binary tree node.
 */


class BSTIterator {
    std::stack<TreeNode*> st;
    bool reverse;  // false = in-order (left to right), true = reverse in-order (right to left)

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = (reverse ? node->right : node->left);
        }
    }

    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        if (!reverse) pushAll(tmp->right);  // In-order: go right
        else pushAll(tmp->left);            // Reverse: go left
        return tmp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  // in-order
        BSTIterator r(root, true);   // reverse in-order

        int i = l.next();
        int j = r.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) i = l.next();
            else j = r.next();
        }

        return false;
    }
};
