class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        rec(nums, 0, {}, target, ans);

        return ans;
    }

    void rec(vector<int>& nums, int ind, vector<int> prev, int target, vector<vector<int>>& ans) {
        cout << ind << " " << target << endl;
        if (target == 0 && ind == nums.size()) {
            ans.push_back(prev);
        }

        if (ind == nums.size()) {
            return ;
        }

        if (target < 0) {
            return ;
        }

        rec(nums, ind+1, prev, target, ans);

        prev.push_back(nums[ind]);
        rec(nums, ind, prev, target-nums[ind], ans);
    }
};
