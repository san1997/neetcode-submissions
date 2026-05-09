class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1);

        dp[n] = true;

        for (int i=n-1; i>=0 ;i--) {
            dp[i] = false;
            for (int j=0; j<wordDict.size(); j++) {
                int len = wordDict[j].size();

                if (i + len <= n) {
                    if (s.substr(i, len) == wordDict[j] && dp[i+len]) {
                        dp[i] = true;
                    }
                }
            }
        }

        return dp[0];
    }
};
