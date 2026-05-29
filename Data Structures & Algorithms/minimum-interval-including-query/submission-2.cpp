#define pii pair<int, int> 

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    
        sort(intervals.begin(), intervals.end());
        vector<int> newq = queries;
        sort(newq.begin(), newq.end());

        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        int j = 0;
        map<int, int> ansmap;
        vector<int> ans;
        for (int i=0; i<newq.size(); i++) {
            int q = newq[i];
            while (j < intervals.size() && intervals[j][0] <= q) {
                int s = intervals[j][0];
                int e = intervals[j][1];
                minheap.push({e - s +1, e});
                j++;
            }

            while (minheap.size() && minheap.top().second < q) {
                minheap.pop();
            }

            if (minheap.size()) {
                ansmap[q] = minheap.top().first;
            } else {
                ansmap[q] = -1;
            }
        }

        for (int i=0; i<queries.size(); i++) {
            ans.push_back(ansmap[queries[i]]);
        }

        return ans;
    }
};
