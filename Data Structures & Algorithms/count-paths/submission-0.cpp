class Solution {
public:
    int dp[102][102];
    int uniquePaths(int m, int n) {
        dp[0][0] = 1;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n ;j++) {
                dp[i][j] = (j-1 >= 0 ? dp[i][j-1] : 0) + (i-1 >= 0 ? dp[i-1][j] : 0);
            
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
            }
        }

        return dp[m-1][n-1];
    }
};
