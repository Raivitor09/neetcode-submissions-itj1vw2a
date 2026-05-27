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
        if(intervals.size() == 1) return 1;

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < intervals.size(); i++) {
            if(!minHeap.empty() && minHeap.top() <= intervals[i].start) {
                minHeap.pop();
            }
            minHeap.push(intervals[i].end);
        }

        return minHeap.size();
    }
};
