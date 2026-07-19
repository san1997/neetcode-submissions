class Solution {
    /**
     * @param {string} s
     * @return {number}
     */
    lengthOfLongestSubstring(s) {
        let j=0, i=0;
        const map = new Map();
        let ans = 0;

        while (j < s.length) {
            if (!map.has(s[j])) {
                map.set(s[j], 0);
            }

            map.set(s[j], map.get(s[j]) + 1);

            while (map.get(s[j]) > 1) {
                map.set(s[i], map.get(s[i]) - 1);
                i++;
            }

            ans = Math.max(ans, j-i+1);
            j++;
        }

        return ans;
    }
}
