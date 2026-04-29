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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<TreeNode*> nodevec = {root};
        vector<vector<int>> ans;

        while (nodevec.size()) {
            vector<TreeNode*> tmp;
            vector<int> numvec;

            for (int i=0; i<nodevec.size(); i++) {
                numvec.push_back(nodevec[i]->val);
                if (nodevec[i]->left) {
                    tmp.push_back(nodevec[i]->left);
                }

                if (nodevec[i]->right) {
                    tmp.push_back(nodevec[i]->right);
                }
            }

            ans.push_back(numvec);
            nodevec = tmp;
        }

        return ans;
    }
};
