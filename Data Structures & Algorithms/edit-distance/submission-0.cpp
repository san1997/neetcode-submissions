class Solution {
public:
    int dp[102][103] = {0};
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        for (int i=m-1; i>=0; i--) {
            dp[i][n] = dp[i+1][n] + 1;
        }
        for (int i=n-1; i>=0; i--) {
            dp[m][i] = dp[m][i+1] + 1;
        }

        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j-- ) {
                int val = dp[i][j+1] + 1;
                val = min(val, dp[i+1][j] + 1);
                val = min(val, dp[i+1][j+1] + 1);

                if (word1[i] == word2[j]) {
                    val = min(val, dp[i+1][j+1]);
                }

                dp[i][j] = val;
            }
        }

        return dp[0][0];
        
    }
};
