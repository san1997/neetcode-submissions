class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int fre1[26] = {0};
        int fre2[26] = {0};

        for (int i=0; i< n; i++) {
            int c = (int)(s1[i]-'a');
            fre1[c]++;
        }

        for (int i=0;i<n;i++) {
            int c = (int)(s2[i]-'a');
            fre2[c]++;
        }

        if (isSame(fre1, fre2)) {
            return true;
        }

        for (int i=1; i+n-1 < s2.size(); i++) {
            int cl = (int) s2[i-1] - 'a';
            int cr = (int) s2[i+n-1] -'a';
            fre2[cl]--;
            fre2[cr]++;

            if (isSame(fre1, fre2)) {
                return true;
            }
        }

        return false;
    }

    bool isSame(int arr1[], int arr2[]) {
        for (int i=0;i<26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }

        return true;
    }
};
