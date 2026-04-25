class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tmap,smap;
        int matches = 0;

        for (int i=0; i<t.size(); i++) {
            tmap[t[i]]++;
        }
        int needs = tmap.size();

        int l=0, r=0;
        int ansl = -1, ansr = s.size();

        while ( r < s.size()) {
            cout << l << " " << r << " " << matches << endl;
            smap[s[r]]++;

            if (tmap[s[r]]){
                if (smap[s[r]] == tmap[s[r]]) {
                    matches++;
                }
            }

            while (matches == needs) {
                cout << "matches : " << l << " " << r << endl;
                if (r-l < ansr - ansl) {
                    ansr = r;
                    ansl = l;
                }

                smap[s[l]]--;
                if (tmap[s[l]]) {
                    if (smap[s[l]] == tmap[s[l]] - 1) {
                        matches--;
                    }
                }
                l++;
            }

            r++;
        }

        if (ansr - ansl < s.size()) {
            return s.substr(ansl, ansr-ansl+1);
        } else {
            return "";
        }
    }
};
