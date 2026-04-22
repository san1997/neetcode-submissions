class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int smap[26] = {0}, tmap[26] = {0};

        for (int i=0;i<s.size(); i++) {
            int sval = ( s[i] - 'a');
            int tval = ( t[i] - 'a');

            smap[sval]++;
            tmap[tval]++;
        }

        for (int i=0;i<26;i++) {
            if (smap[i] != tmap[i]) {
                return false;
            }
        }

        return true;
    }
};
