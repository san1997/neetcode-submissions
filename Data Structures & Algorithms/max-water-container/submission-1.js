class Solution {
    /**
     * @param {number[]} heights
     * @return {number}
     */
    maxArea(heights) {
        let l=0, r=heights.length - 1;
        let maxm = 0;

        while (l < r) {
            const area = (r-l) * Math.min(heights[l], heights[r]);

            maxm = Math.max(area, maxm);

            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return maxm;
    }
}
