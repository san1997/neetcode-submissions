class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        vector<int> last = {intervals[0][0], intervals[0][1]};
        for (int i=1; i<intervals.size(); i++) {
            int a = last[0];
            int b = last[1];

            if (intervals[i][1] < b) {
                count++;
                last = {intervals[i][0], intervals[i][1]};
            } else if (intervals[i][0] < b) {
                count++;
            } else {
                last = {intervals[i][0], intervals[i][1]};
            }
        }
        
        return count;
    }
};
