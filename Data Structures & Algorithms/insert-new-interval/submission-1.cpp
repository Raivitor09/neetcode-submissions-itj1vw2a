class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // ADD BEFORE
            if(end < newInterval[0]) {
                res.push_back(intervals[i]);
            } 
            // ADD AFTER
            else if(start > newInterval[1]) {
                res.push_back(intervals[i]);
            }
            // OVERLAP
            else {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }
        }

        res.push_back(newInterval);
        sort(res.begin(), res.end());
        return res;
    }
};
