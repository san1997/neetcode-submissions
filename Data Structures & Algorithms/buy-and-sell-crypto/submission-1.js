class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {

        let ans = 0;
        let minm = Number.MAX_VALUE;

        for (let price of prices) {
            if (price > minm) {
                ans = Math.max(ans, price - minm);
            }

            minm = Math.min(price, minm);
        }

        return ans;

    }
}
