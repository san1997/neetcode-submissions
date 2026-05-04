class Node {
    public: 
    Node* children[26];
    bool end;

    Node() {
        for (int i=0; i<26; i++) {
            children[i] = nullptr;
        }
        end = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;

        for (int i=0; i<word.size(); i++) {
            int c = (int)(word[i] - 'a');
            if (!curr->children[c]) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        return dfsSearch(root, word, 0);
    }

    bool dfsSearch(Node* node, string& word, int ind) {
        if (!node) {
            return false;
        }

        if (ind == word.size()) {
            return node->end;
        }

        if (word[ind] == '.') {
            bool found = false;
            for (int i=0; i<26; i++) {
                found |= dfsSearch(node->children[i], word, ind+1);
            }
            
            return found;
        } else {
            int c = (int)(word[ind] - 'a');
            return dfsSearch(node->children[c], word, ind+1);
        }
    }
};
