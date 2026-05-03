class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        allsubsets(nums, 0, {}, ans);

        return ans;
    }

    void allsubsets(vector<int>& nums, int ind, vector<int> prev, vector<vector<int>>& ans ) {
        if (ind == nums.size()) {
            ans.push_back(prev);
            return ;
        }

        allsubsets(nums, ind+1, prev, ans);

        prev.push_back(nums[ind]);
        allsubsets(nums, ind+1, prev, ans);
    }
};
