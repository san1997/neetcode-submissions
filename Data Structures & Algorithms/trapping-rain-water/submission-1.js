class Solution {
    /**
     * @param {number[]} height
     * @return {number}
     */
    trap(height) {
        let ans = 0;

        const stack = [];

        for (let i=height.length - 1; i>= 0; i--) {
            if (stack.length == 0 || stack.at(-1).height <= height[i]) {
                stack.push({height: height[i], index: i});
            }
        }

        let maxm = -1;

        for (let i=0; i<height.length; i++) {
            if (stack.length && stack.at(-1).index == i) {
                stack.pop();
            }

            if (stack.length ) {

                let h1 = stack.at(-1).height;
                let h2 = maxm;

                let minm = Math.min(h1, h2);
                const currVol =  minm > height[i] ? minm - height[i] : 0;

                console.log({i, currVol});
                ans += currVol;
            }

            maxm = Math.max(maxm, height[i]);
        }

        return ans;
    }
}
