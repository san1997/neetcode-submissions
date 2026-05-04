class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        string s = "";
        recur(s, n);
        return ans;
    }

    void recur(string s, int n) {
        int left = 0, right = 0;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else { 
                right++;
            }
        }

        if (left == n && right == n) {
            ans.push_back(s);
            return ;
        }

        if (left == n) {
            recur(s + ')', n);
            return ;
        }

        if (right == left) {
            recur(s + '(', n);
            return ;
        }

        recur(s + '(', n);
        if (left > right) {
            recur(s + ')', n);
        }
        
    }
};
