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
    int goodNodes(TreeNode* root) {
        vector<pair<TreeNode*, int>> q = {{root, INT_MIN}};
        int ans = 0;

        while (q.size()) {
            vector<pair<TreeNode*, int>> tmp;

            for (int i=0; i<q.size(); i++) {
                int topmax = q[i].second;
                TreeNode* node = q[i].first;

                if (node->val >= topmax) {
                    ans++;
                    topmax = node->val;
                }

                if (node->left) {
                    tmp.push_back({ node->left, topmax });
                }

                if (node->right) {
                    tmp.push_back({ node->right, topmax });
                }
            }

            q = tmp;
        }

        return ans;
    }
};
