class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int last = 0;
        for (int i=0; i<nums.size(); i++) {
            if (last > 0) {
                last = last + nums[i];
            } else {
                last = nums[i];
            }

            ans = max(ans, last);
        }

        return ans;
    }
};
