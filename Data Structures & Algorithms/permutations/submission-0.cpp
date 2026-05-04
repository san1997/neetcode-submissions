class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        recur({}, nums, ans);

        return ans;
    }

    void recur(vector<int> curr, vector<int> vec, vector<vector<int>>& ans) {
        if (!vec.size()) {
            ans.push_back(curr);
            return ;
        }

        for (int i=0; i<vec.size(); i++) {
            curr.push_back(vec[i]);
            vector<int> vec2 = vec;
            auto it = find(vec2.begin(), vec2.end(), vec2[i]);
            vec2.erase(it);

            recur(curr, vec2, ans);

            curr.pop_back();
        }
    }
};
