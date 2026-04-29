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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<int, TreeNode* > ans = traverse(root, p, q);

        return ans.second;
    }

    pair<int, TreeNode*> traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return {0, NULL};

        pair<int, TreeNode* > lfound = traverse(root->left, p, q);
        pair<int, TreeNode* > rfound = traverse(root->right, p, q);

        int curr = root == p || root == q; 
        int total = lfound.first + rfound.first + curr;

        if (lfound.second) {
            return {2, lfound.second};
        }

        if (rfound.second) {
            return {2, rfound.second};
        }

        if (total == 2) {
            return { 2, root};
        }

        return {total, NULL};
    }
};
