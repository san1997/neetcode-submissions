/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mmap;
        int ans = 0;
        for (int i=0; i<intervals.size(); i++) {
            int s = intervals[i].start;
            int e = intervals[i].end;

            mmap[s]++;
            mmap[e]--;
        }

        int val = 0;
        for (auto it = mmap.begin(); it != mmap.end(); ++it) {
            val += it->second;

            ans = max(val, ans);
        }

        return ans;
    }
};
