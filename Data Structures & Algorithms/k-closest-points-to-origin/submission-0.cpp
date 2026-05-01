class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> heap;

        for (int i=0; i<points.size(); i++) {
            double dis = sqrt(points[i][0]* points[i][0] + points[i][1]*points[i][1]);
            heap.push({dis, {points[i][0], points[i][1]}});
        }

        vector<vector<int>> ans;
        while (k > 0) {
            pair<double, pair<int, int>> top = heap.top();

            heap.pop();

            ans.push_back({ top.second.first, top.second.second});

            k--;
        }

        return ans;
    }
};
