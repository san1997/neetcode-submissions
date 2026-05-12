class Solution {
public:
    map<string, bool> vis;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        queue<string> q;
        q.push(beginWord);

        while (q.size()) {
            queue<string> tmp;

            while (q.size()) {
                string s = q.front();
                q.pop();
                vis[s] = true;

                for (int i=0; i<wordList.size(); i++) {
                    string ns = wordList[i];

                    if (s == endWord) {
                        return ans;
                    }

                    if (!vis[ns] && diff(s, ns) == 1) {
                        tmp.push(ns);
                    }
                }
            }
            q = tmp;
            ans++;
        } 
        

        return 0;
    }


    int diff(string a, string b) {
        int c = 0;
        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) {
                c++;
            }
        }
        return c;
    }
};
