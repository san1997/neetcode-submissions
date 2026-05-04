class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        recur({}, nums, 0, ans);

        return ans;
    }

    void recur(vector<int> curr, vector<int> nums, int mask, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return ;
        }

        for (int i=0; i<nums.size(); i++) {
            if (!(mask & (1 << i))) {
                curr.push_back(nums[i]);
                recur(curr, nums, mask | (1 << i), ans);
                curr.pop_back();
            }
        }
    }
};
