class Solution {
public:
    bool isValid(string s) {
        stack<char> mstack;

        int i = 0;
        while (i<s.size()) {
            if (s[i] == ')') {
                if (mstack.empty()) return false;
                if (mstack.top() == '(') {
                    mstack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (mstack.empty()) return false;
                if (mstack.top() == '{') {
                    mstack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (mstack.empty()) return false;
                if (mstack.top() == '[') {
                    mstack.pop();
                } else {
                    return false;
                }
            } else {
                mstack.push(s[i]);
            }

            i++;
        }

        return mstack.empty();
    }
};
