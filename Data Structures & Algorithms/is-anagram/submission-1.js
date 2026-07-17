class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {

        if (s.length != t.length) return false;

        const mapa = new Map();
        const mapb = new Map();

        for (let i=0; i<s.length; i++) {
            if (!mapa.has(s[i])) {
                mapa.set(s[i], 0);
            }

            mapa.set(s[i], mapa.get(s[i]) + 1);
        }

        for (let i=0; i<t.length; i++) {
            if (!mapb.has(t[i])) {
                mapb.set(t[i], 0);
            }

            mapb.set(t[i], mapb.get(t[i]) + 1);
        }

        for (const k of mapa.keys()) {
            console.log(k, mapa.get(k), mapb.get(k));
            if (mapa.get(k) != mapb.get(k)) {
                return false;
            }
        }

        return true;
    }
}
