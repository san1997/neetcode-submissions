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

    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            if (a.start < b.start) {
                return true;
            } else if (a.start == b.start && a.end < b.end) {
                return true;
            }

            return false;
        });

        for (int i=0; i<intervals.size(); i++) {
            cout << intervals[i].start << " " << intervals[i].end << endl;
        }

        bool hasOverlap = false;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                hasOverlap = true;
            }
        }

        return !hasOverlap;
    }
};
