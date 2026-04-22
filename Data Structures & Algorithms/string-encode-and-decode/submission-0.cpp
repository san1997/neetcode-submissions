class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (int i=0;i < strs.size(); i++) {
            ans += (string)to_string(strs[i].size()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        for (int i=0;i<s.size();) {
            string news = "";
            string prefix = "";
            while(s[i] != '#' ) {
                prefix += s[i];
                i++;
            }

            int num = stoi(prefix);
            i++;
            for (int j=0;j<num; j++) {
                news +=  s[i];
                i++;
            }

            ans.push_back(news);
        }

        return ans;
    }
};
