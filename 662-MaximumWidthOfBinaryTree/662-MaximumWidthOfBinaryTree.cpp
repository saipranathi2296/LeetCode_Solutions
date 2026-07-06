// Last updated: 7/6/2026, 12:08:40 PM
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            long long first, last;

            for (int i = 0; i < size; i++) {
                auto node = q.front().first;
                long long value = q.front().second;
                q.pop();

                if (i == 0) first = value;
                if (i == size - 1) last = value;

                if (node->left)
                    q.push({node->left, 2 * value + 1 - first});
                if (node->right)
                    q.push({node->right, 2 * value + 2 - first});
            }

            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};
