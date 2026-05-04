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

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
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
        Node* curr = root;
        int i = 0;
        while (curr && i < word.size()) {
            int c = (int)(word[i] - 'a');
            curr = curr->children[c];
            i++;
        }
        cout << endl;

        if (curr && curr->end && i == word.size()) {
            return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        int i = 0;
        while (curr && i < prefix.size()) {
            int c = (int)(prefix[i] - 'a');
            curr = curr->children[c];
            i++;
        }

        if (curr && i == prefix.size()) {
            return true;
        }

        return false;
    }
};
