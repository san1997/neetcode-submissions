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
                dp[i][j] = dp[i-1][j];
                if (j >= coins[i-1]) {
                    dp[i][j] += dp[i][j - coins[i-1]];
                }
                
            }
            // cout << endl;
        }

        return dp[n][amount];
    }
};
