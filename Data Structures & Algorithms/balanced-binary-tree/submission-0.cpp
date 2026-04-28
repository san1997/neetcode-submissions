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
    bool isBalanced(TreeNode* root) {
        pair<bool, int> cur = height(root);

        return cur.first; 
    }

    pair<bool, int> height(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }

        pair<bool, int> left = height(root->left);
        pair<bool, int> right = height(root->right);

        bool isbalanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = max(left.second, right.second) + 1;

        cout << root->val << " " << isbalanced << " " << height << endl;
        return {isbalanced, height};

    }
};
