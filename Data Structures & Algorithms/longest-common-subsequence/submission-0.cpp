class Solution {
public:
    int dp[1003][1003];
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        for (int i=0; i<m; i++) {
            dp[i][0] = 0;
        }
        for (int i=0; i<n; i++) {
            dp[0][i] = 0;
        }

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1] + (text1[i-1] == text2[j-1] ? 1 : 0);

                dp[i][j] = max(a, max(b,c));
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[m][n];
    }
};
