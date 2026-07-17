class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const map = new Map();

        for (const str of strs) {
            const sortedstr = str.split("").sort().join('');

            if (!map.has(sortedstr)) {
                map.set(sortedstr, []);
            }

            map.get(sortedstr).push(str);
        }

        const ans = [];

        for (const vals of map.values()) {
            ans.push(vals);
        }   

        return ans;
    }
}
