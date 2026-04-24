class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        map<int, int> amap;
        for (int i=0; i<nums.size(); i++) {
            if (!amap[nums[i]]) {
                int target = -1 * nums[i];
                int l=i+1, r=nums.size()-1;

                while (l < r) {
                    int left = nums[l];
                    int right = nums[r];
                    int cursum = nums[l] + nums[r];
                    if (cursum > target) {
                        r--;
                    } else if (cursum < target) {
                        l++;
                    } else {
                        ans.push_back({nums[i], nums[l], nums[r]});

                        while(left == nums[l]) {
                            l++;
                        }

                        while (right == nums[r]) {
                            r--;
                        }
                    }
                }
            }

            amap[nums[i]]++;
        }

        return ans;
    }
};
