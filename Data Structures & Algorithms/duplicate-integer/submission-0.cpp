class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> mmap;

        for (int i=0; i< nums.size(); i++) {
            if (mmap[nums[i]]) {
                return true;
            }

            mmap[nums[i]]++;
        }

        return false;
    }
};