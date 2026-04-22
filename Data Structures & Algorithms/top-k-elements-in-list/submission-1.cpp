class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mmap;
        set<pair<int, int>> fmap;
        vector<int> ans;

        for (int i=0; i < nums.size(); i++) {
            mmap[nums[i]]++;
        }

        for (auto it = mmap.begin(); it != mmap.end(); it++) {
            fmap.insert({-1 * it->second, it->first});
        }

        auto it = fmap.begin();
        for ( int i=0; i< k; i++) {
            cout << it->first << " " << it->second << endl;
            ans.push_back(it->second);
            it++;
        }

        return ans;
    }
};
