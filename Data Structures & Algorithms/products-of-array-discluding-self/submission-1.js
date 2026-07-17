class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        const prefix = Array(nums.length);
        const suffix = Array(nums.length);

        for (let i = 0; i<nums.length; i++) {
            if (i > 0) {
                prefix[i] = nums[i] * prefix[i-1];
            } else {
                prefix[i] = nums[i];
            }
        }

        for (let i = nums.length - 1; i >= 0; i--) {
            if (i < nums.length - 1) {
                suffix[i] = nums[i] * suffix[i+1];
            } else {
                suffix[i] = nums[i];
            }
        }

        const ans = [];

        for (let i=0; i<nums.length; i++) {
            const pre = i > 0 ? prefix[i-1] : 1;
            const suf = i < nums.length - 1 ? suffix[i+1] : 1;

            ans.push(pre*suf);
        }

        return ans;

    }
}
