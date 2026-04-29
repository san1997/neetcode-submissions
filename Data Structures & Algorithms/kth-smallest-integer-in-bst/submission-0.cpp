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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;

        dfs(root, k, ans);

        return ans;
    }

    int dfs(TreeNode* node, int k, int &ans) {
        if (!node) {
            return 0;
        }

        int left = dfs(node->left, k, ans);

        if (left + 1 == k) {
            ans = node->val;
        }

        int right = dfs(node->right, k - left - 1, ans);

        return left + right + 1;
    }
};
