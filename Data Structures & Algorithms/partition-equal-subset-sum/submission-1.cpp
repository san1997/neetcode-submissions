class Solution {
public:
    bool dp[5001][101];
    bool canPartition(vector<int>& nums) {
        dp[0][0] = true;
        int total = 0;
        for (int i=0; i<nums.size(); i++) {
            total += nums[i];
        }

        if (total % 2 ) {
            return false;
        }

        int target = total / 2;

        for (int s = 1; s <= target; s++) {
            for (int i=1; i<=nums.size(); i++) {
                dp[s][i] = dp[s][i-1];

                if (s - nums[i-1] >= 0) {
                    dp[s][i] |= dp[s - nums[i-1]][i-1];
                }
            }
        }

        return dp[target][nums.size()];
    }
};
