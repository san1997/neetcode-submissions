class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // insert
        bool inserted = false;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            intervals.push_back(newInterval);
        }

        // remove overlap
        for (int i=0; i<intervals.size() - 1; i++) {
            vector<int>& now = intervals[i];
            vector<int>& next = intervals[i+1];

            if (now[1] >= next[1]) {
                next[0] = now[0];
                next[1] = now[1];
                intervals.erase(intervals.begin() + i);
                i--;
            } else if (next[0] <= now[1]) {
                next[0] = now[0];
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }

        return intervals;
    }
};
