class Solution {
public:
    int dp[1004][1004] = {0};
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        dp[m][n] = 1;
        for (int i=0; i<m; i++) {
            dp[i][n] = 1;
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                dp[i][j] = dp[i+1][j];

                if (s[i] == t[j]) {
                    dp[i][j] += dp[i+1][j+1];
                }
            }
        }

        for (int i=0;i<m;i++) {
            for (int j=0; j<n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[0][0];

    }
};
