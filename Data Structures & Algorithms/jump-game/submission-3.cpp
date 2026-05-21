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
};
