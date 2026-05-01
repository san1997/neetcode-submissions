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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSum(root, ans);

        return ans;
    }

    int maxSum(TreeNode* root, int &ans) {
        if (!root) {
            return 0;
        }

        int leftsum = maxSum(root->left, ans);
        int rightsum = maxSum(root->right, ans);

        int currmax = root->val;
        if (leftsum > 0) {
            currmax += leftsum;
        }
        if (rightsum > 0) {
            currmax += rightsum;
        }

        ans = max(ans, currmax);

        return root->val + max(0, max(leftsum, rightsum));
    }
};
