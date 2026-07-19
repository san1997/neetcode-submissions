class Solution {
    /**
     * @param {string} s1
     * @param {string} s2
     * @return {boolean}
     */
    equalMaps(m1, m2) {
        // console.log(m1, m2);
        for (let [k1, v1] of m1) {
            if (m1.get(k1) != m2.get(k1)) {
                return false;
            }
        }

        return true;
    }

    checkInclusion(s1, s2) {
        const map1 = new Map();
        const map2 = new Map();

        if (s2.length < s1.length) return false;

        for (let c of s1) {
            if (!map1.has(c)) {
                map1.set(c, 0);
            }
            map1.set(c, map1.get(c) + 1);
        }

        let sz = s1.length;
        for (let i=0; i<sz; i++) {
            if (!map2.has(s2[i])) {
                map2.set(s2[i], 0);
            }
            map2.set(s2[i], map2.get(s2[i]) + 1);
        }

        if (this.equalMaps(map1, map2)) return true;

        for (let i=0; i<s2.length - sz; i++) {
            map2.set(s2[i], map2.get(s2[i]) - 1);
            if (!map2.has(s2[i+sz])) {
                map2.set(s2[i+sz], 0);
            }
            map2.set(s2[i+sz], map2.get(s2[i+sz]) + 1);

            if (this.equalMaps(map1, map2)) return true;
        }

        return false;
    }
}
