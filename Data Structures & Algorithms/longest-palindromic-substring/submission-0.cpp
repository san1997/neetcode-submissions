class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1002][1002] = {false};

        int n = s.size(); 

        for (int i=0; i<n ;i++) {
            dp[i][i] = true;

            if (i < n-1) {
                dp[i][i+1] = (s[i] == s[i+1]);
            }
        }

        for (int diff = 2; diff< n; diff++) {
            for (int i=0; i + diff < n; i++) {
                int j = i+diff;
                if (s[i] == s[j]) {
                    dp[i][j] = (dp[i+1][j-1] ? true : false);
                } else {
                    dp[i][j] = false;
                }
            }
        }

        int ans = 0;
        string news;
        for (int i=0;i<n;i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j]) {
                    if (j-i+1 > ans) {
                        ans = j-i+1;
                        news = s.substr(i, j-i+1);
                    }
                }
            }
        }

        return news;
    }
};
