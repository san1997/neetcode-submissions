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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> ans = dfs(root);

        for (int i=1;i<ans.size(); i++) {
            if (ans[i]->val <= ans[i-1]->val) {
                return false;
            }
        }

        return true;
    }

    vector<TreeNode*> dfs(TreeNode* node) {
        if (!node) {
            return {};
        }

        vector<TreeNode*> left = dfs(node->left);
        vector<TreeNode*> right = dfs(node->right);

        vector<TreeNode*> ans;

        for (int i=0;i<left.size(); i++) {
            ans.push_back(left[i]);
        }
        ans.push_back(node);
        for(int i=0;i<right.size(); i++) {
            ans.push_back(right[i]);
        }

        return ans;
    }


};
