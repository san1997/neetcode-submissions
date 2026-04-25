class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mstack;

        for (int i=0; i<tokens.size(); i++) {
            if (tokens[i] == "+") {
                int val1 = mstack.top();
                mstack.pop();

                int val2 = mstack.top();
                mstack.pop();

                int val = val1 + val2;
                mstack.push(val);
            } else if (tokens[i] == "-"){
                int val1 = mstack.top();
                mstack.pop();

                int val2 = mstack.top();
                mstack.pop();

                int val = val2 - val1;
                mstack.push(val);
            } else if (tokens[i] == "*"){
                int val1 = mstack.top();
                mstack.pop();

                int val2 = mstack.top();
                mstack.pop();

                int val = val2 * val1;
                mstack.push(val);
            } else if (tokens[i] == "/"){
                int val1 = mstack.top();
                mstack.pop();

                int val2 = mstack.top();
                mstack.pop();

                int val = val2 / val1;
                mstack.push(val);
            } else {
                int val = stoi(tokens[i]);
                mstack.push(val);
            }
        }

        return mstack.top();
    }
};
