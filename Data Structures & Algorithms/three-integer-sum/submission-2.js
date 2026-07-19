class Solution {
    /**
     * @param {number[]} nums
     * @return {number[][]}
     */
    threeSum(nums) {
        const ans = [];

        nums.sort((a,b) => a-b);

        for (let i=0; i<nums.length;) {
            let num1 = nums[i];

            let l =i+1, r = nums.length - 1 ;

            while (l < r) {
                let num2 = nums[l];
                let num3 = nums[r];
                let sum = num1 + num2 + num3;

                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ans.push([num1, num2, num3]);
                    while (nums[l] == num2)l++;
                }
            }

            while(nums[i] == num1)i++;
        }

        return ans;
    }
}
