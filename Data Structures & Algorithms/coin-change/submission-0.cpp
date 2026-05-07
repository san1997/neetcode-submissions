class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0] = 0;
        for (int i=1; i<= amount; i++) {
            dp[i] = -1;
            int minm = INT_MAX;
            for (int j=0; j<coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    minm = min(dp[i - coins[j]] + 1, minm);
                }
            }

            if (minm != INT_MAX) {
                dp[i] = minm;
            }
        }

        return dp[amount];
    }
};
