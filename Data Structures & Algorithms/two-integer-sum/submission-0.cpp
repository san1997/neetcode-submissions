class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mmap;
        vector<int> ans;

        for (int i=0; i < nums.size(); i++) {
            int x = target - nums[i];

            if (mmap[x]) {
                ans.push_back(mmap[x] - 1);
                ans.push_back(i);

                return ans;
            }

            mmap[nums[i]] = i+1;
        }

    }
};
