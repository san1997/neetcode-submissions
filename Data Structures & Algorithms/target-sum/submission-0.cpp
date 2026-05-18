class Solution {
public:
    map<int, map<int, int>> dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums, 0, target);
    }

    int func(vector<int>& nums, int ind, int target) {
        if (dp[target][ind]) {
            return dp[target][ind];
        }

        if (ind == nums.size()) {
            if (target == 0) {
                return dp[target][ind] = 1;
            } else {
                return dp[target][ind] = 0;
            }
        }

        dp[target][ind] = func(nums, ind+1, target + nums[ind]) + func(nums, ind+1, target - nums[ind]);

        return dp[target][ind];
    }
};
