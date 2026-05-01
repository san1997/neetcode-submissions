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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }

    TreeNode* build(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij) {
        cout << pi << " " << pj << endl;
        if (pi > pj  || ii > ij) {
            return nullptr;
        }
        
        if (pi == pj) {
            TreeNode* node = new TreeNode(preorder[pi]);
            return node;
        }

        int val = preorder[pi];
        int ind = -1;
        for(int i=ii; i<=ij; i++) {
            if (inorder[i] == val) {
                ind = i;
                break;
            }
        }

        int leftsize = ind - ii;

        TreeNode* left = build(preorder, pi+1, pi+leftsize, inorder, ii, ind-1);
        TreeNode* right = build(preorder, pi + leftsize+1, pj, inorder, ind+1, ij);
        TreeNode* root = new TreeNode(val, left, right);
        
        return root;

    }
};
