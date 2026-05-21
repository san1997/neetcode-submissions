class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i <= maxreach) {
                maxreach = max(maxreach, i + nums[i]);
            }
        }

        return maxreach >= nums.size() - 1;
    }

    void dfs(int n, vector<int>& nums, vector<bool>& vis) {
        int jump = nums[n];
        vis[n] = true;
        for (int i=n+1; i<=n+jump && i<nums.size(); i++) {
            if (!vis[i]) {
                dfs(i, nums, vis);
            }
        }

    }
};
