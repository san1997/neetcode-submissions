class Solution {
public:
    bool dp[1003][1003] = {false};

    int countSubstrings(string s) {
        int n = s.size();

        for (int i=0; i<s.size(); i++) {
            dp[i][i] = true;

            if (i+1 < n) {
                dp[i][i+1] = (s[i] == s[i+1]);
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i=0; i<n ;i++) {
                int j = i + diff;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
