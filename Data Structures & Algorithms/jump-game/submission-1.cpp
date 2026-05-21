class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);

        vis[0] = true;

        dfs(0, nums, vis);

        return vis[n-1];
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
