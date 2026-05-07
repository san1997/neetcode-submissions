class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());

        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            dp[i] = max((i-1>= 0 ? dp[i-1] : 0), nums[i] + (i-2 >= 0 ? dp[i-2]: 0));
        }

        return dp[nums.size() - 1];
    }
};
