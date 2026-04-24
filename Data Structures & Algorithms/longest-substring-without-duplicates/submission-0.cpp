class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mmap;
        int ans = 0;

        int l=0, r=0;

        while (r < s.size()) {

            while (r < s.size() && mmap[s[r]] == 0) {
                int sz = r-l+1;
                ans = max(ans, sz);

                mmap[s[r]]++;
                r++;
            }

            while (mmap[s[r]]) {
                mmap[s[l]]--;
                l++;
            }
            
        }

        return ans;
    }
};
