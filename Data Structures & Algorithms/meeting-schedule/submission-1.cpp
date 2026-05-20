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
        sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        if(intervals.size() == 1) return true;

        int start = intervals[0].start;
        int end = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start < end) return false;
            else end = intervals[i].end;
        }

        return true;
    }
};
