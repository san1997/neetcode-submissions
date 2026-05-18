class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[103][5005] = {0};
        int n = coins.size();

        for (int i=0; i<103;i++) {
            dp[i][0] = 1;
        }

        dp[0][0] = 1;

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=amount; j++) {
                for (int k=0; k*coins[i-1] <= j; k++ ) {
                    int val = j - k*coins[i-1];
                    // cout << i << " " << j << " " << val << endl;
                    dp[i][j] += dp[i-1][val];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        return dp[n][amount];
    }
};
