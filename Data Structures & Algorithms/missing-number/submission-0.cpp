class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all = nums.size();

        for (int i=0; i<nums.size(); i++) {
            all ^= nums[i];
            all ^= i;
        }

        return all;
    }
};
