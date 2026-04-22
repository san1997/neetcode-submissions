class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (int i=0; i<strs.size(); i++) {
            ans += to_string(strs[i].size()) + ',';
        }

        ans += '#';

        for (int i=0; i<strs.size(); i++) {
            ans += strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<int> sizes;

        int i=0;

        while (s[i] != '#') {
            string num = "";
            while(s[i] != ',') {
                num += s[i];
                i++;
            }

            sizes.push_back(stoi(num));
            i++;
        }

        i++;
        vector<string> ans;

        for (int j=0; j<sizes.size(); j++) {
            int sz = sizes[j];

            string ns = s.substr(i, sz);
            ans.push_back(ns);

            i = i+sz;
        }

        return ans;
    }
};
