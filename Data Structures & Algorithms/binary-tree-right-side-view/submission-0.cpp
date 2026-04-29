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
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> vec;
        vector<int> ans;

        if (root) {
            vec.push_back(root);
        }

        while(vec.size()) {
            ans.push_back(vec[0]->val);

            vector<TreeNode*> tmp;
            for (int i=0;i<vec.size(); i++) {
                if (vec[i]->right) {
                    tmp.push_back(vec[i]->right);
                }
                if (vec[i]->left) {
                    tmp.push_back(vec[i]->left);
                }
            }

            vec = tmp;
        }

        return ans;
    }
};
