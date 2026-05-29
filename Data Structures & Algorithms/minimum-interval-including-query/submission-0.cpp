class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> count(10003, INT_MAX);

        for (int i=0; i<intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            for (int j=s; j <= e; j++) {
                count[j] = min(e-s+1, count[j]);
            }
        }

        vector<int> ans;
        for (int i=0; i<queries.size(); i++) {
            if (count[queries[i]] == INT_MAX) {
                ans.push_back(-1);
            } else {
                ans.push_back(count[queries[i]]);
            }
        }

        return ans;
    }
};
