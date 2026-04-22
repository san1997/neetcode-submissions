class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mmap;
        vector<vector<string>> ans;

        for (int i=0; i < strs.size(); i++) {
            string hash = strs[i];
            sort(hash.begin(), hash.end());

            mmap[hash].push_back(strs[i]);
        }

        for (auto it = mmap.begin(); it!= mmap.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};
