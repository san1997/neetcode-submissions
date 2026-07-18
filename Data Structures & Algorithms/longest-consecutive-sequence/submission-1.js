class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        const map = new Map();

        for (let i=0; i<nums.length; i++) {
            map.set(nums[i], true);
        }

        const dp = new Map();
        var ans = 0;
        for (let k of map.keys()) {
            var i = k;
            while (map.has(i) && !dp.has(i)) {
                i++;
            }
            console.log(k, )
            var c = dp.has(i) ? dp.get(i) : 0;
            while (k <= i) {
                dp.set(i, c);
                ans = Math.max(ans, c);
                c++;
                i--;
            }
        }

        return ans;
    }
}
