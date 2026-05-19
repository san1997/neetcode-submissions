class Solution {
public:
    map<int, map<int, int>> dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        map<int, int > dp;

        dp[0] = 1;

        for (int i=0; i<nums.size(); i++) {
            map<int, int> nextdp;

            for (auto it = dp.begin(); it != dp.end(); it++) {
                int val = it->first;
                int count = it->second;

                nextdp[val + nums[i]] += count;
                nextdp[val - nums[i]] += count;
            }
                
            dp = nextdp;
        }

        return dp[target];
    }

};
