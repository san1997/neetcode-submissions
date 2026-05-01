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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = serializeDFS(root);

        return ans;
    }

    string serializeDFS(TreeNode* root) {
        if (!root) {
            return "null#";
        }

        string s = to_string(root->val) + "#";
        s += serializeDFS(root->left);
        s += serializeDFS(root->right);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;

        int i = 0;
        while (i< data.size()) {
            int j = i;
            while (data[j] != '#') {
                j++;
            }

            string s = data.substr(i, j-i);

            arr.push_back(s);

            i = j+1;
        }

        for (int i=0; i<arr.size(); i++) {
            cout << arr[i] << " ";
        }

        int ind = 0;
        return dfs(arr, ind);
    }

    TreeNode* dfs(vector<string> &vec, int &i) {
        if (vec[i] == "null") {
            i++;
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(vec[i]));
        i++;
        node->left = dfs(vec, i);
        node->right = dfs(vec, i);

        return node;
    }

};
