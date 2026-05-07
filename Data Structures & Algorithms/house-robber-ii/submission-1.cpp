class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }
        
        int l =0,ll = 0;

        for (int i=0; i<nums.size() -1; i++) {
            int now = max(l, ll + nums[i]);
            ll = l;
            l = now;
        }
        int ans1 = l;

        ll = 0; l=0;
        for (int i=1; i<nums.size(); i++) {
            int now = max(l, ll + nums[i]);
            ll = l;
            l = now;
        }
        int ans2 = l;

        return max(ans1, ans2);
    }
};
