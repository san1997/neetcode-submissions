class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> mstack;
        vector<int> ans(n);

        for (int i=n-1; i>=0; i--) {
            while (!mstack.empty() && mstack.top().first <= temperatures[i]) {
                mstack.pop();
            }

            if (mstack.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = mstack.top().second - i;
            }

            mstack.push({temperatures[i], i});
        }

        return ans;
    }
};
