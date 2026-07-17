
// Binary min-heap ordered by a comparator(a, b) -> negative if a is "smaller"
// (higher priority). push/pop are O(log n).
class MaxHeap {
    constructor(compare) {
        this.compare = compare;
        this.data = [];
    }
    get size() { return this.data.length; }
    isEmpty() { return this.data.length === 0; }

    push(item) {
        const d = this.data;
        d.push(item);
        let i = d.length - 1;
        while (i > 0) {
            const parent = (i - 1) >> 1;
            if (this.compare(d[i], d[parent]) >= 0) break;
            [d[i], d[parent]] = [d[parent], d[i]];
            i = parent;
        }
    }

    pop() {
        const d = this.data;
        const top = d[0];
        const last = d.pop();
        if (d.length > 0) {
            d[0] = last;
            let i = 0;
            const n = d.length;
            while (true) {
                const l = 2 * i + 1, r = 2 * i + 2;
                let smallest = i;
                if (l < n && this.compare(d[l], d[smallest]) < 0) smallest = l;
                if (r < n && this.compare(d[r], d[smallest]) < 0) smallest = r;
                if (smallest === i) break;
                [d[i], d[smallest]] = [d[smallest], d[i]];
                i = smallest;
            }
        }
        return top;
    }
}



class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const heap = new MaxHeap((a,b) => b.value-a.value);
        const map = new Map();


        for (const num of nums) {
            if (!map.has(num)) {
                map.set(num, 0);
            }
            map.set(num, map.get(num) + 1);
        }

        for (const [k,v] of map) {
            heap.push({ key: k, value: v});
        }

        const ans = [];

        while (k > 0) {
            const top = heap.pop();
            ans.push(top.key);
            k--;
        }

        return ans;

    }

}
