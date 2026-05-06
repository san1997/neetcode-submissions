/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mmap;

    Node* cloneGraph(Node* node)
    {
        return dfs(node);
    }

    Node* dfs(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (mmap[node]) {
            return mmap[node];
        }
        Node* nnode = new Node(node->val);
        mmap[node] = nnode;

        for (int i=0; i<node->neighbors.size(); i++) {
            Node* next = node->neighbors[i];
            if (!mmap[next]) {
                Node* newNext = dfs(next);
                nnode->neighbors.push_back(newNext);
            } else {
                nnode->neighbors.push_back(mmap[next]);
            }
        }

        return nnode;

    }
};
