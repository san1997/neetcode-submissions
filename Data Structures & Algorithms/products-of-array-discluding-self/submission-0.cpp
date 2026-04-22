class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans;

        pre[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            pre[i] = pre[i-1] * nums[i];
        }

        suf[n-1] = nums[n-1];
        for (int i=n-2; i>=0 ; i--) {
            suf[i] = suf[i+1] * nums[i];
        }

        for (int i=0;i<n;i++) {
            int val = 1;
            if (i-1 >= 0) {
                val *= pre[i-1];
            }

            if (i+1 < n) {
                val *= suf[i+1];
            }

            ans.push_back(val);
        }

        return ans;
    }
};
